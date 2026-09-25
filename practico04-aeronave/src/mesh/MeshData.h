// ----------------------------------------------------------------------------
// MeshData.h  -  Practico 03.
//
// Datos de malla del lado del CPU. Sigue siendo un dato, no un recurso: aca no
// hay nada de OpenGL. Lo producen los generadores de primitives y lo consume
// Mesh::load().
//
// Lo unico que cambio respecto del Practico 02 es el contenido de la tupla
// (ver Vertex.h); la forma de la malla -- dos listas -- es la misma.
// ----------------------------------------------------------------------------

#pragma once

#include <vector>

#include "Vertex.h"

struct MeshData {                          // Datos de malla del lado del CPU
    std::vector<Vertex>       vertices;    // Tuplas de cada vertice
    std::vector<unsigned int> indices;     // Orden de lectura para formar
                                           // los triangulos (cada 3, uno)
};
