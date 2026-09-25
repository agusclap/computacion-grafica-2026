// ----------------------------------------------------------------------------
// MeshData.h  -  Practico 02.
//
// Datos de malla del lado del CPU. Es un dato, no un recurso: aca no hay nada
// de OpenGL. Lo produce el modulo primitives y lo consume Mesh::load().
//
// Un VERTICE no es una coordenada: es la TUPLA COMPLETA de atributos que recibe
// el vertex shader en cada invocacion. De ahi sale la regla que decide cuantos
// vertices tiene una malla:
//
//     un vertice se comparte si y solo si coinciden TODOS sus atributos.
//
// Por eso el cubo de este practico tiene 24 vertices y no 8: cada esquina
// geometrica pertenece a tres caras, y cada cara lleva un color distinto, asi
// que un atributo difiere y el vertice hay que duplicarlo.
// ----------------------------------------------------------------------------

#pragma once

#include <vector>

struct Vertex {         // Tupla de atributos para un vertice
    float px, py, pz;   // Posicion
    float r,  g,  b;    // Color
};

struct MeshData {                          // Datos de malla del lado del CPU
    std::vector<Vertex>       vertices;    // Tuplas de cada vertice
    std::vector<unsigned int> indices;     // Orden de lectura para formar
                                           // los triangulos (cada 3, uno)
};
