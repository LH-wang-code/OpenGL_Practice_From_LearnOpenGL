#version 330 core

in vec2 TexCoords;


out vec4 FragColor;

uniform samlpler2D FragColor;

void main()
{

    FragColor=texture(texture1,TexCoords);

}