#version 330

in vec2 texcoord;

uniform sampler2D sampler0;
uniform vec4 color;

// Output color
layout(location = 0) out vec4 out_color;

void main()
{
    out_color = color  * texture(sampler0, vec2(texcoord.x, texcoord.y));
}
