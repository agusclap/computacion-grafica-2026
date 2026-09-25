#version 460 core

// Modo de depuracion de normales (Guia 03, "Como se sabe que esta bien").
// La normal no se usa para nada todavia, asi que una normal mal calculada no
// produce ningun sintoma. Pintando el vertice con el valor de la normal como
// color se la puede "ver": cada direccion da un color distinto.
//
// El *0.5+0.5 lleva el rango [-1,1] de la normal al [0,1] del color.
//
// Que hay que observar:
//   - el lateral del cilindro: un degrade SUAVE alrededor del eje de revolucion
//   - el cubo: seis caras de color PLANO

in  vec3 vNormal;
out vec4 FragColor;

uniform vec3 uColor;   // declarado y NO usado: el compilador puede eliminarlo

void main()
{
    FragColor = vec4(vNormal * 0.5 + 0.5, 1.0);
}
