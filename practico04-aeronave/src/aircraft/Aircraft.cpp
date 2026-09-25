// ----------------------------------------------------------------------------
// Aircraft.cpp  -  Practico 04, Partes 2 y 3.
// Ver Aircraft.h para el despiece, el sistema de referencia y las decisiones.
// ----------------------------------------------------------------------------

#include "aircraft/Aircraft.h"

#include <cmath>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>   // translate, rotate, scale

#include "mesh/Primitives.h"

namespace {

// ----------------------------------------------------------------------------
// LAS MEDIDAS DEL DESPIECE
//
// Todo esta en unidades de LARGO DE FUSELAJE (L_f = 1), leido de las tres
// vistas de la guia. Ninguna coordenada se repite a mano mas abajo: las
// posiciones de las piezas se DERIVAN de estas constantes, asi que cambiar el
// largo de la nariz reubica la nariz sola.
// ----------------------------------------------------------------------------

constexpr float kRadioFuselaje = 0.065f;   // radio del tubo central

// Reparto del eje Z. La nariz arranca en 0 (el origen del modelo).
constexpr float kLargoNariz  = 0.190f;                    // z: 0.000 -> 0.190
constexpr float kLargoCola   = 0.180f;                    // z: 0.820 -> 1.000
constexpr float kZFinNariz   = kLargoNariz;
constexpr float kZIniCola    = 1.0f - kLargoCola;
constexpr float kLargoTubo   = kZIniCola - kZFinNariz;    // 0.630

// Ala. Envergadura total = 0.90 * L_f, que es la proporcion del S-211
// (8.43 m de envergadura contra 9.31 m de largo = 0.905).
constexpr float kSemiEnvergadura = 0.450f;                // punta del ala en x
constexpr float kCuerdaAla       = 0.240f;                // extension en z
constexpr float kEspesorAla      = 0.020f;                // extension en y
constexpr float kZAla            = 0.560f;                // centro de la cuerda

// Estabilizador horizontal, en la cola.
constexpr float kSemiEnvEstab = 0.190f;
constexpr float kCuerdaEstab  = 0.120f;
constexpr float kEspesorEstab = 0.016f;
constexpr float kZEstab       = 0.900f;
constexpr float kYEstab       = 0.030f;

// Deriva (estabilizador vertical).
constexpr float kAlturaDeriva  = 0.170f;
constexpr float kCuerdaDeriva  = 0.160f;
constexpr float kEspesorDeriva = 0.016f;
constexpr float kZDeriva       = 0.895f;
constexpr float kYBaseDeriva   = 0.030f;

constexpr float kMedioPi = 1.57079632679489661923f;   // 90 grados en radianes

// Colores. Los dos lados llevan colores DISTINTOS a proposito: mientras la
// aeronave rota es la unica forma de ver a simple vista que el ala que sube es
// la de estribor y no la de babor. Si los dos fueran iguales, una rotacion y su
// opuesta se verian igual y la verificacion de la Parte 3 no probaria nada.
constexpr glm::vec4 kColFuselaje {0.80f, 0.82f, 0.86f, 1.0f};   // gris claro
constexpr glm::vec4 kColNariz    {0.22f, 0.24f, 0.30f, 1.0f};   // radomo oscuro
constexpr glm::vec4 kColCola     {0.55f, 0.58f, 0.65f, 1.0f};   // gris medio
constexpr glm::vec4 kColAlaDer   {0.88f, 0.30f, 0.26f, 1.0f};   // rojo
constexpr glm::vec4 kColAlaIzq   {0.26f, 0.48f, 0.90f, 1.0f};   // azul
constexpr glm::vec4 kColEstabDer {0.95f, 0.62f, 0.22f, 1.0f};   // naranja
constexpr glm::vec4 kColEstabIzq {0.30f, 0.76f, 0.78f, 1.0f};   // celeste
constexpr glm::vec4 kColDeriva   {0.92f, 0.85f, 0.35f, 1.0f};   // amarillo

// Matriz local de una PLACA: un cubo unitario estirado a (sx, sy, sz) y
// llevado a (x, y, z). No lleva rotacion: el cubo ya viene alineado con los
// ejes, asi que basta elegir que eje es el espesor.
//
// OJO CON EL ORDEN EN GLM: cada llamada multiplica por derecha, asi que la
// ULTIMA que se escribe es la PRIMERA que se aplica. Escribir translate y
// despues scale da M = T * S, o sea escalar primero y ubicar despues -- que es
// lo que se quiere. Al reves, la traslacion tambien se escalaria.
glm::mat4 placa(const glm::vec3& centro, const glm::vec3& medidas)
{
	glm::mat4 m(1.0f);
	m = glm::translate(m, centro);
	m = glm::scale(m, medidas);
	return m;
}

// Informe de una malla recien generada, con la verificacion de winding del
// Practico 03. Devuelve true si la malla esta sana.
bool informar(const char* nombre, const MeshData& d)
{
	const unsigned malos = primitives::winding_invertidos(d);

	std::cout << "  " << nombre
	          << "  vertices: " << d.vertices.size()
	          << "   indices: " << d.indices.size()
	          << "   triangulos: " << d.indices.size() / 3U
	          << "   winding invertidos: " << malos << std::endl;

	return malos == 0U;
}

}  // namespace


// ----------------------------------------------------------------------------
bool Aircraft::init(unsigned gajos)
{
	// --- Las TRES mallas, generadas una sola vez ---------------------------
	//
	// El cono se genera con la conicidad que le da EXACTAMENTE la altura de la
	// nariz. La primitiva se parametriza por angulo, no por altura, asi que la
	// conversion va al reves de cone_height():
	//     altura = radio / tan(conicidad/2)  =>  conicidad = 2*atan(radio/altura)
	const float conicidad = 2.0f * std::atan(kRadioFuselaje / kLargoNariz);

	const MeshData d_cil  = primitives::cylinder(kRadioFuselaje, kLargoTubo,
	                                             gajos);
	const MeshData d_cono = primitives::cone(kRadioFuselaje, conicidad, gajos);
	const MeshData d_cubo = primitives::cube();

	std::cout << "Mallas de la aeronave (gajos = " << gajos << "):" << std::endl;
	bool sanas = true;
	sanas &= informar("cilindro", d_cil);
	sanas &= informar("cono    ", d_cono);
	sanas &= informar("cubo    ", d_cubo);

	if (!sanas) {
		std::cout << "Aircraft: alguna malla tiene triangulos invertidos."
		          << std::endl;
		return false;
	}

	malla_cilindro_.load(d_cil);
	malla_cono_.load(d_cono);
	malla_cubo_.load(d_cubo);

	// La altura real del cono generado. Sale igual a kLargoNariz por como se
	// eligio la conicidad, pero se recalcula en vez de suponerlo: si mañana
	// cambia la formula de la primitiva, esto sigue estando bien.
	const float h_cono = primitives::cone_height(kRadioFuselaje, conicidad);

	piezas_.clear();
	piezas_.reserve(8U);

	// ------------------------------------------------------------------
	// 1. FUSELAJE CENTRAL  --  cilindro
	//
	// El cilindro del Practico 03 nace centrado en el origen y con el eje en
	// Y. Hay que pararlo sobre Z y correrlo hasta el centro del tubo.
	// No lleva escala: radio y largo son PARAMETROS de la primitiva, asi que
	// la malla ya tiene el tamaño final. Es la pieza donde la pregunta de las
	// normales bajo escala no uniforme directamente no se plantea.
	// ------------------------------------------------------------------
	{
		glm::mat4 m(1.0f);
		m = glm::translate(m, glm::vec3(0.0f, 0.0f,
		                                kZFinNariz + 0.5f * kLargoTubo));
		m = glm::rotate(m, -kMedioPi, glm::vec3(1.0f, 0.0f, 0.0f));
		piezas_.push_back({ &malla_cilindro_, m, kColFuselaje,
		                    "fuselaje central" });
	}

	// ------------------------------------------------------------------
	// 2. NARIZ  --  cono, apice hacia -Z (hacia adelante)
	//
	// El cono nace con el apice en +Y. Una rotacion de -90 grados en X manda
	// +Y a -Z:  Rx(-90) * (0,1,0) = (0,0,-1).  El cono esta centrado en su
	// propia altura, asi que su centro va a la mitad del tramo de nariz.
	// Escala: ninguna. La conicidad se eligio para que la altura ya sea la
	// buena.
	// ------------------------------------------------------------------
	{
		glm::mat4 m(1.0f);
		m = glm::translate(m, glm::vec3(0.0f, 0.0f, 0.5f * h_cono));
		m = glm::rotate(m, -kMedioPi, glm::vec3(1.0f, 0.0f, 0.0f));
		piezas_.push_back({ &malla_cono_, m, kColNariz, "nariz" });
	}

	// ------------------------------------------------------------------
	// 3. COLA  --  el MISMO cono, apice hacia +Z (hacia atras)
	//
	// Rx(+90) manda +Y a +Z. La cola es algo mas corta que la nariz, y esa
	// diferencia se resuelve con una escala UNIFORME: el factor sale de la
	// razon de alturas, y al ser uniforme no rompe las normales ni el winding
	// (determinante positivo). Reducir tambien el radio de la base es el
	// efecto lateral, y ademas es lo que se ve en la vista lateral de la guia:
	// la cola afina.
	// ------------------------------------------------------------------
	{
		const float k = kLargoCola / h_cono;     // < 1
		glm::mat4 m(1.0f);
		m = glm::translate(m, glm::vec3(0.0f, 0.0f,
		                                kZIniCola + 0.5f * kLargoCola));
		m = glm::rotate(m, kMedioPi, glm::vec3(1.0f, 0.0f, 0.0f));
		m = glm::scale(m, glm::vec3(k));
		piezas_.push_back({ &malla_cono_, m, kColCola, "cola" });
	}

	// ------------------------------------------------------------------
	// 4 y 5. ALAS  --  el mismo cubo, escalado a placa
	//
	// El centro de cada ala se pone a mitad de camino entre el costado del
	// fuselaje y la punta: asi la raiz del ala queda METIDA dentro del tubo y
	// no se ve una juntura al aire.
	//
	// El ala izquierda NO usa escala negativa: es la misma placa TRASLADADA a
	// x negativo. Una escala negativa invertiria el winding (ver Aircraft.h).
	// ------------------------------------------------------------------
	{
		// La placa va del EJE del modelo (x = 0) a la punta: asi la raiz
		// queda enteramente dentro del tubo y no se ve una juntura al aire.
		const glm::vec3 medidas(kSemiEnvergadura, kEspesorAla, kCuerdaAla);
		const float x_centro = 0.5f * kSemiEnvergadura;
		const float y = -0.5f * kEspesorAla;   // ala baja, colgada del fuselaje

		piezas_.push_back({ &malla_cubo_,
		                    placa({  x_centro, y, kZAla }, medidas),
		                    kColAlaDer, "ala derecha" });
		piezas_.push_back({ &malla_cubo_,
		                    placa({ -x_centro, y, kZAla }, medidas),
		                    kColAlaIzq, "ala izquierda" });
	}

	// ------------------------------------------------------------------
	// 6 y 7. ESTABILIZADORES HORIZONTALES  --  el mismo cubo, mas chico
	// ------------------------------------------------------------------
	{
		const glm::vec3 medidas(kSemiEnvEstab, kEspesorEstab, kCuerdaEstab);
		const float x_centro = 0.5f * kSemiEnvEstab;

		piezas_.push_back({ &malla_cubo_,
		                    placa({  x_centro, kYEstab, kZEstab }, medidas),
		                    kColEstabDer, "estab. horiz. derecho" });
		piezas_.push_back({ &malla_cubo_,
		                    placa({ -x_centro, kYEstab, kZEstab }, medidas),
		                    kColEstabIzq, "estab. horiz. izquierdo" });
	}

	// ------------------------------------------------------------------
	// 8. DERIVA  --  el mismo cubo, parado
	//
	// Misma placa con los papeles de los ejes cambiados: lo que en el ala era
	// envergadura (X) aca es espesor, y lo que era espesor (Y) aca es altura.
	// No hace falta rotarla: alcanza con permutar las medidas de la escala.
	// La base se hunde un poco en el fuselaje por el mismo motivo que las alas.
	// ------------------------------------------------------------------
	{
		const glm::vec3 medidas(kEspesorDeriva, kAlturaDeriva, kCuerdaDeriva);
		const float y_centro = kYBaseDeriva + 0.5f * kAlturaDeriva;
		piezas_.push_back({ &malla_cubo_,
		                    placa({ 0.0f, y_centro, kZDeriva }, medidas),
		                    kColDeriva, "deriva" });
	}

	update(glm::vec3(0.0f), glm::vec3(0.0f));   // pose neutra de arranque
	return !piezas_.empty();
}


// ----------------------------------------------------------------------------
void Aircraft::update(const glm::vec3& posicion, const glm::vec3& angulos)
{
	// M_pose = T(posicion) * R(angulos) * T(-ref)
	//
	// Leida de DERECHA A IZQUIERDA, que es el orden en que se aplica:
	//   1) T(-ref)      lleva el punto de referencia al origen
	//   2) R(angulos)   rota ahi, o sea ALREDEDOR DEL PUNTO DE REFERENCIA
	//   3) T(posicion)  lleva el conjunto a su lugar en el mundo
	//
	// En glm se escribe al reves: cada llamada multiplica por derecha, asi que
	// la ULTIMA linea es la PRIMERA transformacion que se aplica.
	//
	// El orden de las tres rotaciones es guiñada -> cabeceo -> alabeo leido de
	// izquierda a derecha, o sea R = Ry * Rx * Rz. Hay que fijar uno porque las
	// rotaciones NO conmutan: cabecear y despues alabear no da lo mismo que
	// alabear y despues cabecear. Se elige este porque es el habitual en
	// aeronautica (el alabeo se aplica en los ejes ya orientados del avion).
	pose_ = glm::mat4(1.0f);
	pose_ = glm::translate(pose_, posicion);
	pose_ = glm::rotate(pose_, angulos.y, glm::vec3(0.0f, 1.0f, 0.0f));  // yaw
	pose_ = glm::rotate(pose_, angulos.x, glm::vec3(1.0f, 0.0f, 0.0f));  // pitch
	pose_ = glm::rotate(pose_, angulos.z, glm::vec3(0.0f, 0.0f, 1.0f));  // roll
	pose_ = glm::translate(pose_, -ref_);
}


// ----------------------------------------------------------------------------
void Aircraft::collect(std::vector<RenderItem>& items) const
{
	// clear() borra los elementos pero CONSERVA la capacidad: despues del
	// primer cuadro, el push_back de abajo ya no pide memoria al sistema.
	items.clear();
	items.reserve(piezas_.size());

	for (const Pieza& p : piezas_) {
		// La unica linea que importa de todo el practico:
		//     M_mundo(pieza) = M_pose * M_local(pieza)
		// La MISMA pose multiplica a las ocho. Por eso se mueven juntas.
		items.push_back({ p.mesh, pose_ * p.local, p.color });
	}
}


// ----------------------------------------------------------------------------
const char* Aircraft::nombre(std::size_t i) const
{
	return (i < piezas_.size()) ? piezas_[i].nombre : "";
}
