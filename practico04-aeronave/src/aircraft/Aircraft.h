// ----------------------------------------------------------------------------
// Aircraft.h  -  Practico 04, Partes 2 y 3.
//
// El MODELO COMPUESTO: una unica aeronave armada con varias primitivas del
// Practico 03. La clase es dueña de las mallas, guarda el despiece (una matriz
// local por pieza) y sabe ubicar el conjunto en el mundo con una sola pose.
//
// Aeronave de referencia: SIAI Marchetti / Aermacchi S-211, las tres vistas de
// la guia (p.1). Las medidas son RELATIVAS AL LARGO DEL FUSELAJE, que se toma
// igual a 1; asi el modelo es adimensional y cualquier escala global se decide
// despues, afuera.
//
// ----------------------------------------------------------------------------
// EL DESPIECE  (la actividad del aula)
//
// La guia aclara que "no hay una solucion unica porque la cantidad de piezas y
// que primitivas se usa en cada una dependen de este despiece (y es una
// propuesta personal)". Esta es la propuesta de este trabajo:
//
//   #  pieza                    primitiva   como se dimensiona
//   1  fuselaje central         cilindro    parametros de la primitiva
//   2  nariz                    cono        cono tal cual (escala 1)
//   3  cola                     cono        el MISMO cono, escala UNIFORME
//   4  ala derecha              cubo        escala NO uniforme -> placa
//   5  ala izquierda            cubo        idem, espejada por TRASLACION
//   6  estab. horizontal der.   cubo        idem, mas chico
//   7  estab. horizontal izq.   cubo        idem
//   8  deriva (estab. vertical) cubo        idem, parada sobre el eje Y
//
//   => OCHO PIEZAS, OCHO MATRICES LOCALES, TRES MALLAS EN LA GPU.
//
// ----------------------------------------------------------------------------
// EN QUE SE APARTA ESTA CLASE DEL ESQUELETO DE LA GUIA  (p.2)
//
// La guia aclara que las interfaces que muestra son "un punto de partida y no
// el molde". Hay dos diferencias, y las dos son deliberadas:
//
//  1. El esqueleto propone DOS vectores paralelos:
//         std::vector<Mesh>      piezas_;
//         std::vector<glm::mat4> locales_;
//     Aca hay UN solo vector de una estructura Pieza que junta malla, matriz
//     local y color. Dos motivos:
//       a) Vectores paralelos se pueden desincronizar: nada impide que uno
//          tenga siete elementos y el otro ocho, y el error recien se nota al
//          dibujar. Con un vector de estructuras la correspondencia es un
//          invariante del tipo, no una promesa.
//       b) Mas de fondo: std::vector<Mesh> implica UNA MALLA POR PIEZA, o sea
//          ocho. Aca las piezas guardan un PUNTERO a malla y las mallas viven
//          aparte, que es lo que permite que ocho piezas compartan tres
//          mallas. La propia guia pregunta cuantas mallas distintas hacen
//          falta; compartirlas es la respuesta.
//
//  2. init() devuelve bool y recibe la cantidad de gajos. El bool traslada la
//     verificacion de winding del Practico 03 a quien construye el modelo; el
//     parametro es el mismo criterio del Practico 03, donde la discretizacion
//     se elige desde afuera y la malla se regenera sola.
//
// ----------------------------------------------------------------------------
// CUESTIONES A PENSAR DE LA PARTE 1  (guia p.2)
//
//  - "Si se llama a collect() antes de haber llamado nunca a update(), con
//     que pose se dibuja el avion? Y si se llama antes de init()?"
//
//    Antes de update(): con pose_ = IDENTIDAD, porque asi esta inicializada.
//    Y la identidad NO es la pose neutra correcta: le falta el T(-ref), asi
//    que el avion aparece con la nariz en el origen en vez de con su punto de
//    referencia en el origen. Es el peor tipo de error -- se dibuja algo, y
//    algo parecido a lo que se esperaba -- asi que aca NO SE DEJA QUE PASE:
//    init() termina llamando a update() con pose neutra, y de ese modo el
//    objeto nunca esta en un estado a medio armar.
//
//    Antes de init(): piezas_ esta vacio, collect() limpia el vector y no
//    agrega nada, y no se dibuja NADA. No hay puntero colgando ni memoria
//    pisada: el vector vacio es un estado valido. Que la pantalla quede vacia
//    es un sintoma mucho mas facil de diagnosticar que un avion mal puesto.
//
//  - "Por que separar init() (una vez) de update() (cada cuadro)? Que costo
//     tendria recalcular las piezas en cada cuadro?"
//
//    Porque son dos trabajos de ordenes de magnitud distintos.
//      init()   : genera 198 vertices (100 + 74 + 24) y 468 indices en la CPU,
//                 pide tres juegos de VBO/VAO/EBO al driver y transfiere todo
//                 a la memoria de video.
//      update() : multiplica cuatro matrices de 4x4.
//    Rehacer lo primero 60 veces por segundo significa repetir la generacion y
//    la transferencia por el bus en cada cuadro, y ademas crear y destruir
//    objetos de OpenGL sin parar, que fragmenta la memoria de video y obliga
//    al driver a sincronizar. Todo eso para obtener EXACTAMENTE los mismos
//    vertices, porque la geometria del avion no cambia: lo unico que cambia
//    entre cuadros es donde esta.
//
//  - "El dia que las piezas se reemplacen por una malla cargada de un .obj,
//     que metodo de Aircraft cambia? Y que parte del resto del programa?"
//
//    Cambia init(), y SOLO init(): es el unico que decide de donde sale la
//    geometria. update() sigue componiendo la misma pose y collect() sigue
//    haciendo pose * local. Del resto del programa no cambia nada, porque el
//    main no conoce mallas: recibe RenderItem.
//    La excepcion honesta: si el .obj trajera materiales o texturas, el color
//    plano del RenderItem se quedaria corto y habria que ampliar ESE struct
//    -- y entonces si tocaria el bucle de dibujado.
//
// ----------------------------------------------------------------------------
// SISTEMA DE REFERENCIA DEL MODELO  (la primera decision, y la que ordena todo)
//
//   origen  : la NARIZ de la aeronave
//   +Z      : de la nariz hacia la cola
//   +Y      : hacia arriba (la deriva crece en +Y)
//   +X      : hacia estribor, o sea el ala DERECHA
//
// Es el ejemplo que da la filmina ("Origen del modelo en la nariz; z+ va de la
// nariz a la cola"). Con el elegido, todas las coordenadas del despiece se leen
// como "a que distancia de la nariz esta esta pieza", que es como se miden las
// tres vistas.
//
// OJO: las primitivas del Practico 03 tienen su eje de revolucion en Y, no en
// Z. Por eso el cilindro y los dos conos llevan una rotacion de +-90 grados en
// su matriz LOCAL: es el precio de haber fijado un eje canonico en el
// generador, y se paga una vez por pieza en vez de tener un generador por
// orientacion.
//
// ----------------------------------------------------------------------------
// CUESTIONES A PENSAR DE LA PARTE 2  (guia p.3)
//
//  - "Las piezas simetricas (las dos alas) se pueden obtener con una escala
//     negativa, pero eso ALTERA EL WINDING. ¿Conviene?"
//    NO, y aca no se usa. Una escala negativa en un eje tiene determinante
//    negativo: invierte la orientacion del espacio y un triangulo que estaba
//    antihorario pasa a horario. Con el descarte de caras traseras habilitado,
//    esa ala desapareceria; con iluminacion, sus normales apuntarian para
//    adentro. El ala izquierda se obtiene con una TRASLACION a x negativo, que
//    tiene determinante positivo y no toca el winding. Se puede porque el ala
//    es simetrica respecto de su propio plano: si tuviera una asimetria real,
//    haria falta una segunda malla, no un espejo.
//
//  - "Si una pieza se escala de forma no uniforme, ¿sus normales siguen siendo
//     perpendiculares a la superficie? ¿Hay alguna pieza para la que la
//     respuesta no importe?"
//    NO siguen siendo perpendiculares. Las posiciones se transforman con M,
//    pero las normales se deforman: hay que transformarlas con la
//    TRASPUESTA DE LA INVERSA de M, que para una escala no uniforme NO es
//    proporcional a M. Ejemplo concreto de este modelo: el ala es un cubo
//    escalado (0.385, 0.020, 0.240); su normal de borde (1,0,0) se transforma
//    con M en (0.385,0,0), que normalizada sigue siendo (1,0,0) -- esa zafa --
//    pero la normal de una cara inclinada dejaria de ser perpendicular.
//    SI hay piezas para las que no importa, y son tres:
//      * los dos CONOS, que solo llevan escala UNIFORME (la traspuesta de la
//        inversa de s*I es (1/s)*I, o sea la misma direccion);
//      * el CILINDRO, que no lleva escala ninguna porque sus dimensiones
//        reales entran como parametros de la primitiva.
//    Y en este practico todavia no importa para ninguna, porque el color es
//    plano y no se ilumina: el problema aparece en la Unidad IX.
//
//  - "¿Cuantas mallas distintas hacen falta y cuantas matrices locales?"
//    TRES mallas y OCHO matrices. Esa asimetria es el punto del practico: la
//    malla es la geometria en la GPU y se comparte; la matriz local es DONDE
//    esta esa geometria dentro del modelo y es propia de cada pieza. Las dos
//    alas son el mismo VBO leido dos veces con dos matrices distintas.
//
// ----------------------------------------------------------------------------
// PARTE 3: LA POSE  (una sola matriz mueve las ocho piezas)
//
//     M_mundo(pieza) = M_pose * M_local(pieza)
//     M_pose         = T(posicion) * R(angulos) * T(-ref)
//
// El T(-ref) de la derecha es el que hace todo el trabajo: lleva el PUNTO DE
// REFERENCIA al origen, ahi se rota, y recien despues se traslada a la posicion
// final. Sin el, la aeronave giraria alrededor de la nariz -- que es donde esta
// el origen del modelo -- y no alrededor de su centro.
//
// El punto de referencia sale de la figura de la guia (p.3): esta sobre el eje
// del fuselaje, a 0.438 * L_f de la nariz. Como L_f = 1, ref = (0, 0, 0.438).
//
// Lo importante es que M_pose se calcula UNA sola vez por cuadro y se aplica a
// las ocho piezas. Si cada pieza se moviera por su cuenta, el modelo se
// desarmaria en cuanto se lo rotara: que no se desarme ES la verificacion que
// pide la guia.
//
// ----------------------------------------------------------------------------
// CUESTIONES A PENSAR DE LA PARTE 3  (guia p.4)
//
//  - "De que lado de la composicion va la traslacion que lleva el punto de
//     referencia al origen? Que le pasa al avion si se la pone del otro lado?"
//
//    Va a la DERECHA de la rotacion, o sea se aplica PRIMERO. Es la unica
//    forma de que la rotacion encuentre el punto de referencia ya en el
//    origen, que es alrededor de donde rota una matriz de rotacion.
//    Del otro lado -- T(posicion) * T(-ref) * R -- pasan DOS cosas a la vez:
//      a) la rotacion opera sobre el modelo tal cual viene, asi que gira
//         alrededor del ORIGEN DEL MODELO, que aca es la punta de la nariz;
//      b) el T(-ref) deja de ser un cambio de centro y se vuelve un
//         desplazamiento real: el avion ademas se corre 0.438 hacia -Z.
//    Lo segundo se nota enseguida; lo primero es lo que de verdad importa y es
//    mas dificil de ver, porque a angulos chicos se parece bastante.
//    Con la tecla O del programa se puede comparar: mueve el punto de
//    referencia a la nariz y se ve como la cola sale despedida.
//
//  - "Si una pieza tuviera que moverse por su cuenta -- un aleron que se
//     deflecta --, alcanza con la misma matriz local fija? Que habria que
//     cambiar?"
//
//    NO alcanza: 'local' es fija por definicion, se calcula en init() y no se
//    vuelve a tocar. Esa pieza necesitaria una matriz local VARIABLE:
//        local(t) = T(bisagra) * R(deflexion(t), eje_bisagra) * T(-bisagra)
//                   * local_fija
//    y habria que recalcularla en update(), que hoy toca unicamente pose_.
//    O sea: el cambio no es agregar una pieza, es que update() deje de ser
//    "una sola matriz" y pase a recorrer las piezas moviles. La guia lo deja
//    afuera a proposito ("no se estan considerando partes moviles").
//
//  - "Hace falta un arbol de transformaciones para este modelo? o alcanza con
//     una lista de piezas y dos niveles de jerarquia? En que caso dejaria de
//     alcanzar?"
//
//    Para ESTE modelo alcanza la lista plana con dos niveles (pose * local), y
//    es la opcion b) de la guia: todas las piezas estan referidas directamente
//    al sistema del modelo, ninguna depende de otra.
//    Deja de alcanzar en cuanto una pieza cuelgue de otra pieza MOVIL, porque
//    ahi el movimiento del padre tiene que arrastrar al hijo. Tres ejemplos
//    concretos de esta misma aeronave:
//      * el timon de direccion, montado sobre la deriva: si la deriva se
//        moviera, el timon tendria que seguirla;
//      * el tren de aterrizaje: pata que se repliega y rueda montada sobre la
//        pata, que gira por su cuenta;
//      * un motor basculante con la tobera orientable colgando de el.
//    En esos casos M_mundo = pose * local_padre * local_hijo, y la cadena
//    puede tener mas de un eslabon: eso ya es un arbol.
// ----------------------------------------------------------------------------

#pragma once

#include <cstddef>
#include <vector>

#include <glm/glm.hpp>

#include "mesh/Mesh.h"
#include "aircraft/RenderItem.h"

class Aircraft {
public:
	Aircraft() = default;

	// No hace falta prohibir la copia a mano: la clase contiene objetos Mesh,
	// que ya la tienen prohibida, asi que Aircraft es no copiable por herencia
	// de esa restriccion. Es la regla del Practico 02 propagandose sola.

	// Crea las tres mallas en la GPU y arma el despiece.
	// Devuelve false si alguna malla salio con el winding invertido (la
	// verificacion sin dibujar del Practico 03) o si el despiece quedo vacio.
	// 'gajos' es la discretizacion diametral del cilindro y de los conos.
	bool init(unsigned gajos = 24U);

	// Recalcula la pose. 'angulos' viene en RADIANES:
	//     .x = cabeceo  (pitch, eje X: sube y baja la nariz)
	//     .y = guiñada  (yaw,   eje Y: gira la nariz a izquierda/derecha)
	//     .z = alabeo   (roll,  eje Z: baja un ala y sube la otra)
	// No toca ninguna matriz local: el despiece es fijo, lo unico que cambia
	// entre cuadros es esta matriz.
	void update(const glm::vec3& posicion, const glm::vec3& angulos);

	// Vuelca las ocho unidades de dibujado ya compuestas (M_pose * M_local).
	// Recibe el vector por referencia y lo LIMPIA antes de llenarlo, para no
	// pedir memoria nueva en cada cuadro: el vector conserva su capacidad.
	void collect(std::vector<RenderItem>& items) const;

	// Cambia el punto de referencia. Existe para PODER EQUIVOCARSE a proposito:
	// poniendolo en la nariz (0,0,0) se ve de que se trata el T(-ref), porque
	// la aeronave pasa a girar alrededor de la punta y la cola sale despedida.
	// Surte efecto en el proximo update().
	void set_ref(const glm::vec3& r) { ref_ = r; }

	// --- Consultas, para que el main pueda informar y verificar ------------
	const glm::vec3& ref(void)     const { return ref_; }
	const glm::mat4& pose(void)    const { return pose_; }
	std::size_t      piezas(void)  const { return piezas_.size(); }
	std::size_t      mallas(void)  const { return 3U; }

	// Devuelve el nombre de la pieza i (mismo orden que collect()).
	const char*      nombre(std::size_t i) const;

private:
	// Una pieza del despiece: que malla usa, donde esta dentro del modelo y de
	// que color es. La matriz es LOCAL (relativa al origen del modelo); la de
	// mundo se calcula en collect().
	struct Pieza {
		const Mesh* mesh   {nullptr};
		glm::mat4   local  {1.0f};
		glm::vec4   color  {1.0f};
		const char* nombre {""};
	};

	// Las tres mallas. La clase es DUEÑA: viven mientras viva el Aircraft, que
	// es exactamente lo que necesitan los punteros de RenderItem, que no lo son.
	Mesh malla_cilindro_;
	Mesh malla_cono_;
	Mesh malla_cubo_;

	std::vector<Pieza> piezas_;

	// Punto de referencia: sobre el eje del fuselaje, a 0.438 * L_f de la
	// nariz (figura de la guia, p.3). Con L_f = 1 el numero es literal.
	glm::vec3 ref_  {0.0f, 0.0f, 0.438f};
	glm::mat4 pose_ {1.0f};
};
