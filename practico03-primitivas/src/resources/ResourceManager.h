// ----------------------------------------------------------------------------
// ResourceManager.h
//
// Practico 01 - Parte 2. Modulo de gestion de recursos del proyecto.
//
// C++ puro: NO hace llamadas a la API de OpenGL. Su unica responsabilidad es
// leer recursos del disco, mantener una copia en memoria y no volver a leer lo
// que ya leyo. Quien compila y linkea los shaders es otro modulo (el Shader del
// Practico 02): ninguno hace el trabajo del otro.
//
// ----------------------------------------------------------------------------
// DECISIONES TOMADAS  (las "cuestiones a pensar" de la guia, p.2)
//
// 1. La clave la elige el usuario del modulo; NO es el nombre del archivo.
//    Motivo: un programa de shader son dos o tres archivos distintos (.vs, .fs,
//    .gs). La clave es el nombre logico que los agrupa ("solid"), y ademas
//    permite cambiar los archivos sin tocar el codigo que los pide.
//
// 2. Pedir dos veces la MISMA clave con los MISMOS archivos no vuelve a tocar
//    el disco: devuelve lo que ya esta en memoria.
//
// 3. Pedir una clave ya cargada con archivos DISTINTOS es un ERROR.
//    Motivo: es ambiguo. Recargar en silencio cambiaria el shader debajo de
//    quien ya tiene una referencia; ignorar lo nuevo en silencio devolveria un
//    recurso que no es el que se pidio. Las dos alternativas fallan calladas,
//    que es justamente lo que la guia pide evitar.
//
// 4. Los fallos se avisan con EXCEPCION (std::runtime_error).
//    Motivo: load_shader_source() y get_shader_source() devuelven una
//    referencia const, y una referencia no tiene un valor "invalido" que se
//    pueda devolver para señalar el error. Con esta interfaz, el valor de
//    retorno no esta disponible como canal de aviso.
//
// 5. Se devuelve REFERENCIA const, no una copia, para no duplicar el texto de
//    los shaders en cada consulta.
//    Cuidado: la referencia sobrevive a otras llamadas a load_shader_source()
//    -- std::unordered_map garantiza que las referencias a sus elementos siguen
//    siendo validas aunque la tabla crezca y rehashee -- pero clear() las
//    invalida todas.
//
// 6. Se usa un struct (ShaderSource) y no fuentes sueltos, porque los tres
//    fuentes viajan juntos: un programa se compila a partir de la tupla
//    completa. Guardarlos sueltos obligaria a tres mapas y a mantener a mano la
//    correspondencia entre ellos. Ademas, el mismo patron -- un struct por tipo
//    de recurso, un load_*, un get_* y un mapa -- permite ampliar el modulo mas
//    adelante a texturas y modelos.
// ----------------------------------------------------------------------------

#pragma once

#include <cstddef>
#include <filesystem>
#include <string>
#include <unordered_map>

// Codigo fuente de un programa de shader.
struct ShaderSource {
    std::string vs;   // vertex shader
    std::string fs;   // fragment shader
    std::string gs;   // geometry shader (opcional, hoy no se usa)
};

class ResourceManager {
public:
    // Lanza std::runtime_error si assets_root no es un directorio existente.
    explicit ResourceManager(const std::filesystem::path& assets_root);

    // Carga los fuentes de un programa de shader y los deja disponibles bajo
    // "key". Las rutas de los archivos son relativas a assets_root.
    // Si "key" ya estaba cargada con los mismos archivos, NO lee del disco.
    // Lanza std::runtime_error si un archivo no existe o esta vacio, o si la
    // clave ya estaba cargada con archivos distintos.
    const ShaderSource& load_shader_source(const std::string& key,
                                           const std::string& vs_file,
                                           const std::string& fs_file,
                                           const std::string& gs_file = "");

    // Devuelve lo ya cargado. Lanza std::runtime_error si la clave no existe.
    const ShaderSource& get_shader_source(const std::string& key) const;

    // Libera todo lo cargado. Invalida las referencias devueltas antes.
    // Se puede llamar dos veces sin problema.
    void clear(void);

    // Cantidad de archivos efectivamente leidos del disco desde que se creo
    // esta instancia. No forma parte de la interfaz propuesta por la guia: se
    // agrega para que el programa de prueba pueda demostrar el cacheo de forma
    // objetiva, en lugar de depender de mirar mensajes por consola.
    // clear() NO lo reinicia: es un acumulado de la instancia.
    std::size_t disk_reads(void) const { return disk_reads_; }

private:
    // Lee un archivo completo a un string. shader_type se usa solo para que el
    // mensaje de error diga cual de los tres fuentes fallo.
    std::string read_shader_file(const std::string& shader_file,
                                 const std::string& shader_type);

    std::filesystem::path assets_root_;
    std::unordered_map<std::string, ShaderSource> shaders_sources_;

    // Recuerda con que archivos se cargo cada clave, para poder detectar el
    // caso 3 (misma clave, archivos distintos).
    std::unordered_map<std::string, std::string> key_origin_;

    std::size_t disk_reads_ {0U};
};
