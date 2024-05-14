#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 aTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 color;

varying vec2 TexCoords;

out vec4 fragColor;
out vec3 fragNormal;
out vec3 fragPosition;



void main() {
    fragColor = color;
    fragNormal = normal;
    fragPosition = vec3(model * vec4(position, 1.0));
    TexCoords = aTexCoords;


    gl_Position = projection * view * model * vec4(position, 1.0);


}