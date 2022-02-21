#version 330 core
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texture0;
uniform sampler2D texture1;

uniform vec3 MAXIMUM_LIGHTS;

struct Light {
    int lightEnum;

    vec3 position;
    
    float intensity;
    float linear;
    float constant;
};

uniform Light light;

uniform vec3 cameraPos;
//uniform float quad;

vec4 directionLight() {
    return vec4(1.0f);
}

vec4 pointLight() {
    //LightPosition and Brightness
    vec3 lightDirection = (light.position - globalModelPos);

    float distance = length(lightDirection);
    float intensity = light.intensity / (light.linear * pow(distance, 2) + light.constant * distance);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection);
    
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 reflection = reflect(-lightDirection, normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16);

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular);
}

vec4 spotLight() {
    //Light and Shadow
    float lightCone = 0.90f;
    float shadowCone = 0.95f;

    //LightPosition and Brightness
    vec3 lightDirection = (light.position - globalModelPos);

    float distance = length(lightDirection);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection);
    
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 reflection = reflect(-lightDirection, normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16);

    //caculate light cone
    float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirection);
	float intensity = clamp((angle - shadowCone) / (lightCone - shadowCone), 0.0f, 1.0f);

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular);
}

void main() {
    //vec4 results +=  

    if(light.lightEnum == 0) {
        FragColor = pointLight();
    }else if(light.lightEnum == 1) {
        FragColor = spotLight();
    }
}