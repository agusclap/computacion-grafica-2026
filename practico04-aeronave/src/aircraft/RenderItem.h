// ----------------------------------------------------------------------------
// RenderItem.h  -  Practico 04, Parte 1.
//
// Una UNIDAD DE DIBUJADO: todo lo que el bucle de dibujado necesita saber para
// emitir una llamada, y nada mas. Es el mismo struct 'Pieza' del Practico 03
// ascendido a tipo propio, porque ahora hay ocho y las arma otra clase.
//
// ----------------------------------------------------------------------------
// DECISIONES TOMADAS
//
// 1. GUARDA UN PUNTERO A LA MALLA, NO UNA MALLA.
//    Mesh es dueño unico de sus tres objetos de OpenGL y por eso tiene la copia
//    prohibida (Practico 02): un RenderItem que contuviera un Mesh no se podria
//    meter en un std::vector. Pero ademas seria un error de diseño aunque se
//    pudiera: la gracia del practico es que OCHO PIEZAS COMPARTEN TRES MALLAS.
//    Las dos alas son la misma geometria en la GPU vista con dos matrices
//    distintas; duplicar el VBO seria desperdiciar memoria de video para no
//    obtener nada.
//
//    ¿Puntero o referencia? Puntero. Un std::vector exige elementos asignables
//    y una referencia no se puede reasignar despues de construida.
//
//    ¿Puntero a const? Si: dibujar no modifica la malla, solo le pide el VAO y
//    la cantidad de indices. Que el tipo lo diga documenta la intencion.
//
//    El puntero NO ES DUEÑO: no libera nada. El dueño de las mallas es la clase
//    Aircraft, que las mantiene vivas mientras existan los items que apuntan a
//    ellas. Es la contracara de la regla del Practico 02: quien no es dueño, no
//    destruye.
//
// 2. GUARDA LA MATRIZ DE MUNDO YA COMPUESTA, NO LOS INGREDIENTES.
//    El item no lleva posicion, ni angulos, ni escala por separado: lleva la
//    mat4 final. El bucle de dibujado no tiene que saber COMO se llego a esa
//    matriz -- si viene de una pose, de una jerarquia o de una animacion --,
//    solo tiene que escribirla en el uniform. Componer es trabajo de Aircraft.
//
// 3. EL COLOR VIAJA EN EL ITEM Y NO EN LA MALLA.
//    Si el color fuera un atributo de vertice (como en el Practico 02), dos
//    piezas de distinto color no podrian compartir malla, que es justo lo que
//    este practico quiere. Como uniform, el color es una propiedad DE LA PIEZA
//    y la geometria queda libre de reutilizarse.
//    Se usa vec4 y no vec3 porque el cuarto canal (alfa) es el lugar natural
//    para la transparencia cuando aparezca; declararlo ahora no cuesta nada.
// ----------------------------------------------------------------------------

#pragma once

#include <glm/glm.hpp>

#include "mesh/Mesh.h"

struct RenderItem {
	const Mesh* mesh  {nullptr};        // NO es dueño: no libera nada
	glm::mat4   model {1.0f};           // matriz de MUNDO, ya compuesta
	glm::vec4   color {1.0f};           // propiedad de la pieza, no de la malla
};
