// ----------------------------------------------------------------------------
// Primitives.cpp  -  Practico 03, Parte 2.
// Ver Primitives.h para las decisiones de diseño y su justificacion.
// ----------------------------------------------------------------------------

#include "Primitives.h"

#include <cmath>

#include <glm/geometric.hpp>     // glm::cross, glm::normalize, glm::dot

namespace {

constexpr float kPi = 3.14159265358979323846f;

// Agrega una cara plana de cuatro esquinas (el cubo). Las esquinas llegan en
// orden antihorario mirando la cara desde afuera; los dos triangulos se arman
// (0,1,2) y (0,2,3) sobre ese mismo orden y heredan el sentido.
void agregar_cara(MeshData& m,
                  const glm::vec3& a, const glm::vec3& b,
                  const glm::vec3& c, const glm::vec3& d,
                  const glm::vec3& normal)
{
    const unsigned int base = static_cast<unsigned int>(m.vertices.size());

    m.vertices.push_back({ a, normal, { 0.0f, 0.0f } });
    m.vertices.push_back({ b, normal, { 1.0f, 0.0f } });
    m.vertices.push_back({ c, normal, { 1.0f, 1.0f } });
    m.vertices.push_back({ d, normal, { 0.0f, 1.0f } });

    m.indices.insert(m.indices.end(), { base + 0U, base + 1U, base + 2U,
                                        base + 0U, base + 2U, base + 3U });
}

// Agrega una tapa circular como abanico de triangulos desde el centro.
//
// El borde lleva N vertices y NO N+1: con un mapeo de textura en disco, en la
// costura de la tapa coinciden todos los atributos y el vertice se comparte.
//
// hacia_arriba indica de que lado mira la normal axial; de eso depende el
// orden de los dos vertices del borde en cada triangulo.
void agregar_tapa(MeshData& m, float radio, float y, unsigned gajos,
                  bool hacia_arriba)
{
    const unsigned int base   = static_cast<unsigned int>(m.vertices.size());
    const glm::vec3    normal = hacia_arriba ? glm::vec3(0.0f,  1.0f, 0.0f)
                                             : glm::vec3(0.0f, -1.0f, 0.0f);

    // Centro del abanico.
    m.vertices.push_back({ { 0.0f, y, 0.0f }, normal, { 0.5f, 0.5f } });

    for (unsigned i = 0U; i < gajos; ++i) {
        const float th = 2.0f * kPi * static_cast<float>(i)
                                    / static_cast<float>(gajos);
        const float c = std::cos(th);
        const float s = std::sin(th);
        m.vertices.push_back({ { radio * c, y, radio * s },
                               normal,
                               { 0.5f + 0.5f * c, 0.5f + 0.5f * s } });
    }

    for (unsigned i = 0U; i < gajos; ++i) {
        const unsigned int centro = base;
        const unsigned int r0     = base + 1U + i;
        const unsigned int r1     = base + 1U + ((i + 1U) % gajos);
        if (hacia_arriba) {
            m.indices.insert(m.indices.end(), { centro, r1, r0 });
        } else {
            m.indices.insert(m.indices.end(), { centro, r0, r1 });
        }
    }
}

}  // namespace


namespace primitives {

// ----------------------------------------------------------------------------
MeshData cube(float sx, float sy, float sz)
{
    const float x = 0.5f * sx;
    const float y = 0.5f * sy;
    const float z = 0.5f * sz;

    const glm::vec3 nnn{ -x, -y, -z }, pnn{  x, -y, -z };
    const glm::vec3 ppn{  x,  y, -z }, npn{ -x,  y, -z };
    const glm::vec3 nnp{ -x, -y,  z }, pnp{  x, -y,  z };
    const glm::vec3 ppp{  x,  y,  z }, npp{ -x,  y,  z };

    MeshData m;
    m.vertices.reserve(24U);
    m.indices.reserve(36U);

    // Seis caras x 4 vertices = 24. La normal es constante en cada cara y
    // cambia en la arista: por eso las esquinas NO se comparten.
    agregar_cara(m, nnp, pnp, ppp, npp, {  0.0f,  0.0f,  1.0f });   // +Z
    agregar_cara(m, pnn, nnn, npn, ppn, {  0.0f,  0.0f, -1.0f });   // -Z
    agregar_cara(m, pnp, pnn, ppn, ppp, {  1.0f,  0.0f,  0.0f });   // +X
    agregar_cara(m, nnn, nnp, npp, npn, { -1.0f,  0.0f,  0.0f });   // -X
    agregar_cara(m, npp, ppp, ppn, npn, {  0.0f,  1.0f,  0.0f });   // +Y
    agregar_cara(m, nnn, pnn, pnp, nnp, {  0.0f, -1.0f,  0.0f });   // -Y

    return m;
}

// ----------------------------------------------------------------------------
MeshData cylinder(float radio, float largo, unsigned gajos, unsigned anillos)
{
    if (gajos < 3U)   { gajos = 3U; }     // con menos no hay superficie
    if (anillos < 1U) { anillos = 1U; }

    MeshData m;
    const unsigned int por_anillo = gajos + 1U;   // el +1 es la COSTURA

    // --- Paso 2: discretizar los anillos ------------------------------------
    for (unsigned a = 0U; a <= anillos; ++a) {
        const float v = static_cast<float>(a) / static_cast<float>(anillos);
        const float y = -0.5f * largo + v * largo;          // centrado en Y

        for (unsigned i = 0U; i <= gajos; ++i) {            // OJO: <= y no <
            const float th = 2.0f * kPi * static_cast<float>(i)
                                        / static_cast<float>(gajos);
            const float c = std::cos(th);
            const float s = std::sin(th);

            // La normal del lateral es RADIAL: sale de normalizar la posicion
            // con la componente axial (aca, la Y) en cero.
            m.vertices.push_back({ { radio * c, y, radio * s },
                                   { c, 0.0f, s },
                                   { static_cast<float>(i)
                                        / static_cast<float>(gajos), v } });
        }
    }

    // --- Paso 3: tira de cuadrilateros, dos triangulos cada uno -------------
    //
    // ATENCION AL ORDEN. El que sale natural al recorrer el cuadrilatero,
    // {b0, b1, t1}, deja la normal de TODOS los triangulos al reves. Se usa el
    // orden de la filmina, que da la normal hacia afuera:
    for (unsigned a = 0U; a < anillos; ++a) {
        const unsigned int fila_b = a * por_anillo;
        const unsigned int fila_t = (a + 1U) * por_anillo;

        for (unsigned i = 0U; i < gajos; ++i) {
            const unsigned int b0 = fila_b + i,  b1 = fila_b + i + 1U;
            const unsigned int t0 = fila_t + i,  t1 = fila_t + i + 1U;

            m.indices.insert(m.indices.end(), { b0, t1, b1 });
            m.indices.insert(m.indices.end(), { b0, t0, t1 });
        }
    }

    // --- Tapas: normal axial, no comparten vertices con el lateral ----------
    agregar_tapa(m, radio, -0.5f * largo, gajos, false);   // abajo  (-Y)
    agregar_tapa(m, radio,  0.5f * largo, gajos, true);    // arriba (+Y)

    return m;
}

// ----------------------------------------------------------------------------
float cone_height(float radio, float conicidad)
{
    return radio / std::tan(0.5f * conicidad);
}

// ----------------------------------------------------------------------------
MeshData cone(float radio, float conicidad, unsigned gajos, unsigned anillos)
{
    if (gajos < 3U)   { gajos = 3U; }
    if (anillos < 1U) { anillos = 1U; }

    const float altura = cone_height(radio, conicidad);
    const float y_base = -0.5f * altura;
    const float y_ap   =  0.5f * altura;

    // Semiangulo de la conicidad: con el se inclina la normal del lateral.
    const float cos_semi = std::cos(0.5f * conicidad);
    const float sin_semi = std::sin(0.5f * conicidad);

    MeshData m;
    const unsigned int por_anillo = gajos + 1U;

    // --- Anillos del lateral. El radio decrece linealmente hasta el apice ---
    // Se generan anillos+1 filas; la ultima tiene radio 0 pero NO se usa como
    // apice: el apice va aparte, con su propia normal (ver abajo).
    for (unsigned a = 0U; a < anillos; ++a) {
        const float v = static_cast<float>(a) / static_cast<float>(anillos);
        const float y = y_base + v * altura;
        const float r = radio * (1.0f - v);

        for (unsigned i = 0U; i <= gajos; ++i) {
            const float th = 2.0f * kPi * static_cast<float>(i)
                                        / static_cast<float>(gajos);
            const float c = std::cos(th);
            const float s = std::sin(th);

            // La normal del lateral NO es radial: esta inclinada por el
            // semiangulo de la conicidad.
            m.vertices.push_back({ { r * c, y, r * s },
                                   { c * cos_semi, sin_semi, s * cos_semi },
                                   { static_cast<float>(i)
                                        / static_cast<float>(gajos), v } });
        }
    }

    // Bandas intermedias (si anillos > 1): mismo criterio que el cilindro.
    for (unsigned a = 0U; a + 1U < anillos; ++a) {
        const unsigned int fila_b = a * por_anillo;
        const unsigned int fila_t = (a + 1U) * por_anillo;
        for (unsigned i = 0U; i < gajos; ++i) {
            const unsigned int b0 = fila_b + i,  b1 = fila_b + i + 1U;
            const unsigned int t0 = fila_t + i,  t1 = fila_t + i + 1U;
            m.indices.insert(m.indices.end(), { b0, t1, b1 });
            m.indices.insert(m.indices.end(), { b0, t0, t1 });
        }
    }

    // --- Apice: TANTOS VERTICES COMO GAJOS, con normal AXIAL ----------------
    // Criterio de la filmina: el apice no comparte vertices con el lateral.
    // Cada triangulo del abanico necesita el suyo para llevar su coordenada
    // de textura.
    const unsigned int fila_ult = (anillos - 1U) * por_anillo;
    const unsigned int base_ap  = static_cast<unsigned int>(m.vertices.size());

    for (unsigned i = 0U; i < gajos; ++i) {
        const float u = (static_cast<float>(i) + 0.5f)
                        / static_cast<float>(gajos);
        m.vertices.push_back({ { 0.0f, y_ap, 0.0f },
                               { 0.0f, 1.0f, 0.0f },      // axial
                               { u, 1.0f } });
    }

    for (unsigned i = 0U; i < gajos; ++i) {
        const unsigned int b0 = fila_ult + i;
        const unsigned int b1 = fila_ult + i + 1U;
        // Mismo criterio que el cilindro con el anillo de arriba colapsado.
        m.indices.insert(m.indices.end(), { b0, base_ap + i, b1 });
    }

    // --- Tapa de la base ----------------------------------------------------
    agregar_tapa(m, radio, y_base, gajos, false);

    return m;
}

// ----------------------------------------------------------------------------
unsigned winding_invertidos(const MeshData& malla)
{
    unsigned malos = 0U;

    for (std::size_t k = 0U; k + 2U < malla.indices.size(); k += 3U) {
        const Vertex& A = malla.vertices[malla.indices[k + 0U]];
        const Vertex& B = malla.vertices[malla.indices[k + 1U]];
        const Vertex& C = malla.vertices[malla.indices[k + 2U]];

        const glm::vec3 geom = glm::cross(B.position - A.position,
                                          C.position - A.position);

        // La normal de los vertices del triangulo, promediada: alcanza para
        // decidir de que lado esta.
        const glm::vec3 prom = A.normal + B.normal + C.normal;

        // Si apuntan para lados opuestos, el triangulo esta invertido.
        if (glm::dot(geom, prom) <= 0.0f) {
            ++malos;
        }
    }
    return malos;
}

}  // namespace primitives
