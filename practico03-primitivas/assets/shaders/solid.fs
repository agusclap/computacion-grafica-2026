#version 460 core

in  vec3 vNormal;      // viene del vertex shader (hoy solo se usa en depuracion)
out vec4 FragColor;

uniform vec3 uColor;   // un color por OBJETO, ya no por vertice

void main()
{
    FragColor = vec4(uColor, 1.0);
}
