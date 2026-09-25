// ----------------------------------------------------------------------------
// Vertex.h  -  Practico 03, Parte 1.
//
// LA TUPLA CAMBIO respecto del Practico 02:
//
//     antes:  { posicion, color }
//     ahora:  { posicion, normal, coordenadas de textura }
//
//  - SALE el color. Deja de ser un atributo del vertice y pasa a ser un dato
//    del OBJETO: llega al fragment shader por otro camino (un uniform).
//    Tiene sentido: una pieza de color plano repetiria el mismo valor en
//    cientos o miles de vertices.
//  - ENTRA la normal: la direccion perpendicular a la superficie en el
//    vertice. Es el dato con el que se calcula el sombreado (Unidad IX).
//  - ENTRAN las coordenadas de textura (u,v): permiten mapear colores desde
//    una imagen en memoria.
//
// La normal y las coordenadas de textura SE CALCULAN Y SE GUARDAN aunque
// todavia no las use nadie. La iluminacion y las texturas entran mas adelante
// en la cursada.
//
// ----------------------------------------------------------------------------
// CONSECUENCIA SOBRE EL CONTEO DE VERTICES
//
// La regla no cambio -- un vertice se comparte si y solo si coinciden TODOS
// sus atributos -- pero al cambiar los atributos cambia el resultado:
//
//   - El CUBO sigue teniendo 24 vertices. Antes porque el color cambiaba en la
//     arista; ahora porque la NORMAL cambia en la arista (dos caras que se
//     tocan tienen normales distintas). Mismo numero, otro motivo.
//   - El LATERAL de un cilindro de 8 gajos pasa de 32 a 18. Antes cada gajo
//     tenia su color, asi que ningun gajo compartia con el vecino. Ahora la
//     normal varia de forma CONTINUA alrededor del eje, de modo que dos gajos
//     vecinos SI pueden compartir el borde. Quedan 2 anillos x (8+1) = 18.
//     El "+1" es la costura, y esta explicado en Primitives.h.
//
// ----------------------------------------------------------------------------
// RESPUESTA A LAS "CUESTIONES A PENSAR" DE LA GUIA (p.2)
//
//  - "Los desplazamientos de cada atributo, ¿se escribieron a mano en el
//     Practico 02 o se calculan? Esta es la migracion que responde aquella
//     pregunta."
//    Se calculan con offsetof(). Por eso esta migracion NO rompio nada: la
//    normal entro en el MEDIO de la tupla, justo el caso que dejaba mal un
//    offset escrito a mano (0 y 12), y lo hubiera dejado mal EN SILENCIO: sin
//    error de compilacion y sin error de OpenGL.
//
//  - "¿Cuantos lugares del codigo hubo que tocar para agregar un atributo?"
//    Dos, los mismos que se habian previsto en Mesh.h:
//       1. este struct;
//       2. el bloque de configuracion de atributos de Mesh::load().
//    El stride sigue saliendo de sizeof(Vertex) y los offsets de offsetof(),
//    asi que no se tocaron. (Y ademas el shader, que no es "codigo del
//    modulo" sino del programa.)
// ----------------------------------------------------------------------------

#pragma once

#include <glm/glm.hpp>

struct Vertex {              // Tupla de atributos para un vertice
    glm::vec3 position;      // Posicion
    glm::vec3 normal;        // Perpendicular a la superficie
    glm::vec2 tex_coords;    // Coordenadas de textura (u, v)
};
