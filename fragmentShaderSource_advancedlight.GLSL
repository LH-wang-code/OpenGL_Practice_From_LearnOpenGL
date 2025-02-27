#version 330 core


out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D planetexture;
uniform vec3 lightPos;

uniform vec3 viewPos;

uniform bool blinn;
void main()
{
    vec3 color=texture(planetexture,TexCoords).rgb;


    vec3 ambient=0.05f * color;

    vec3 lightDir=normalize(lightPos-FragPos);
    vec3 normal=normalize(Normal);

    float diff=max(dot(lightDir,normal),0.0f);

    vec3 diffuse=diff * color;

    vec3 viewDir=normalize(viewPos-FragPos);

    vec3 reflectDir=reflect(-lightDir,normal);


    float spec=0.0f;

    if(blinn)
    {
        vec3 halfwayDir=normalize(lightDir+viewDir);
        spec=pow(max(dot(normal,halfwayDir),0.0f),32.0f);

    }else
    {
        vec3 reflectDir=reflect(-lightDir,normal);

        spec=pow(max(dot(viewDir,reflectDir),0.0f),8.0f);
    }
    vec3 specular=vec3(0.3f)*spec;
    FragColor=vec4(ambient+diffuse+specular,1.0f);




}

