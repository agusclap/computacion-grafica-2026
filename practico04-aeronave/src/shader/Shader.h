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

// ----------------------------------------------------------------------------
// PRACTICO 03, PARTE 3 -- LOS UNIFORM
//
// Un uniform es una variable del programa de shaders que se fija ANTES de
// ejecutar el pipeline y mantiene el mismo valor para todos los vertices y
// todos los fragmentos de esa llamada.
//
//     atributo -> un valor por VERTICE     (viaja por el VBO)
//     uniform  -> un valor por EJECUCION del pipeline
//
// Es el camino por el que se asignan el color de la pieza y su matriz de
// modelo. Una pieza de color plano tendria que repetir el mismo color en
// cientos o miles de vertices; como uniform se escribe una sola vez.
//
// DECISIONES
//
//  - NO ES UNA LISTA CERRADA: cada tipo nuevo de uniform que requiera el
//    proyecto agrega una sobrecarga.
//
//  - Se usan las llamadas de ACCESO DIRECTO AL ESTADO (glProgramUniform*),
//    coherentes con el estilo DSA del resto de los modulos. Reciben el
//    programa como argumento, asi que NO exigen haberlo activado antes.
//    "¿Que ocurre si se llama glUniform* sin haber activado el programa?"
//    glUniform* escribe sobre el programa ACTIVO, que puede ser otro o
//    ninguno: el valor se pierde o se le escribe a un tercero, sin error. La
//    falla es dificil de encontrar porque aparece lejos de su causa, y porque
//    funciona "de casualidad" cuando hay un solo shader.
//
//  - La consulta de la ubicacion devuelve -1 si el uniform NO EXISTE o si el
//    compilador de GLSL LO ELIMINO por no usarse, y pasar -1 no produce
//    ningun error: la llamada se IGNORA EN SILENCIO. Por eso el modulo avisa
//    -- una sola vez por nombre -- cuando una ubicacion sale -1.
//    Que un atributo declarado y no usado se elimine no es un error: el
//    compilador puede descartar todo lo que no afecta a la salida.
//
//  - DOS VERSIONES de los setters:
//      * por NOMBRE: comoda y legible, pero busca una cadena de texto dentro
//        del programa enlazado una vez por uniform y por cuadro, para obtener
//        siempre el mismo numero. Con 60 cuadros por segundo y varias piezas
//        son miles de busquedas de string por segundo.
//      * por UBICACION: se consulta UNA vez con loc() al crear el shader, se
//        guarda el entero y despues se usa ese.
//    "¿La ubicacion cambia alguna vez?" Es estable mientras el programa siga
//    siendo el mismo; deja de ser valida si el programa se RE-LINKEA (aca,
//    si se vuelve a llamar a compile_from_source()).
// ----------------------------------------------------------------------------

#pragma once

#include <string>

#include <glm/glm.hpp>

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

    // --- Uniform: version por NOMBRE (legible) ----------------------------
    void set_uniform(const std::string& nombre, const glm::mat4& m) const;
    void set_uniform(const std::string& nombre, const glm::vec3& v) const;
    void set_uniform(const std::string& nombre, const glm::vec4& v) const;
    void set_uniform(const std::string& nombre, float valor) const;

    // --- Uniform: version por UBICACION (para el bucle de dibujado) -------
    // Se consulta una vez con loc() y despues se usa el entero.
    // loc() devuelve -1 si el uniform no existe o fue eliminado, y avisa.
    int  loc(const std::string& nombre) const;
    void set_uniform(int ubicacion, const glm::mat4& m) const;
    void set_uniform(int ubicacion, const glm::vec3& v) const;
    void set_uniform(int ubicacion, const glm::vec4& v) const;
    void set_uniform(int ubicacion, float valor) const;

    // Se puede llamar dos veces sin romper nada: glDeleteProgram(0) no hace nada.
    void clear(void);

    unsigned int id(void) const { return id_; }

private:
    unsigned int id_ {0U};   // un entero, no cuatro
};
