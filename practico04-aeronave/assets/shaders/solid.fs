#version 460 core

in  vec3 vNormal;      // viene del vertex shader (hoy solo se usa en depuracion)
out vec4 FragColor;

// Un color por PIEZA, no por vertice y no por malla. Es lo que permite que las
// ocho piezas compartan tres mallas: el color viaja en el RenderItem.
uniform vec4 uColor;

void main()
{
    FragColor = uColor;
}
