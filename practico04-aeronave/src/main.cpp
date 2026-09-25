// ----------------------------------------------------------------------------
// main.cpp  -  Practico 04, Parte 3: la aeronave en movimiento.
//
// La escena tiene UN SOLO MODELO armado con OCHO PIEZAS que comparten TRES
// MALLAS. El bucle de dibujado no sabe nada de aeronaves: le pide a Aircraft
// que recalcule su pose y que le entregue la lista de unidades de dibujado.
//
// LA VERIFICACION QUE PIDE LA GUIA
//   "Rotar la aeronave en uno de sus ejes y verificar que todas las piezas se
//    muevan juntas, girando alrededor del punto de referencia elegido y no de
//    un punto arbitrario del modelo."
//
//   El programa arranca cabeceando (rotacion sobre el eje del ala) de forma
//   continua. Hay que mirar dos cosas:
//     1) que el modelo NO SE DESARME: ninguna pieza se atrasa, se despega ni
//        se queda quieta. Eso prueba que la misma M_pose multiplica a las
//        ocho matrices locales.
//     2) que el centro de giro sea el PUNTO DE REFERENCIA -- la crucecita que
//        se puede dibujar con la tecla P -- y no la nariz, que es donde esta
//        el origen del modelo. Con la tecla O se quita el T(-ref) de la pose
//        y se ve el error: la aeronave se va de paseo girando alrededor de la
//        punta de la nariz.
//
// Uso:
//     ogl-app [gajos] [normales] [quieto]
//
//   quieto   arranca en pausa, para mirar el despiece sin que se mueva.
//   captura  dibuja cuatro cuadros a angulos de cabeceo conocidos, vuelca
//            cada uno a captura-N.ppm y termina. Es la verificacion objetiva:
//            no depende de mirar la pantalla.
//
// Teclas:
//     1 / 2 / 3   cabeceo / guiñada / alabeo   (se pueden combinar)
//     0           deja de rotar y vuelve a la pose neutra
//     ESPACIO     pausa y reanuda la animacion
//     P           muestra u oculta el punto de referencia
//     O           conmuta el T(-ref): con el punto de referencia o sin el
//     ESC         salir
//
// Este archivo sigue sin tener ninguna llamada glDelete*: los dueños de los
// recursos de OpenGL son Mesh y Shader.
// ----------------------------------------------------------------------------

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "aircraft/Aircraft.h"
#include "aircraft/RenderItem.h"
#include "mesh/Mesh.h"
#include "mesh/Primitives.h"
#include "resources/ResourceManager.h"
#include "shader/Shader.h"

static const char* kWindowTitle     = "Practico 04 - armado de la aeronave";
static constexpr int kWindowWidth   = 800;
static constexpr int kWindowHeight  = 600;
static constexpr int kGLVerMajor    = 4;
static constexpr int kGLVerMinor    = 6;

static const char* kAssetsRoot = "./assets";

static int glfw_error_code{};
static std::string glfw_error_str{};

static void error_callback(int error, const char *description);
static void framebuffer_size_callback(GLFWwindow* window, int w, int h);
static void print_gl_version(void);

namespace {

// Estado de la demostracion. Se toca desde el callback de teclado, que es el
// lugar correcto para un cambio de MODO: glfwGetKey() dentro del bucle informa
// si la tecla esta apretada AHORA, y a 60 cuadros por segundo una pulsacion
// normal dura varios cuadros, asi que un modo conmutado ahi parpadearia. El
// callback avisa del FLANCO, una vez por pulsacion.
struct Estado {
	bool rota_cabeceo {true};    // arranca cabeceando: es la verificacion
	bool rota_guinada {false};
	bool rota_alabeo  {false};
	bool pausado      {false};
	bool marca_ref    {true};    // dibuja el punto de referencia
	bool usa_ref      {true};    // aplica el T(-ref) de la pose
};

Estado g_estado;

void key_callback([[maybe_unused]] GLFWwindow* window, int key,
                  [[maybe_unused]] int scancode, int action,
                  [[maybe_unused]] int mods)
{
	if (action != GLFW_PRESS) { return; }

	switch (key) {
	case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, true);       break;
	case GLFW_KEY_1: g_estado.rota_cabeceo = !g_estado.rota_cabeceo;    break;
	case GLFW_KEY_2: g_estado.rota_guinada = !g_estado.rota_guinada;    break;
	case GLFW_KEY_3: g_estado.rota_alabeo  = !g_estado.rota_alabeo;     break;
	case GLFW_KEY_0:
		g_estado.rota_cabeceo = false;
		g_estado.rota_guinada = false;
		g_estado.rota_alabeo  = false;
		break;
	case GLFW_KEY_SPACE: g_estado.pausado   = !g_estado.pausado;        break;
	case GLFW_KEY_P:     g_estado.marca_ref = !g_estado.marca_ref;      break;
	case GLFW_KEY_O:
		g_estado.usa_ref = !g_estado.usa_ref;
		std::cout << "Punto de referencia: "
		          << (g_estado.usa_ref
		              ? "ACTIVO   (gira alrededor de 0.438*L_f)"
		              : "ANULADO  (gira alrededor de la nariz)")
		          << std::endl;
		break;
	default: break;
	}
}

// ----------------------------------------------------------------------------
// Herramienta de VERIFICACION, no parte del practico: vuelca el framebuffer a
// un archivo PPM. Sirve para comprobar el resultado sin depender de mirar la
// pantalla -- y sobre todo para comparar dos cuadros pixel a pixel.
//
// glReadPixels entrega las filas de ABAJO HACIA ARRIBA (el origen de OpenGL es
// la esquina inferior izquierda) y el PPM las espera al reves, asi que se
// escriben en orden invertido.
// ----------------------------------------------------------------------------
bool volcar_ppm(const char* archivo, int ancho, int alto)
{
	std::vector<unsigned char> px(static_cast<std::size_t>(ancho) * alto * 3U);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, ancho, alto, GL_RGB, GL_UNSIGNED_BYTE, px.data());

	std::ofstream f(archivo, std::ios::binary);
	if (!f) { return false; }
	// El \n se escribe como char(10) a proposito: es el separador del
	// encabezado PPM y tiene que salir tal cual.
	const char nl = static_cast<char>(10);
	f << "P6" << nl << ancho << " " << alto << nl << 255 << nl;
	for (int y = alto - 1; y >= 0; --y) {
		f.write(reinterpret_cast<const char*>(
		            px.data() + static_cast<std::size_t>(y) * ancho * 3U),
		        static_cast<std::streamsize>(ancho) * 3);
	}
	return static_cast<bool>(f);
}

}  // namespace


int main(int argc, char** argv)
{
	// --- Parametros de linea de comandos ---------------------------------
	unsigned gajos = 24U;
	bool     modo_normales = false;
	bool     modo_captura  = false;
	for (int i = 1; i < argc; ++i) {
		const std::string arg = argv[i];
		if (arg == "normales") { modo_normales = true; }
		else if (arg == "quieto") { g_estado.pausado = true; }
		else if (arg == "captura") { modo_captura = true; }
		else if (arg == "sinref") { g_estado.usa_ref = false; }
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
	glfwSetKeyCallback(window, key_callback);
	glfwSwapInterval(1);

	// Sin esto el modelo se dibujaria por orden de lista y no por cercania:
	// el ala izquierda taparia al fuselaje aunque estuviera detras.
	glEnable(GL_DEPTH_TEST);

	int exit_code = EXIT_SUCCESS;

	// Bloque de vida de los objetos que POSEEN recursos de OpenGL: tienen que
	// morir con el contexto todavia vivo.
	{
		try {
			// --- 1. El modelo: mallas y despiece, UNA sola vez -------
			Aircraft aeronave;
			if (!aeronave.init(gajos)) {
				throw std::runtime_error("No se pudo armar la aeronave.");
			}

			std::cout << "Despiece: " << aeronave.piezas() << " piezas sobre "
			          << aeronave.mallas() << " mallas" << std::endl;
			for (std::size_t i = 0U; i < aeronave.piezas(); ++i) {
				std::cout << "  " << (i + 1U) << ". "
				          << aeronave.nombre(i) << std::endl;
			}
			const glm::vec3 kRefAeronave = aeronave.ref();
			std::cout << "Punto de referencia: (" << aeronave.ref().x << ", "
			          << aeronave.ref().y << ", " << aeronave.ref().z
			          << ")  = 0.438 * L_f desde la nariz" << std::endl;

			// Malla auxiliar para marcar el punto de referencia. No es parte
			// del modelo: es instrumental, como una regla apoyada al lado.
				Mesh marca;
				marca.load(primitives::cube());   // cubo unitario, se escala

				// Un cubito solo no serviria: el punto de referencia cae sobre
				// el eje del fuselaje, o sea DENTRO del tubo, y el test de
				// profundidad lo taparia. Por eso la marca son tres varillas
				// largas y finas -- una por eje -- que asoman a los dos lados.
				constexpr float kLargoVarilla  = 0.55f;
				constexpr float kGrosorVarilla = 0.006f;
				const glm::mat4 varillas[3] = {
					glm::scale(glm::mat4(1.0f), glm::vec3(kLargoVarilla,
					           kGrosorVarilla, kGrosorVarilla)),
					glm::scale(glm::mat4(1.0f), glm::vec3(kGrosorVarilla,
					           kLargoVarilla, kGrosorVarilla)),
					glm::scale(glm::mat4(1.0f), glm::vec3(kGrosorVarilla,
					           kGrosorVarilla, kLargoVarilla)),
				};

			// --- 2. El programa de shaders ---------------------------
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
				// Sigue siendo la del Practico 03: corrige la relacion
				// de aspecto y niega Z. Las dos cosas son trabajo de la
				// proyeccion, que recien aparece en el Practico 05.
				//
				// El modelo mide L_f = 1 de largo y su punto mas lejano
				// al de referencia esta a 0.756; con la correccion de
				// aspecto el conjunto entra en [-1,1] para CUALQUIER
				// rotacion, sin recortarse. Eso se calculo, no se
				// ajusto a ojo.
				// Lleva ademas una ROTACION DE VISTA fija. Sin ella el
				// eje del fuselaje apunta al observador y la aeronave se
				// ve de punta: un disco con las alas de canto. La
				// rotacion la elige el punto de vista, no el modelo, asi
				// que es trabajo de la matriz de vista -- el Practico
				// 05 -- y por eso entra aca, en la caja negra.
				// Con 115 grados de guiñada la nariz queda hacia el
				// observador y a la izquierda, y el eje del ala queda
				// casi perpendicular a la pantalla: asi el cabeceo se ve
				// como un giro EN EL PLANO de la imagen, que es la forma
				// mas clara de comprobar alrededor de que punto gira.
				// Los 18 grados de cabeceo levantan el punto de vista
				// para que se vea el dorso.
				const float ancho = static_cast<float>(kWindowWidth);
				const float alto  = static_cast<float>(kWindowHeight);
				glm::mat4 ajuste(1.0f);
				// El 1.25 es un acercamiento: el punto del modelo mas lejano al
				// de referencia esta a 0.756, asi que 0.756*1.25 = 0.945 < 1 y el
				// conjunto entra en el volumen de recorte para CUALQUIER rotacion.
				// Es lo que despues hara el campo visual de la proyeccion.
				ajuste = glm::scale(ajuste,
				                    glm::vec3(1.25f * alto / ancho, 1.25f, -1.25f));
				ajuste = glm::rotate(ajuste, glm::radians(18.0f),
				                     glm::vec3(1.0f, 0.0f, 0.0f));
				ajuste = glm::rotate(ajuste, glm::radians(115.0f),
				                     glm::vec3(0.0f, 1.0f, 0.0f));

				shader.set_uniform("uAjuste", ajuste);

				// Se consultan UNA vez y en el bucle se usa el entero.
				const int loc_model = shader.loc("uModel");
				const int loc_color = shader.loc("uColor");

				// El vector de items se declara AFUERA del bucle y
				// collect() lo reusa: asi no se pide memoria nueva 60
				// veces por segundo.
				std::vector<RenderItem> items;
				items.reserve(16U);

				// Velocidades de rotacion, en radianes por segundo.
				// Distintas entre si a proposito: con velocidades
				// iguales, combinar dos ejes daria un movimiento
				// repetitivo que esconde los errores.
				const glm::vec3 vel(glm::radians(45.0f),
				                    glm::radians(27.0f),
				                    glm::radians(33.0f));

				// El tiempo de la ANIMACION no es el tiempo del reloj:
				// se acumula solo cuando no esta pausada. Si se usara
				// glfwGetTime() directo, al despausar el modelo
				// pegaria un salto.
				double t_anim  = 0.0;
				double t_prev  = glfwGetTime();

				std::cout << "\nTeclas: 1/2/3 cabeceo/guiñada/alabeo | "
				             "0 detener | ESPACIO pausa | "
				             "P marca del punto de referencia | "
				             "O anular el punto de referencia | ESC salir"
				          << std::endl;

				// Angulos de cabeceo del modo captura, en grados. Cuatro
				// cuadros a angulos conocidos: si el modelo se desarmara,
				// se veria en alguno de ellos.
				const float kCapturas[] = {0.0f, 40.0f, 80.0f, 120.0f};
				std::size_t captura_i = 0U;

				while (!glfwWindowShouldClose(window)) {
					const double t_hoy = glfwGetTime();
					const double dt    = t_hoy - t_prev;
					t_prev = t_hoy;
					if (!g_estado.pausado) { t_anim += dt; }

					const float t = static_cast<float>(t_anim);
					glm::vec3 angulos(
					        g_estado.rota_cabeceo ? vel.x * t : 0.0f,
					        g_estado.rota_guinada ? vel.y * t : 0.0f,
					        g_estado.rota_alabeo  ? vel.z * t : 0.0f);

					if (modo_captura) {
						angulos = glm::vec3(
						        glm::radians(kCapturas[captura_i]),
						        0.0f, 0.0f);
					}

					// Demostracion de por que hace falta el T(-ref):
					// con la tecla O el punto de referencia se corre a
					// la NARIZ, que es el origen del modelo. La pose se
					// arma igual; lo unico que cambia es ese punto.
					aeronave.set_ref(g_estado.usa_ref
					                 ? kRefAeronave
					                 : glm::vec3(0.0f));

					// --- Parte 3: UNA pose para las ocho piezas ---
					aeronave.update(glm::vec3(0.0f), angulos);
					aeronave.collect(items);

					glClearColor(51.0f/256, 55.0f/256, 76.0f/256, 1.0f);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

					shader.use();
					for (const RenderItem& it : items) {
						shader.set_uniform(loc_model, it.model);
						shader.set_uniform(loc_color, it.color);
						glBindVertexArray(it.mesh->vao());
						glDrawElements(GL_TRIANGLES, it.mesh->count(),
						               GL_UNSIGNED_INT, nullptr);
					}

					// La marca del punto de referencia NO se rota: se
					// queda fija en el mundo. Que la aeronave gire
					// alrededor de ella -- y no la arrastre -- es
					// exactamente lo que hay que ver.
					if (g_estado.marca_ref) {
						shader.set_uniform(loc_color,
						                   glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
						glBindVertexArray(marca.vao());
						for (const glm::mat4& v : varillas) {
							shader.set_uniform(loc_model, v);
							glDrawElements(GL_TRIANGLES, marca.count(),
							               GL_UNSIGNED_INT, nullptr);
						}
					}

					if (modo_captura) {
						const std::string nom =
						        std::string(g_estado.usa_ref ? "captura-"
						                                     : "sinref-")
						        + std::to_string(captura_i) + ".ppm";
						if (volcar_ppm(nom.c_str(), kWindowWidth,
						               kWindowHeight)) {
							std::cout << "  " << nom << "  cabeceo = "
							          << kCapturas[captura_i] << " grados"
							          << std::endl;
						}
						if (++captura_i >= (sizeof(kCapturas)
						                    / sizeof(kCapturas[0]))) {
							glfwSetWindowShouldClose(window, true);
						}
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

void print_gl_version(void){
    std::cout << " OpenGL Vendor: "   << glGetString(GL_VENDOR)   << std::endl;
    std::cout << " OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << " OpenGL Version: "  << glGetString(GL_VERSION)  << std::endl;
    std::cout << " GLSL Version: "
              << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}
