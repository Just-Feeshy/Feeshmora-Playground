#version 330 core
out vec4 FragColor;

in vec3 vrtxColor;
in vec2 texCoord;

uniform sampler2D texSampler;

uniform vec4 lightColor;

void main() {
    vec4 color = texture(texSampler, texCoord);
    FragColor = color;
}