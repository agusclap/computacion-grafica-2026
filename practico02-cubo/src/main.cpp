// ----------------------------------------------------------------------------
// main.cpp  -  Practico 02, Parte 4: el programa que usa los modulos.
//
// Las mismas cuatro etapas del triangulo, pero ahora las tres primeras las
// resuelven los modulos:
//
//   1. decidir los datos        ->  primitives::cube()        (24 y 36)
//   2. pasarlos a la GPU        ->  Mesh::load()
//   3. armar el programa        ->  ResourceManager + Shader
//   4. dar la orden             ->  glDrawElements()
//
// CONDICION DEL PRACTICO: este archivo NO tiene ninguna llamada glDelete*.
// Los dueños de los recursos de OpenGL son Mesh y Shader, y liberan en su
// destructor. Las unicas llamadas a OpenGL que quedan aca son las minimas
// necesarias antes del loop y dentro del loop para dibujar.
// ----------------------------------------------------------------------------

#include <cstdlib>          // EXIT_FAILURE, EXIT_SUCCESS
#include <iostream>
#include <stdexcept>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "mesh/Mesh.h"
#include "mesh/Primitives.h"
#include "resources/ResourceManager.h"
#include "shader/Shader.h"

static const char* kWindowTitle     = "Practico 02 - cubo indexado";
static constexpr int kWindowWidth   = 800;
static constexpr int kWindowHeight  = 600;
static constexpr int kGLVerMajor    = 4;
static constexpr int kGLVerMinor    = 6;

// El programa se ejecuta desde la raiz del proyecto (ver 'make run').
static const char* kAssetsRoot = "./assets";

static int glfw_error_code{};
static std::string glfw_error_str{};

static void error_callback(int error, const char *description);
static void framebuffer_size_callback(GLFWwindow* window,
                                      int width, int height);
static void processInput(GLFWwindow *window);
static void print_gl_version(void);


int main()
{
	// Set error callback before initialization so we can be notified
	glfwSetErrorCallback(error_callback);

	// Init GLFW
	if (!glfwInit()) {
		const std::string error_msg = "GLFW initialization failed!";
		const std::string glfw_error_msg = std::to_string(glfw_error_code) +
		                                   "): " + glfw_error_str;
		std::cout << error_msg + " - GLFW(" + glfw_error_msg << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, kGLVerMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, kGLVerMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(kWindowWidth,
					      kWindowHeight,
					      kWindowTitle, nullptr, nullptr);

	if (window == nullptr){
		glfwTerminate();
		const std::string error_msg = "GLFW window creation failed!";
		const std::string glfw_error_msg = std::to_string(glfw_error_code) +
		                                   "): " + glfw_error_str;
		std::cout << error_msg + " - GLFW(" + glfw_error_msg << std::endl;
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Load GLAD pointers in the current GLFW context
	if (!gladLoadGL(glfwGetProcAddress)) {
		glfwDestroyWindow(window);
		glfwTerminate();
		std::cout << "GLAD initialization failed!" << std::endl;
		return EXIT_FAILURE;
	}

	print_gl_version();

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSwapInterval(1);

	// CAJA NEGRA, vence el 09-oct (Unidad VIII). Sin el test de profundidad
	// las caras se pisan en el orden en que se dibujan.
	glEnable(GL_DEPTH_TEST);

	int exit_code = EXIT_SUCCESS;

	// ---------------------------------------------------------------------
	// BLOQUE de vida de los objetos que POSEEN recursos de OpenGL.
	// Tienen que morir con el contexto todavia vivo, o sea antes de
	// glfwTerminate(). Si vivieran hasta el final de main, sus destructores
	// correrian sin contexto: a veces no pasa nada y a veces es un segfault
	// al cerrar, de los que aparecen "a veces".
	{
		try {
			// --- 1. Decidir los datos --------------------------------
			const MeshData datos = primitives::cube();

			std::cout << "Malla del cubo: "
			          << datos.vertices.size() << " vertices, "
			          << datos.indices.size()  << " indices"
			          << std::endl;

			// --- 2. Pasarlos a la GPU --------------------------------
			Mesh cubo;
			cubo.load(datos);

			// --- 3. Armar el programa de shaders ---------------------
			// El ResourceManager lee del disco; el Shader compila.
			// Ninguno hace el trabajo del otro.
			ResourceManager recursos(kAssetsRoot);
			const ShaderSource& fuente =
				recursos.load_shader_source("solid",
				                            "shaders/solid.vs",
				                            "shaders/solid.fs");

			Shader shader;
			if (!shader.compile_from_source(fuente.vs, fuente.fs)) {
				// El Shader ya imprimio el log del driver.
				std::cout << "No se pudo armar el programa de "
				             "shaders; se cierra." << std::endl;
				exit_code = EXIT_FAILURE;
			}
			else {
				// --- 4. Dar la orden -----------------------------
				while (!glfwWindowShouldClose(window)) {
					processInput(window);

					glClearColor(51.0f/256, 55.0f/256, 76.0f/256, 1.0f);
					// DOS bits: color y profundidad.
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

					shader.use();
					glBindVertexArray(cubo.vao());
					// El 2do argumento es la cantidad de INDICES.
					// El nullptr no es un puntero a memoria de la
					// aplicacion: es un offset dentro del EBO.
					glDrawElements(GL_TRIANGLES, cubo.count(),
					               GL_UNSIGNED_INT, nullptr);

					glfwSwapBuffers(window);
					glfwPollEvents();
				}
			}
		}
		catch (const std::exception& e) {
			// El ResourceManager avisa por excepcion (Practico 01).
			std::cout << e.what() << std::endl;
			exit_code = EXIT_FAILURE;
		}
	}
	// <- aca corren ~Mesh y ~Shader, con el contexto todavia activo.

	glfwDestroyWindow(window);
	glfwTerminate();

	return exit_code;
}


void error_callback(int error, const char *description){
    glfw_error_code = error;
    glfw_error_str = std::string(description);
}

void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window,
                               int width, int height){
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
}

void print_gl_version(void){
    std::cout << " OpenGL Vendor: "   << glGetString(GL_VENDOR)   << std::endl;
    std::cout << " OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << " OpenGL Version: "  << glGetString(GL_VERSION)  << std::endl;
    std::cout << " GLSL Version: "
              << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}
