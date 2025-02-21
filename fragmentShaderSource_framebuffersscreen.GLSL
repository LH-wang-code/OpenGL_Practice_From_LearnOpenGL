#version 330 core

in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D texturescreen;


void main()
{
    FragColor=texture(texturescreen,TexCoords);

}
