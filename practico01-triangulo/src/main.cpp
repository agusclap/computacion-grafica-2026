#include <cstdlib>          // EXIT_FAILURE, EXIT_SUCCESS
#include <iostream>
#include <string>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

static const char* kWindowTitle     = "OpenGL template project";
static constexpr int kWindowWidth   = 800;
static constexpr int kWindowHeight  = 600;
static constexpr int kGLVerMajor    = 4;
static constexpr int kGLVerMinor    = 6;

static int glfw_error_code{};
static std::string glfw_error_str{};

static void error_callback(int error, const char *description);
static void framebuffer_size_callback(GLFWwindow* window,
                                      int width, int height);
static void processInput(GLFWwindow *window);
static void print_gl_version(void);

// ------------------------------------------------------------------------------
// Practico 01: triangulo con vertex + fragment shader (Hoja de ruta A)

// 1 - Los datos: tres vertices, coordenadas en [-1, 1]
static const float kVertices[] = {
     0.0f,  0.5f, 0.0f,  // arriba
    -0.5f, -0.5f, 0.0f,  // abajo izquierda
     0.5f, -0.5f, 0.0f   // abajo derecha
};

static const char* kVertexShaderSrc = R"glsl(
#version 460 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
}
)glsl";

static const char* kFragmentShaderSrc = R"glsl(
#version 460 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
)glsl";

// Compila un shader y, si falla, imprime el log completo (largo dinamico,
// no un char log[512] que trunca el mensaje justo cuando mas se lo necesita).
static GLuint compile_shader(GLenum type, const char* src, const char* name)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint ok = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        GLint largo = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &largo); // incluye el '\0'
        std::string log(largo, '\0');
        glGetShaderInfoLog(shader, largo, nullptr, log.data());
        std::cout << name << ": " << log << std::endl;
    }
    return shader;
}

// Linkea vertex+fragment en un programa y, si falla, imprime el log.
static GLuint link_program(GLuint vs, GLuint fs)
{
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    GLint ok = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &ok);
    if (!ok) {
        GLint largo = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &largo);
        std::string log(largo, '\0');
        glGetProgramInfoLog(program, largo, nullptr, log.data());
        std::cout << "Program link: " << log << std::endl;
    }
    return program;
}

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
		// Clean resources already created
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
		// Clean resources already created
		glfwDestroyWindow(window);
		glfwTerminate();

		std::cout << "GLAD initialization failed!" << std::endl;

		return EXIT_FAILURE;
	}

	// Show current system OpenGL info
	print_gl_version();

	// Set GLFW callbacks
	//glViewport(0, 0, kWindowWidth, kWindowHeight);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Configure sync with monitor
    // interval: the number of screen updates to wait from the time
    // glfwSwapBuffers was called before swapping the buffers and returning.
	// 0 -> run at code speed (don't sync to monitor)
	// 1 -> sync with motinor refresh rate (code run at monitor refresh rate)
    // 2 -> sync with half monitor refresh rate (code run at half monitor
    //      refresh rate)
	glfwSwapInterval(1);

	// ---------------------------------------------------------------------
	// 2 - Enviar los bytes a la GPU y decir como se leen (VBO + VAO, DSA)
	GLuint vbo = 0;
	glCreateBuffers(1, &vbo);
	glNamedBufferData(vbo, sizeof(kVertices), kVertices, GL_STATIC_DRAW);

	GLuint vao = 0;
	glCreateVertexArrays(1, &vao);
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, 3 * sizeof(float));
	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vao, 0, 0);
	glEnableVertexArrayAttrib(vao, 0);

	// ---------------------------------------------------------------------
	// 3 - Armar el programa (vertex + fragment shader)
	GLuint vs = compile_shader(GL_VERTEX_SHADER, kVertexShaderSrc, "Vertex shader");
	GLuint fs = compile_shader(GL_FRAGMENT_SHADER, kFragmentShaderSrc, "Fragment shader");
	GLuint program = link_program(vs, fs);
	// Los shaders ya quedaron linkeados en el programa; no hacen falta sueltos.
	glDeleteShader(vs);
	glDeleteShader(fs);

	while(!glfwWindowShouldClose(window)){
		// input
		processInput(window);

		// rendering commands here
		glClearColor(51.0f/256, 55.0f/256, 76.0f/256, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// 4 - Dar la orden: acá aparece el triángulo
		glUseProgram(program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clean resources before close
	glDeleteProgram(program);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glfwDestroyWindow(window);
	glfwTerminate();

	return EXIT_SUCCESS;
}

void error_callback(int error, const char *description){
    glfw_error_code = error;
    glfw_error_str = std::string(description);
}

void framebuffer_size_callback([[maybe_unused]]  GLFWwindow* window,
                               int width, int height){
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
}

void print_gl_version(void){
    // show gl info
    std::cout << " OpenGL Vendor: "
              << glGetString(GL_VENDOR) << std::endl;
    std::cout << " OpenGL Renderer: "
              << glGetString(GL_RENDERER) << std::endl;
    std::cout << " OpenGL Version: "
              << glGetString(GL_VERSION) << std::endl;
    std::cout << " GLSL Version: "
              << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}
