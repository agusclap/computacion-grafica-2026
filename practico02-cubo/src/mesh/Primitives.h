// ----------------------------------------------------------------------------
// Primitives.h  -  Practico 02, Parte 3.
//
// Generador de mallas de figuras primitivas. Los 24 vertices del cubo NO se
// escriben a mano en el main: se obtienen por medio de una funcion.
//
// Hoy tiene una sola primitiva; en el proximo practico se le agregan el cono y
// el cilindro, y mas adelante pueden sumarse otras (disco, quad, triangulo).
//
// ----------------------------------------------------------------------------
// DECISIONES TOMADAS  (las "cuestiones a pensar" de la guia, p.3)
//
//  - FUNCION LIBRE en un namespace, no una clase. La pregunta de la clase del
//    practico -- ¿que POSEE este objeto? -- tiene aca una respuesta clara:
//    nada. No hay estado que administrar ni recurso que liberar; es una
//    funcion pura que recibe medidas y devuelve datos. Una clase sin estado
//    solo agregaria ceremonia.
//
//  - NO USA LA API DE OpenGL. Es un generador de datos: devuelve MeshData y no
//    sabe que existe la GPU. Quien sube esos datos es Mesh::load().
//
//  - LOS COLORES QUEDAN FIJOS adentro del generador, escritos a mano, uno por
//    cara. Es lo que pide el practico. Cuando en el Practico 03 el color deje
//    de ser un atributo del vertice y pase a ser un dato del objeto (un
//    uniform), estos colores desaparecen de aca: por eso no conviene invertir
//    ahora en pasarlos por parametro.
//
//  - EL CUBO QUEDA CENTRADO EN EL ORIGEN, no apoyado sobre el plano y = 0.
//    Motivo: es la figura la que se rota en este practico, y rotar alrededor
//    del centro del propio cuerpo es lo que se quiere ver. Ademas, un modelo
//    centrado es mas facil de ubicar despues con una matriz de modelo
//    (Practico 03) que uno con el origen en una esquina.
//
//  - WINDING: las cuatro esquinas de cada cara se recorren SIEMPRE en el mismo
//    sentido, ANTIHORARIO MIRANDO LA CARA DESDE AFUERA. El criterio se fija
//    ahora y no se cambia: de el depende el descarte de caras traseras que se
//    ve mas adelante en el teorico (Unidad VIII) y que decide que cara se
//    dibuja y cual no. Hoy GL_CULL_FACE esta apagado, asi que un winding
//    invertido NO daria ningun sintoma.
//
//  - SOBRE LA FIRMA, pensando en la ampliacion: cube() se parametriza por sus
//    tres escalas porque un cubo es una caja. Un cilindro no se describe asi
//    -- necesita radio, largo y cantidad de gajos -- de modo que cylinder() y
//    cone() van a tener su propia firma. Eso no obliga a reescribir el modulo:
//    lo que se comparte es el tipo de retorno (MeshData) y el criterio de
//    winding, no la lista de parametros.
// ----------------------------------------------------------------------------

#pragma once

#include "MeshData.h"

namespace primitives {

// Cubo indexado: 24 vertices unicos, 36 indices, un color plano por cara.
// Centrado en el origen. Con los valores por defecto es un cubo de lado
// unitario (l = 1), es decir que se extiende de -0.5 a +0.5 en cada eje.
// Con escalas distintas por eje se obtienen otras figuras de caras rectas
// paralelas (por ejemplo una placa).
MeshData cube(float scale_x = 1.0f,
              float scale_y = 1.0f,
              float scale_z = 1.0f);

}  // namespace primitives
