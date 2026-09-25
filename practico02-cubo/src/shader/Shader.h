// ----------------------------------------------------------------------------
// Shader.h  -  Practico 02, Parte 2.
//
// Administra el programa de shader linkeado. Es la misma estrategia del modulo
// Mesh sobre otro recurso: un programa que se identifica por un nombre (un
// unico entero en vez de tres). Lo que cambia es el tipo de recurso, no el
// criterio.
//
// ----------------------------------------------------------------------------
// LAS MISMAS TRES DECISIONES
//   1. El destructor libera (glDeleteProgram). Ningun glDelete* fuera de aca.
//   2. Copia prohibida: duplicaria el entero pero no el programa de la GPU.
//   3. Movimiento permitido, dejando el origen en CERO. glDeleteProgram(0) es
//      legal y no hace nada, asi que el objeto vaciado se destruye sin romper.
//
// ----------------------------------------------------------------------------
// OTRAS DECISIONES  (las "cuestiones a pensar" de la guia, p.3)
//
//  - ESTA CLASE NO ABRE ARCHIVOS. Recibe el codigo fuente ya leido; quien lee
//    del disco es el ResourceManager del Practico 01. Ninguno hace el trabajo
//    del otro: ese es todo el criterio de separacion.
//
//  - El largo del log SE CONSULTA con GL_INFO_LOG_LENGTH; no se asume un
//    char[512]. Un buffer fijo trunca el mensaje justo cuando es largo, que es
//    cuando mas se lo necesita.
//
//  - Si algo no compila o no linkea: se pide el log, se IMPRIME, y el objeto
//    QUEDA VACIO (id() == 0). Un shader roto no puede pasar desapercibido: es
//    la falla 2 de la clinica del triangulo.
//
//  - Como se avisa el error: por VALOR DE RETORNO (bool), no por excepcion.
//    ¿Es coherente con el ResourceManager, que usa excepciones? Si, y la
//    diferencia esta justificada por dos motivos:
//      a) Por la interfaz. ResourceManager devuelve 'const ShaderSource&', y
//         una referencia no tiene valor invalido que se pueda devolver: el
//         retorno no esta disponible como canal de aviso. Aca el retorno es un
//         bool, que si lo esta.
//      b) Por la naturaleza del fallo. Que falte un archivo es un error de
//         despliegue y no hay forma sensata de seguir. Que el driver rechace
//         un shader es informacion que el programa puede querer manejar (por
//         ejemplo, volver a un shader de respaldo).
//    En los dos casos el modulo IMPRIME el detalle, asi que ninguno de los dos
//    falla en silencio, que es la regla que de verdad importa.
// ----------------------------------------------------------------------------

#pragma once

#include <string>

class Shader {
public:
    Shader() = default;
    ~Shader();                                     // libera el programa

    Shader(const Shader&)            = delete;     // las MISMAS tres decisiones
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    // Compila los dos componentes, los linkea y libera los objetos
    // intermedios. Devuelve true si el programa quedo utilizable.
    // Si falla: imprime el log del driver y el objeto queda vacio (id()==0).
    bool compile_from_source(const std::string& vs, const std::string& fs);

    void use(void) const;

    // Se puede llamar dos veces sin romper nada: glDeleteProgram(0) no hace nada.
    void clear(void);

    unsigned int id(void) const { return id_; }

private:
    unsigned int id_ {0U};   // un entero, no cuatro
};
