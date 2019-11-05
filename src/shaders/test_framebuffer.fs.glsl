#version 330

in vec2 texcoord;

uniform sampler2D sampler0;

// Output color
layout(location = 0) out vec4 out_color;

void main()
{
    out_color = texture(sampler0, texcoord);
}
