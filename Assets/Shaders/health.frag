#version 400 core

uniform sampler2D 	mainTex;
uniform int useTexture;

in Vertex
{
	vec4 colour;
	vec2 texCoord;
} IN;

out vec4 fragColor;

void main(void)
{
	if(useTexture == 0) {
		fragColor = IN.colour;
	}
	else {
		fragColor = texture(mainTex, IN.texCoord);
	}

}