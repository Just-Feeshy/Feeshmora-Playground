#version 330 core
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texSampler;

uniform mat3 lightMatrix;

void main() {
    vec3 cameraView = normalize(lightMatrix[0] - globalModelPos);

    vec3 normaly = normalize(normal);
    vec3 lightDirection = normalize(lightMatrix[0] - globalModelPos);

    float diff = max(dot(normaly, lightDirection), 0.0f);

    vec4 color = texture(texSampler, texCoord);
    FragColor = color * vec4(lightMatrix[1], 1) * (diff + 0.0f);
}