// ----------------------------------------------------------------------------
// Primitives.h  -  Practico 03, Parte 2.
//
// Generacion PARAMETRICA de mallas. Ninguna coordenada se escribe a mano: los
// vertices se calculan dentro de un bucle a partir de pocos parametros, y la
// malla se regenera sola al cambiar cualquiera de ellos.
//
// Es, en terminos de la Unidad V, modelado matematico por BARRIDO: una seccion
// 2D (el anillo) barrida a lo largo de una trayectoria (el eje). El cilindro y
// el cono son superficies de revolucion, el caso particular del barrido
// alrededor de un eje.
//
// Ninguna funcion usa la API de OpenGL: son generadores de datos.
//
// ----------------------------------------------------------------------------
// DECISIONES TOMADAS
//
// 1. SISTEMA DE REFERENCIA DEL MODELO  (el paso 1 de la filmina, "importante!")
//    - Eje de revolucion = Y, como en el codigo de la filmina, donde la
//      posicion del anillo es { r*cos(th), y, r*sin(th) }.
//    - Las tres primitivas quedan CENTRADAS EN EL ORIGEN. Un modelo centrado
//      es mas facil de ubicar despues con una matriz de modelo que uno con el
//      origen en una esquina o en una tapa, y ademas rota sobre si mismo.
//      El cilindro va de y = -largo/2 a y = +largo/2; el cono, de y = -h/2
//      (base) a y = +h/2 (apice).
//
// 2. ANGULOS EN RADIANES.  La guia avisa que esta decision "tiene que quedar
//    documentada: es una fuente clasica de resultados que no se parecen a
//    nada". Se eligen radianes por coherencia con std::cos/std::sin y con glm,
//    que tambien trabaja en radianes. Para escribir grados en el programa esta
//    glm::radians().
//
// 3. EL CONO SE PARAMETRIZA POR EL ANGULO DE CONICIDAD, no por la altura, que
//    es lo que pide la guia. ¿Hace falta una funcion auxiliar que convierta una
//    en otra? Si, y esta abajo: cone_height(). La relacion es
//        tan(conicidad/2) = radio / altura   =>   altura = radio / tan(conicidad/2)
//    Hace falta porque quien arma la escena razona en alturas (que tan alto es
//    el cono), no en angulos de apertura, y porque la altura se necesita para
//    ubicar la pieza con la matriz de modelo.
//
// 4. CADA ANILLO LLEVA N+1 VERTICES Y NO N.  En la costura -- donde el ultimo
//    gajo se encuentra con el primero -- la POSICION y la NORMAL coinciden,
//    pero la coordenada de textura vale 0 y 1 a la vez. Un atributo difiere,
//    asi que el vertice hay que duplicarlo. Es la misma regla del cubo.
//    => El lateral de un cilindro de N gajos y dos anillos tiene 2(N+1)
//       vertices, que es la cuenta que la guia pide verificar.
//
//    "Si se quitaran las coordenadas de textura de la tupla, ¿cuantos vertices
//     tendria el lateral de un cilindro de N gajos? ¿Como cambiaria el bucle?"
//    Tendria N por anillo, no N+1: sin uv, en la costura coincidirian TODOS los
//    atributos y el vertice se podria compartir. El bucle iria de 0 a N-1 y
//    cerraria con el indice (i+1) % N en lugar de i+1.
//
// 5. LAS TAPAS NO COMPARTEN VERTICES CON EL LATERAL: su normal es AXIAL y la
//    del lateral es radial (o inclinada, en el cono). Un atributo difiere.
//    En cambio, el borde de la tapa SI cierra con N vertices y no con N+1:
//    con un mapeo de textura en disco, en la costura de la tapa coinciden
//    todos los atributos. La regla es un permiso, no una obligacion.
//
// 6. LA NORMAL DEL APICE DEL CONO no esta definida -- dependeria de que gajo se
//    mire -- asi que hay que tomar un criterio. Se adopta el de la filmina:
//    el apice NO comparte vertices con el lateral y su normal es AXIAL (0,1,0).
//    "Con ese criterio, ¿el apice es un vertice o son tantos como gajos?"
//    Son tantos como gajos: cada triangulo del abanico necesita su propio
//    vertice de apice para poder llevar su coordenada de textura.
//
// 7. WINDING: antihorario mirando la cara desde afuera, el mismo criterio
//    fijado en el Practico 02. DENTRO DE UN BUCLE ese orden deja de ser
//    evidente: el que sale natural al recorrer el cuadrilatero deja TODOS los
//    triangulos invertidos. Ver el comentario en Primitives.cpp.
// ----------------------------------------------------------------------------

#pragma once

#include "MeshData.h"

namespace primitives {

// Cubo indexado: 24 vertices unicos, 36 indices. Centrado en el origen.
// Con los valores por defecto es un cubo de lado unitario (l = 1).
// Devuelve la normal de cada cara: sigue teniendo 24 vertices porque la normal
// no es continua en las aristas.
MeshData cube(float sx = 1.0f, float sy = 1.0f, float sz = 1.0f);

// Cilindro de revolucion alrededor del eje Y, centrado en el origen, con tapas.
//   radio   : radio del cilindro
//   largo   : altura total (de -largo/2 a +largo/2)
//   gajos   : discretizacion diametral (N). Cada anillo lleva N+1 vertices.
//   anillos : discretizacion AXIAL, en cantidad de bandas. Con anillos = 1 hay
//             DOS anillos de vertices (abajo y arriba), que es el caso que la
//             guia usa para la cuenta 2(N+1). En general hay anillos+1 anillos
//             de vertices.
MeshData cylinder(float radio, float largo,
                  unsigned gajos, unsigned anillos = 1U);

// Cono de revolucion alrededor del eje Y, centrado en el origen, con tapa en
// la base. El apice queda en +h/2 y la base en -h/2.
//   radio     : radio de la base
//   conicidad : angulo de apertura completo, EN RADIANES
//   gajos     : discretizacion diametral (N)
//   anillos   : discretizacion axial de la superficie lateral, en bandas
MeshData cone(float radio, float conicidad,
              unsigned gajos, unsigned anillos = 1U);

// Auxiliar: altura de un cono a partir de su radio y su angulo de conicidad.
//     altura = radio / tan(conicidad / 2)
// Sirve para ubicar la pieza en la escena, donde se razona en alturas.
float cone_height(float radio, float conicidad);

// ----------------------------------------------------------------------------
// Verificacion del orden de los indices SIN DIBUJAR NADA (la que sugiere la
// guia, p.4). Para cada triangulo (A,B,C), el producto vectorial
// (B-A) x (C-A) tiene que apuntar para el mismo lado que la normal de sus
// vertices. Devuelve la cantidad de triangulos mal orientados: 0 es correcto.
//
// Hace falta porque el descarte de caras traseras esta DESHABILITADO: si el
// orden estuviera invertido, no se detectaria mirando la pantalla.
// ----------------------------------------------------------------------------
unsigned winding_invertidos(const MeshData& malla);

}  // namespace primitives
