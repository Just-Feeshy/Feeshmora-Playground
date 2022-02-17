#version 330 core
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texture0;
uniform sampler2D texture1;

uniform int lightEnum;

uniform mat3 lightMatrix;

uniform vec3 cameraPos;

uniform float brightness;

uniform float linear;
uniform float constant;
//uniform float quad;

vec4 directionLight() {
    return vec4(1.0f);
}

vec4 pointLight() {
    //LightPosition and Brightness
    vec3 lightDirection = (lightMatrix[0] - globalModelPos);

    float distance = length(lightDirection);
    float intensity = 1.0f / (linear * pow(distance, 2) + constant * distance);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection) * brightness;
    
    vec3 cameraView = normalize((cameraPos * intensity) - globalModelPos);

    vec3 reflection = reflect(-lightDirection / max(brightness, 1), normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16);

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular); //* vec4(0.2, 0.4, 0, 0);
}

void main() {
    if(lightEnum == 0) {
        FragColor = pointLight();
    }else if(lightEnum == 1) {
        FragColor = directionLight();
    }
}