// ----------------------------------------------------------------------------
// main.cpp  -  Practico 03, Parte 4: una escena con varias piezas.
//
// Se dibujan tres primitivas en la misma escena, cada una en un lugar
// distinto, con un tamaño distinto y un color distinto.
//
// LAS MALLAS SE GENERAN UNA SOLA VEZ, fuera del bucle de dibujo. Lo unico que
// cambia entre una pieza y otra -- y dentro del bucle -- son los UNIFORM.
//
// Uso:
//     ogl-app [gajos] [normales]
//
//   gajos     cantidad de gajos de las primitivas de revolucion (def. 24).
//             Cambiarlo y volver a correr regenera la malla sola, sin tocar
//             una sola coordenada.
//   normales  usa el fragment shader de depuracion, que pinta cada vertice
//             con el valor de su normal como color.
//
// Este archivo sigue sin tener ninguna llamada glDelete*: los dueños de los
// recursos de OpenGL son Mesh y Shader.
// ----------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "mesh/Mesh.h"
#include "mesh/Primitives.h"
#include "resources/ResourceManager.h"
#include "shader/Shader.h"

static const char* kWindowTitle     = "Practico 03 - primitivas y matriz de modelo";
static constexpr int kWindowWidth   = 800;
static constexpr int kWindowHeight  = 600;
static constexpr int kGLVerMajor    = 4;
static constexpr int kGLVerMinor    = 6;

static const char* kAssetsRoot = "./assets";

static int glfw_error_code{};
static std::string glfw_error_str{};

static void error_callback(int error, const char *description);
static void framebuffer_size_callback(GLFWwindow* window, int w, int h);
static void processInput(GLFWwindow *window);
static void print_gl_version(void);

namespace {

// Lo minimo que hace falta para dibujar una pieza. La malla se referencia, no
// se copia: varias piezas podrian compartir la misma.
struct Pieza {
    const Mesh* malla;
    glm::mat4   model;
    glm::vec3   color;
};

// Informe por consola de lo que genero cada primitiva, y verificacion del
// orden de los indices SIN DIBUJAR NADA.
void informar(const char* nombre, const MeshData& m, int lateral_esperado = -1)
{
    std::cout << "  " << nombre << ": "
              << m.vertices.size() << " vertices, "
              << m.indices.size()  << " indices";
    if (lateral_esperado >= 0) {
        std::cout << "  [lateral: " << lateral_esperado << " vertices]";
    }
    const unsigned malos = primitives::winding_invertidos(m);
    std::cout << "  -> winding: "
              << (malos == 0U ? "OK, ningun triangulo invertido"
                              : std::to_string(malos) + " INVERTIDOS")
              << std::endl;
}

}  // namespace


int main(int argc, char** argv)
{
	// --- Parametros de linea de comandos ---------------------------------
	unsigned gajos = 24U;
	bool     modo_normales = false;
	for (int i = 1; i < argc; ++i) {
		const std::string arg = argv[i];
		if (arg == "normales") { modo_normales = true; }
		else {
			try { gajos = static_cast<unsigned>(std::stoul(arg)); }
			catch (const std::exception&) { /* se ignora */ }
		}
	}

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		std::cout << "GLFW initialization failed! - GLFW("
		          << glfw_error_code << "): " << glfw_error_str << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, kGLVerMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, kGLVerMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(kWindowWidth, kWindowHeight,
	                                      kWindowTitle, nullptr, nullptr);
	if (window == nullptr){
		glfwTerminate();
		std::cout << "GLFW window creation failed! - GLFW("
		          << glfw_error_code << "): " << glfw_error_str << std::endl;
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGL(glfwGetProcAddress)) {
		glfwDestroyWindow(window);
		glfwTerminate();
		std::cout << "GLAD initialization failed!" << std::endl;
		return EXIT_FAILURE;
	}

	print_gl_version();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSwapInterval(1);

	// Se mantiene habilitado como en el Practico 02 (Unidad VIII).
	glEnable(GL_DEPTH_TEST);

	int exit_code = EXIT_SUCCESS;

	// Bloque de vida de los objetos que POSEEN recursos de OpenGL: tienen que
	// morir con el contexto todavia vivo.
	{
		try {
			// --- 1. Decidir los datos: UNA SOLA VEZ ------------------
			std::cout << "Mallas generadas (gajos = " << gajos << "):"
			          << std::endl;

			const MeshData datos_cubo = primitives::cube();
			informar("cubo    ", datos_cubo);

			const MeshData datos_cil = primitives::cylinder(0.24f, 0.78f, gajos);
			// El lateral son (anillos+1) filas de (gajos+1) vertices; con
			// anillos = 1 son DOS anillos: 2*(N+1), que es la cuenta que
			// pide verificar la guia.
			informar("cilindro", datos_cil,
			         static_cast<int>(2U * (gajos + 1U)));

			const float conicidad = glm::radians(50.0f);   // RADIANES
			const MeshData datos_cono =
			        primitives::cone(0.30f, conicidad, gajos);
			informar("cono    ", datos_cono);
			std::cout << "  (altura del cono = "
			          << primitives::cone_height(0.30f, conicidad)
			          << ")" << std::endl;

			// --- 2. Pasarlos a la GPU: tambien una sola vez ----------
			Mesh malla_cubo, malla_cil, malla_cono;
			malla_cubo.load(datos_cubo);
			malla_cil.load(datos_cil);
			malla_cono.load(datos_cono);

			// --- 3. Armar el programa de shaders ---------------------
			ResourceManager recursos(kAssetsRoot);
			const char* fs_file = modo_normales ? "shaders/normales.fs"
			                                    : "shaders/solid.fs";
			const ShaderSource& fuente =
			        recursos.load_shader_source("solid",
			                                    "shaders/solid.vs", fs_file);

			Shader shader;
			if (!shader.compile_from_source(fuente.vs, fuente.fs)) {
				std::cout << "No se pudo armar el programa de shaders."
				          << std::endl;
				exit_code = EXIT_FAILURE;
			}
			else {
				// --- La caja negra: ajuste de vista y proyeccion --
				// Corrige la relacion de aspecto de la ventana y niega
				// el eje Z. Las dos cosas son trabajo de la proyeccion
				// (Unidad VII); por eso todavia es una caja negra.
				const float ancho = static_cast<float>(kWindowWidth);
				const float alto  = static_cast<float>(kWindowHeight);
				const glm::mat4 ajuste =
				        glm::scale(glm::mat4(1.0f),
				                   glm::vec3(alto / ancho, 1.0f, -1.0f));

				// uAjuste se fija UNA sola vez -> version por nombre,
				// que es la legible. Fuera del bucle no hay costo.
				shader.set_uniform("uAjuste", ajuste);

				// uModel y uColor cambian por pieza y por cuadro -> se
				// consulta la ubicacion UNA vez, aca, y en el bucle se
				// usa el entero. Buscar la cadena de texto en cada
				// cuadro serian miles de busquedas por segundo para
				// obtener siempre el mismo numero.
				//
				// En modo normales, uColor esta declarado en el
				// fragment shader pero NO se usa: el compilador de GLSL
				// puede eliminarlo y loc() devuelve -1. El modulo avisa.
				const int loc_model = shader.loc("uModel");
				const int loc_color = shader.loc("uColor");

				// --- Las matrices de modelo ----------------------
				// OJO con el orden en glm: cada llamada multiplica por
				// derecha, asi que LA ULTIMA QUE SE ESCRIBE ES LA
				// PRIMERA QUE SE APLICA. Escribiendo translate, rotate
				// y scale en ese orden se obtiene M = T * R * S, o sea
				// escalar -> rotar -> trasladar, que es lo que se
				// quiere: la pieza se dimensiona, se orienta sobre si
				// misma y recien despues se ubica en la escena.
				// Y las funciones DEVUELVEN, no modifican: hay que
				// asignar el resultado.
				// Las tres piezas quedan SEPARADAS: cada una ocupa su
				// franja en x, con un hueco de ~0.19 entre vecinas, y el
				// conjunto entra en [-1,1] sin recortarse. Las medidas se
				// ajustaron por calculo, no a ojo.
				glm::mat4 m_cubo(1.0f);
				m_cubo = glm::translate(m_cubo, glm::vec3(-0.95f, 0.0f, 0.0f));
				m_cubo = glm::rotate(m_cubo, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				m_cubo = glm::rotate(m_cubo, glm::radians(35.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				m_cubo = glm::scale(m_cubo, glm::vec3(0.46f));

				// El cilindro va algo inclinado, como en la figura de
				// referencia de la catedra ("escena-primitivas coloreada
				// usando las normales"): asi se ve el lateral y una tapa.
				glm::mat4 m_cil(1.0f);
				m_cil = glm::translate(m_cil, glm::vec3(0.0f, -0.02f, 0.0f));
				m_cil = glm::rotate(m_cil, glm::radians(-20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				m_cil = glm::rotate(m_cil, glm::radians(24.0f), glm::vec3(0.0f, 0.0f, 1.0f));

				glm::mat4 m_cono(1.0f);
				m_cono = glm::translate(m_cono, glm::vec3(0.95f, -0.05f, 0.0f));
				m_cono = glm::rotate(m_cono, glm::radians(-18.0f), glm::vec3(1.0f, 0.0f, 0.0f));

				const std::vector<Pieza> piezas = {
					{ &malla_cubo, m_cubo, { 0.88f, 0.30f, 0.28f } },
					{ &malla_cil,  m_cil,  { 0.32f, 0.72f, 0.40f } },
					{ &malla_cono, m_cono, { 0.33f, 0.50f, 0.88f } },
				};

				// --- 4. Dar la orden -----------------------------
				while (!glfwWindowShouldClose(window)) {
					processInput(window);

					glClearColor(51.0f/256, 55.0f/256, 76.0f/256, 1.0f);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

					shader.use();
					// En el bucle solo quedan el cambio de uniform y
					// la llamada de dibujado.
					for (const Pieza& p : piezas) {
						shader.set_uniform(loc_model, p.model);
						shader.set_uniform(loc_color, p.color);
						glBindVertexArray(p.malla->vao());
						glDrawElements(GL_TRIANGLES, p.malla->count(),
						               GL_UNSIGNED_INT, nullptr);
					}

					glfwSwapBuffers(window);
					glfwPollEvents();
				}
			}
		}
		catch (const std::exception& e) {
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
