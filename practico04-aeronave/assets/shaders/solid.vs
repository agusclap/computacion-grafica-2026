#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 vNormal;

// uModel es ahora la matriz de MUNDO de la pieza, o sea el producto
//     M_pose * M_local(pieza)
// que ya viene compuesto desde el lado de C++. El shader no sabe -- ni le
// importa -- que adentro hay una pose y un despiece: recibe una sola matriz.
uniform mat4 uModel;
uniform mat4 uAjuste;   // CAJA NEGRA hasta ver la Unidad VII

void main()
{
    // La normal se rota con la misma matriz que la posicion para que el modo
    // de depuracion muestre que la pieza GIRO. Se descarta la traslacion
    // tomando solo la parte 3x3, porque una normal es una DIRECCION y no un
    // punto: trasladarla no tendria sentido.
    // Esto vale mientras la matriz no tenga escala no uniforme; cuando la
    // tenga (Unidad IX) hay que usar la traspuesta de la inversa.
    vNormal     = normalize(mat3(uModel) * aNormal);
    gl_Position = uAjuste * uModel * vec4(aPos, 1.0);
}
