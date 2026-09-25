// ----------------------------------------------------------------------------
// Mesh.cpp  -  Practico 02, Parte 1.
// Ver Mesh.h para las decisiones de diseño y su justificacion.
// ----------------------------------------------------------------------------

#include "Mesh.h"

#include <cstddef>      // offsetof
#include <utility>      // std::exchange

#include <glad/gl.h>


Mesh::~Mesh()
{
    clear();
}


Mesh::Mesh(Mesh&& other) noexcept
    : vao_(other.vao_), vbo_(other.vbo_), ebo_(other.ebo_),
      count_(other.count_)
{
    // Se anula el origen: sin esto los dos objetos liberarian lo mismo.
    other.vao_ = other.vbo_ = other.ebo_ = 0U;
    other.count_ = 0;
}


Mesh& Mesh::operator=(Mesh&& other) noexcept
{
    if (this != &other) {
        clear();                                   // suelta lo propio primero
        vao_   = std::exchange(other.vao_,   0U);
        vbo_   = std::exchange(other.vbo_,   0U);
        ebo_   = std::exchange(other.ebo_,   0U);
        count_ = std::exchange(other.count_, 0);
    }
    return *this;
}


void Mesh::load(const MeshData& data)
{
    clear();   // recargar no debe dejar huerfano lo anterior

    // --- VBO: los bytes de los vertices -------------------------------------
    glCreateBuffers(1, &vbo_);
    glNamedBufferData(vbo_,
                      static_cast<GLsizeiptr>(data.vertices.size() * sizeof(Vertex)),
                      data.vertices.data(),
                      GL_STATIC_DRAW);

    // --- EBO: los indices ---------------------------------------------------
    // Es un buffer mas: bytes sin tipo, igual que el VBO. El sentido de
    // "indices" se lo da la ranura dedicada del VAO a la que se conecta.
    glCreateBuffers(1, &ebo_);
    glNamedBufferData(ebo_,
                      static_cast<GLsizeiptr>(data.indices.size() * sizeof(unsigned int)),
                      data.indices.data(),
                      GL_STATIC_DRAW);

    // --- VAO: el instructivo de lectura de esos bytes -----------------------
    glCreateVertexArrays(1, &vao_);

    // El EBO se conecta por una ranura UNICA, sin indice, a diferencia de los
    // VBO que van a puntos de enlace numerados. Esa ranura es estado del VAO.
    glVertexArrayElementBuffer(vao_, ebo_);

    // Un solo buffer entrelazado en el punto de enlace 0; el stride es la
    // tupla entera.
    glVertexArrayVertexBuffer(vao_, 0, vbo_, 0,
                              static_cast<GLsizei>(sizeof(Vertex)));

    // Atributo 0: posicion. El offset se calcula, no se escribe a mano.
    glVertexArrayAttribFormat(vao_, 0, 3, GL_FLOAT, GL_FALSE,
                              offsetof(Vertex, px));
    glVertexArrayAttribBinding(vao_, 0, 0);
    glEnableVertexArrayAttrib(vao_, 0);

    // Atributo 1: color. Mismo buffer, mismo punto de enlace; lo unico que los
    // separa es el offset dentro de la tupla.
    glVertexArrayAttribFormat(vao_, 1, 3, GL_FLOAT, GL_FALSE,
                              offsetof(Vertex, r));
    glVertexArrayAttribBinding(vao_, 1, 0);
    glEnableVertexArrayAttrib(vao_, 1);

    count_ = static_cast<int>(data.indices.size());
}


void Mesh::clear(void)
{
    glDeleteVertexArrays(1, &vao_);   // glDelete*(0) es legal: no hace nada
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &ebo_);
    vao_ = vbo_ = ebo_ = 0U;
    count_ = 0;
}
