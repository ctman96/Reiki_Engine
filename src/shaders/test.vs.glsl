#version 330

// Input attributes
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;

// Application data
uniform sampler2D sampler0;
uniform mat3 transform;
uniform mat3 projection;

out vec4 vcolor;

void main() {
    vec3 pos = projection * transform * vec3(in_position.xy, 1.0);
    gl_Position = vec4(pos.xy, in_position.z, 1.0);
    vcolor = in_color * texture(sampler0, pos.xy);
}