#version 330 core

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D hdrBuffer;
uniform float exposure;
uniform bool hdr;


void main()
{
    const float gamma=2.2f;
    vec3 hdrColor=texture(hdrBuffer,TexCoords).rgb;
    if(hdr)
    {
        
        vec3 result=vec3(1.0f)-exp(-hdrColor * exposure);
        result=pow(result,vec3(1.0f/gamma));
        FragColor=vec4(result,1.0f);
    }
    else
    {
        vec3 result=pow(hdrColor,vec3(1.0f/gamma));
        FragColor=vec4(result,1.0f);

    }
}