// ----------------------------------------------------------------------------
// Mesh.h  -  Practico 02, Parte 1.
//
// Administra los tres objetos de OpenGL que hacen falta para dibujar una malla
// indexada: el VAO, el VBO y el EBO.
//
// ----------------------------------------------------------------------------
// POR QUE ESTA CLASE EXISTE
//
// Los tres objetos se manejan por NOMBRES: enteros que apuntan a memoria que
// vive en la GPU. De ahi salen los dos hechos que mandan:
//
//   - copiar el entero NO copia el objeto;
//   - perder el entero NO lo libera: lo deja huerfano hasta que se cierra el
//     contexto.
//
// Es decir, el entero es un recurso con dueño, y C++ ya tiene la herramienta
// para eso. De ahi las TRES DECISIONES de la interfaz:
//
//   1. El DESTRUCTOR libera.  Ningun glDelete* vive fuera de esta clase.
//   2. La COPIA esta prohibida.  Copiar duplicaria el entero pero no el objeto:
//      los dos Mesh creerian ser dueños y los dos destructores liberarian lo
//      mismo. Peor todavia: OpenGL reutiliza los nombres liberados, asi que la
//      segunda liberacion podria destruir un VAO ajeno que todavia se usa.
//   3. El MOVIMIENTO esta permitido: traspasa la propiedad y deja el origen en
//      CERO. El cero es lo que hace que el traspaso sea real, porque
//      glDelete*(0) es legal y no hace nada: el destructor del objeto vaciado
//      corre igual y no rompe nada.
//
// ----------------------------------------------------------------------------
// OTRAS DECISIONES  (las "cuestiones a pensar" de la guia, p.2)
//
//  - count_ guarda la cantidad de INDICES, no de vertices, porque es lo que
//    necesita glDrawElements() como segundo argumento.
//    Si mas adelante se quisiera dibujar una malla NO indexada habria que
//    distinguir los dos numeros: lo natural seria guardar ambos y que el
//    modulo decida entre glDrawElements y glDrawArrays segun haya EBO o no.
//    Hoy no se hace porque todas las primitivas del proyecto son indexadas.
//
//  - Los desplazamientos de cada atributo dentro de la tupla se CALCULAN con
//    offsetof(), no se escriben a mano (0 y 12). El dia que la tupla lleve la
//    normal en el medio -- que es exactamente lo que pasa en el Practico 03 --
//    los numeros escritos a mano quedarian mal en silencio, sin error de
//    compilacion y sin error de OpenGL.
//
//  - Si mañana el vertice tuviera un atributo mas, hay que tocar DOS lugares:
//    el struct Vertex (MeshData.h) y el bloque de configuracion de atributos
//    de Mesh::load(). El stride sale solo de sizeof(Vertex) y los offsets de
//    offsetof(), asi que esos no se tocan.
// ----------------------------------------------------------------------------

#pragma once

#include "MeshData.h"

class Mesh {
public:
    Mesh() = default;
    ~Mesh();                                   // libera lo que posee

    Mesh(const Mesh&)            = delete;     // copiar rompe el dueño unico
    Mesh& operator=(const Mesh&) = delete;

    Mesh(Mesh&& other) noexcept;               // mover: traspasa la propiedad
    Mesh& operator=(Mesh&& other) noexcept;

    // Sube las dos listas a la GPU y arma el VAO. Si ya habia algo cargado, lo
    // libera antes (load() dos veces no deja el anterior huerfano).
    void load(const MeshData& data);

    // Libera los tres objetos. Se puede llamar dos veces sin romper nada y sin
    // banderas auxiliares: glDelete*(0) es legal y no hace nada.
    void clear(void);

    unsigned int vao(void) const   { return vao_; }
    int          count(void) const { return count_; }   // cantidad de INDICES

private:
    unsigned int vao_ {0U}, vbo_ {0U}, ebo_ {0U};
    int          count_ {0};
};
