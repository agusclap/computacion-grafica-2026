#version 460 core

in  vec3 vColor;      // viene del vertex shader: MISMO tipo y MISMO nombre
out vec4 FragColor;

void main()
{
    FragColor = vec4(vColor, 1.0);
}
