// ----------------------------------------------------------------------------
// test_resource_manager.cpp  -  Practico 01, Parte 2.
//
// Programa de prueba pedido por la guia (recomendacion 1): "Crear main.cpp de
// prueba que demuestre que el cacheo funciona".
//
// No usa OpenGL ni ninguna libreria externa. Compilar con:
//
//   g++ -std=c++17 -Wall -Wextra -I src
//       src/resources/ResourceManager.cpp tests/test_resource_manager.cpp
//       -o bin/test-rm
//
//   (las tres lineas van en un solo comando; aca se cortan por legibilidad.
//    No se usa la barra invertida al final porque, dentro de un comentario
//    de linea, continua el comentario y g++ avisa con -Wcomment.)
//
// Se ejecuta desde la raiz del proyecto (usa ./assets como carpeta de assets).
// Devuelve 0 si todas las verificaciones pasan, 1 si alguna falla.
// ----------------------------------------------------------------------------

#include "resources/ResourceManager.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace {

int fallidas = 0;

void check(bool condicion, const std::string& que)
{
    std::cout << (condicion ? "  [ok]   " : "  [FALLA] ") << que << '\n';
    if (!condicion) {
        ++fallidas;
    }
}

// Verifica que una operacion avise el error, y muestra el mensaje para que se
// vea que no se rompe en silencio.
template <typename Fn>
void check_avisa(Fn&& operacion, const std::string& que)
{
    try {
        operacion();
        check(false, que + " -- NO aviso: paso en silencio");
    } catch (const std::runtime_error& e) {
        check(true, que);
        std::cout << "          aviso: " << e.what() << '\n';
    }
}

}  // namespace


int main()
{
    std::cout << "== ResourceManager: pruebas ==\n\n";

    // ------------------------------------------------------------------
    std::cout << "1. Carga desde disco\n";
    ResourceManager recursos("./assets");

    const ShaderSource& solid =
        recursos.load_shader_source("solid", "shaders/solid.vs",
                                            "shaders/solid.fs");

    check(recursos.disk_reads() == 2U,
          "leyo 2 archivos del disco (vs + fs)");
    check(solid.vs.find("gl_Position") != std::string::npos,
          "el vertex shader trae su contenido");
    check(solid.fs.find("FragColor") != std::string::npos,
          "el fragment shader trae su contenido");
    check(solid.gs.empty(),
          "sin geometry shader, el campo gs queda vacio");

    // ------------------------------------------------------------------
    std::cout << "\n2. Cacheo: la segunda vez NO vuelve a leer del disco\n";
    const std::size_t lecturas_antes = recursos.disk_reads();

    const ShaderSource& otra_vez =
        recursos.load_shader_source("solid", "shaders/solid.vs",
                                            "shaders/solid.fs");

    check(recursos.disk_reads() == lecturas_antes,
          "el contador de lecturas de disco no subio");
    check(&otra_vez == &solid,
          "devolvio una referencia al MISMO objeto ya cargado");

    // ------------------------------------------------------------------
    std::cout << "\n3. get_shader_source() sobre lo ya cargado\n";
    const ShaderSource& consultado = recursos.get_shader_source("solid");
    check(&consultado == &solid, "devuelve el recurso cargado");
    check(recursos.disk_reads() == lecturas_antes,
          "consultar tampoco toca el disco");

    // ------------------------------------------------------------------
    std::cout << "\n4. Los fallos se avisan (no se rompe en silencio)\n";

    check_avisa([] { ResourceManager rm("./carpeta-que-no-existe"); },
                "carpeta de assets inexistente");

    check_avisa([&] { recursos.load_shader_source("roto",
                                                  "shaders/no-existe.vs",
                                                  "shaders/solid.fs"); },
                "archivo de shader inexistente");

    check_avisa([&] { recursos.load_shader_source("vacio",
                                                  "shaders/solid.vs",
                                                  "shaders/vacio.fs"); },
                "archivo de shader vacio");

    check_avisa([&] { recursos.get_shader_source("nunca-cargado"); },
                "pedir una clave que no se cargo");

    check_avisa([&] { recursos.load_shader_source("solid",
                                                  "shaders/solid.vs",
                                                  "shaders/vacio.fs"); },
                "misma clave con archivos distintos");

    // ------------------------------------------------------------------
    std::cout << "\n5. Una carga fallida no deja el modulo a medias\n";
    check_avisa([&] { recursos.get_shader_source("roto"); },
                "la clave que fallo al cargar no quedo registrada");

    // ------------------------------------------------------------------
    std::cout << "\n6. clear()\n";
    recursos.clear();
    check_avisa([&] { recursos.get_shader_source("solid"); },
                "despues de clear() ya no hay nada cargado");

    recursos.clear();
    check(true, "clear() se puede llamar dos veces sin romper nada");

    const std::size_t lecturas_tras_clear = recursos.disk_reads();
    recursos.load_shader_source("solid", "shaders/solid.vs",
                                         "shaders/solid.fs");
    check(recursos.disk_reads() == lecturas_tras_clear + 2U,
          "tras clear() vuelve a leer del disco (el cache quedo vacio)");

    // ------------------------------------------------------------------
    std::cout << "\n== Resultado: "
              << (fallidas == 0 ? "TODAS LAS PRUEBAS PASARON"
                                : std::to_string(fallidas) + " FALLARON")
              << " ==\n";
    return fallidas == 0 ? 0 : 1;
}
