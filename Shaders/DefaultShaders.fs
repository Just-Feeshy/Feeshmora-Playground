#version 330 core
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texSampler;

uniform mat3 lightMatrix;

uniform vec3 cameraPos;

void main() {
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 normaly = normalize(normal);

    //LightPosition and Brightness
    vec3 lightDirection = normalize(lightMatrix[0] - globalModelPos);

    //Reflect stuff
    vec3 reflection = reflect(-lightDirection, normaly);

    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Play around with this later.
    float specular = (pow(max(dot(cameraView, reflection), 0), 5) * 0.50);

    vec4 color = texture(texSampler, texCoord);
    FragColor = color * vec4(lightMatrix[1], 1) * (diff + 0.0f + specular);
}