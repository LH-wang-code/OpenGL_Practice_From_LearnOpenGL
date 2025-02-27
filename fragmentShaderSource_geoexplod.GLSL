#version 330 core
out vec4 FragColor;


struct Material{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};


struct Light{
    vec3 position;
    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

};

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    

    FragColor = texture(texture_diffuse1,TexCoords);
}