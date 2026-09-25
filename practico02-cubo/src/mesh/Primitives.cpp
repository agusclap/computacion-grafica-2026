// ----------------------------------------------------------------------------
// Primitives.cpp  -  Practico 02, Parte 3.
// Ver Primitives.h para las decisiones de diseño y su justificacion.
// ----------------------------------------------------------------------------

#include "Primitives.h"

namespace {

struct Color { float r, g, b; };

// Agrega una cara: cuatro esquinas del mismo color y los dos triangulos que la
// forman.
//
// Las esquinas llegan en orden ANTIHORARIO MIRANDO LA CARA DESDE AFUERA, y los
// dos triangulos se arman (0,1,2) y (0,2,3) sobre ese mismo orden, con lo que
// heredan el sentido. Es el unico lugar del modulo donde se decide el winding.
void agregar_cara(MeshData& malla,
                  const float a[3], const float b[3],
                  const float c[3], const float d[3],
                  const Color& color)
{
    const unsigned int base = static_cast<unsigned int>(malla.vertices.size());

    for (const float* v : { a, b, c, d }) {
        malla.vertices.push_back(Vertex{ v[0], v[1], v[2],
                                         color.r, color.g, color.b });
    }

    malla.indices.insert(malla.indices.end(),
                         { base + 0U, base + 1U, base + 2U,
                           base + 0U, base + 2U, base + 3U });
}

}  // namespace


namespace primitives {

MeshData cube(float scale_x, float scale_y, float scale_z)
{
    // Centrado en el origen: cada semiarista es la mitad de la escala. Con la
    // escala por defecto (1.0) el cubo va de -0.5 a +0.5 y tiene lado 1.
    const float x = 0.5f * scale_x;
    const float y = 0.5f * scale_y;
    const float z = 0.5f * scale_z;

    // Las ocho esquinas geometricas. Cada una va a aparecer en TRES caras, y
    // como cada cara lleva un color distinto, un atributo difiere: por eso el
    // cubo termina con 24 vertices y no con 8.
    const float nnn[3] = { -x, -y, -z };
    const float pnn[3] = {  x, -y, -z };
    const float ppn[3] = {  x,  y, -z };
    const float npn[3] = { -x,  y, -z };
    const float nnp[3] = { -x, -y,  z };
    const float pnp[3] = {  x, -y,  z };
    const float ppp[3] = {  x,  y,  z };
    const float npp[3] = { -x,  y,  z };

    // Un color plano distinto por cara, escrito a mano.
    const Color rojo     { 0.90f, 0.25f, 0.25f };
    const Color cian     { 0.25f, 0.75f, 0.80f };
    const Color verde    { 0.35f, 0.75f, 0.35f };
    const Color amarillo { 0.95f, 0.80f, 0.25f };
    const Color azul     { 0.30f, 0.45f, 0.85f };
    const Color violeta  { 0.65f, 0.40f, 0.80f };

    MeshData malla;
    malla.vertices.reserve(24U);
    malla.indices.reserve(36U);

    // Seis caras x 4 vertices = 24 vertices unicos.
    // Seis caras x 2 triangulos x 3 = 36 indices.
    agregar_cara(malla, nnp, pnp, ppp, npp, rojo);      // frente  (+Z)
    agregar_cara(malla, pnn, nnn, npn, ppn, cian);      // atras   (-Z)
    agregar_cara(malla, pnp, pnn, ppn, ppp, verde);     // derecha (+X)
    agregar_cara(malla, nnn, nnp, npp, npn, amarillo);  // izq.    (-X)
    agregar_cara(malla, npp, ppp, ppn, npn, azul);      // arriba  (+Y)
    agregar_cara(malla, nnn, pnn, pnp, nnp, violeta);   // abajo   (-Y)

    return malla;
}

}  // namespace primitives
