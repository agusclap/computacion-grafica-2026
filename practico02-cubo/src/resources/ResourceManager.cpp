// ----------------------------------------------------------------------------
// ResourceManager.cpp  -  Practico 01, Parte 2.
// Ver ResourceManager.h para las decisiones de diseño y su justificacion.
// ----------------------------------------------------------------------------

#include "ResourceManager.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace {

// Arma el mensaje de error con un prefijo uniforme, para que se vea de donde
// salio sin tener que rastrear el stack.
std::runtime_error fallo(const std::string& detalle)
{
    return std::runtime_error("ResourceManager: " + detalle);
}

}  // namespace


ResourceManager::ResourceManager(const std::filesystem::path& assets_root)
    : assets_root_(assets_root)
{
    // "no esta la carpeta" es uno de los fallos que la guia pide avisar, y
    // conviene detectarlo al construir y no recien al pedir el primer recurso.
    std::error_code ec;
    if (!std::filesystem::is_directory(assets_root_, ec)) {
        throw fallo("no existe la carpeta de assets: '"
                    + assets_root_.string() + "'");
    }
}


std::string ResourceManager::read_shader_file(const std::string& shader_file,
                                              const std::string& shader_type)
{
    const std::filesystem::path full = assets_root_ / shader_file;

    // Se abre en binario para no traducir los fines de linea: el texto va tal
    // cual al compilador de GLSL.
    std::ifstream in(full, std::ios::in | std::ios::binary);
    if (!in) {
        throw fallo("no se pudo abrir el " + shader_type + ": '"
                    + full.string() + "'");
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    ++disk_reads_;

    std::string source = buffer.str();
    if (source.empty()) {
        // Un archivo vacio compila "bien" y despues da pantalla negra sin
        // ningun mensaje: conviene cortarlo aca.
        throw fallo("el " + shader_type + " esta vacio: '"
                    + full.string() + "'");
    }
    return source;
}


const ShaderSource& ResourceManager::load_shader_source(
        const std::string& key,
        const std::string& vs_file,
        const std::string& fs_file,
        const std::string& gs_file)
{
    const std::string origin = vs_file + '|' + fs_file + '|' + gs_file;

    const auto it = shaders_sources_.find(key);
    if (it != shaders_sources_.end()) {
        if (key_origin_.at(key) != origin) {
            // Decision 3: ambiguo, se avisa en lugar de elegir en silencio.
            throw fallo("la clave '" + key + "' ya esta cargada con otros "
                        "archivos ('" + key_origin_.at(key) + "'); se pidio "
                        "cargarla con ('" + origin + "')");
        }
        return it->second;   // cache hit: no se toca el disco
    }

    // Se leen los tres fuentes ANTES de tocar el mapa: si alguno falla, el
    // ResourceManager queda como estaba y no con media entrada cargada.
    ShaderSource source;
    source.vs = read_shader_file(vs_file, "vertex shader");
    source.fs = read_shader_file(fs_file, "fragment shader");
    if (!gs_file.empty()) {
        source.gs = read_shader_file(gs_file, "geometry shader");
    }

    key_origin_.emplace(key, origin);
    return shaders_sources_.emplace(key, std::move(source)).first->second;
}


const ShaderSource& ResourceManager::get_shader_source(
        const std::string& key) const
{
    const auto it = shaders_sources_.find(key);
    if (it == shaders_sources_.end()) {
        throw fallo("no hay ningun shader cargado con la clave '" + key + "'");
    }
    return it->second;
}


void ResourceManager::clear(void)
{
    shaders_sources_.clear();
    key_origin_.clear();
    // disk_reads_ no se reinicia a proposito: es el acumulado de la instancia.
}
