// ----------------------------------------------------------------------------
// Shader.cpp  -  Practico 02, Parte 2.
// Ver Shader.h para las decisiones de diseño y su justificacion.
// ----------------------------------------------------------------------------

#include "Shader.h"

#include <iostream>
#include <utility>      // std::exchange

#include <glad/gl.h>

namespace {

// Pide el log de COMPILACION de un shader. El largo se consulta: un char[512]
// trunca el mensaje justo cuando es largo.
std::string shader_log(GLuint shader)
{
    GLint largo = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &largo);   // incluye el '\0'
    if (largo <= 0) {
        return {};
    }
    std::string log(static_cast<std::size_t>(largo), '\0');
    glGetShaderInfoLog(shader, largo, nullptr, log.data());
    return log;
}

// Idem para el log de LINKEO de un programa.
std::string program_log(GLuint program)
{
    GLint largo = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &largo);
    if (largo <= 0) {
        return {};
    }
    std::string log(static_cast<std::size_t>(largo), '\0');
    glGetProgramInfoLog(program, largo, nullptr, log.data());
    return log;
}

// Compila un componente. Devuelve 0 si fallo, y en ese caso ya imprimio el log.
GLuint compilar(GLenum tipo, const std::string& fuente, const char* nombre)
{
    const GLuint shader = glCreateShader(tipo);
    const char*  src    = fuente.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint ok = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        std::cout << "Shader: fallo la compilacion del " << nombre << ":\n"
                  << shader_log(shader) << std::endl;
        glDeleteShader(shader);
        return 0U;
    }
    return shader;
}

}  // namespace


Shader::~Shader()
{
    clear();
}


Shader::Shader(Shader&& other) noexcept
    : id_(std::exchange(other.id_, 0U))
{
}


Shader& Shader::operator=(Shader&& other) noexcept
{
    if (this != &other) {
        clear();                                // suelta lo propio primero
        id_ = std::exchange(other.id_, 0U);
    }
    return *this;
}


bool Shader::compile_from_source(const std::string& vs, const std::string& fs)
{
    clear();   // recompilar no debe dejar huerfano el programa anterior

    const GLuint vs_id = compilar(GL_VERTEX_SHADER,   vs, "vertex shader");
    if (vs_id == 0U) {
        return false;                      // el objeto queda vacio
    }

    const GLuint fs_id = compilar(GL_FRAGMENT_SHADER, fs, "fragment shader");
    if (fs_id == 0U) {
        glDeleteShader(vs_id);             // no dejar suelto el que si compilo
        return false;
    }

    const GLuint program = glCreateProgram();
    glAttachShader(program, vs_id);
    glAttachShader(program, fs_id);
    glLinkProgram(program);

    GLint ok = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &ok);

    // Los componentes ya estan linkeados dentro del programa: se liberan
    // siempre, haya salido bien o mal.
    glDeleteShader(vs_id);
    glDeleteShader(fs_id);

    if (!ok) {
        std::cout << "Shader: fallo el linkeo del programa:\n"
                  << program_log(program) << std::endl;
        glDeleteProgram(program);
        return false;                      // el objeto queda vacio
    }

    id_ = program;
    return true;
}


void Shader::use(void) const
{
    glUseProgram(id_);
}


void Shader::clear(void)
{
    glDeleteProgram(id_);   // glDeleteProgram(0) es legal: no hace nada
    id_ = 0U;
}
