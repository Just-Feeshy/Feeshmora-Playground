//Messy. Ik.
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texture0;
uniform sampler2D texture1;

struct PointLight {
    int lightEnum;

    vec3 position;
    
    float intensity;
    float linear;
    float constant;

    bool shouldCast;
};

struct SpotLight {
    int lightEnum;

    float cutOff;
    float outerCutOff;

    vec3 position;
    vec3 direction;

    float intensity;
    float linear;
    float constant;

    bool shouldCast;
};

uniform vec3 cameraPos;

#ifndef MAXIMUM_POINTLIGHTS
#define MAXIMUM_POINTLIGHTS 1
#endif

#ifndef MAXIMUM_SPOTLIGHTS
#define MAXIMUM_SPOTLIGHTS 1
#endif

uniform PointLight pointlight[MAXIMUM_POINTLIGHTS];
uniform SpotLight spotlight[MAXIMUM_SPOTLIGHTS];

vec4 directionLight() {
    return vec4(1.0f);
}

vec4 pointLight(int index) {
    //LightPosition and Brightness
    vec3 lightDirection = (pointlight[index].position - globalModelPos);

    float distance = length(lightDirection);
    float intensity = pointlight[index].intensity / (pointlight[index].linear * pow(distance, 2) + pointlight[index].constant * distance + 1.0f);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection);
    
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 reflection = reflect(-lightDirection, normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16) * 0.5;

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular);
}

vec4 spotLight(int index) {
    //Light and Shadow
    float lightCone = 0.9;
    float shadowCone = 0.95;

    //LightPosition and Brightness
    vec3 normaly = normalize(normal);
    vec3 lightDirection = normalize(spotlight[index].position - globalModelPos);
    float diff = max(dot(normaly, lightDirection), 0.0f);

    //Specular stuff
    vec3 cameraView = normalize(cameraPos - globalModelPos);
    vec3 reflectDir = reflect(-lightDirection, normaly);
    float specularAngle = pow(max(dot(cameraView, reflectDir), 0.0f), 16) * 0.5;

    //play around with
    float distance = length(spotlight[index].position - globalModelPos);
    float inten = spotlight[index].intensity / (spotlight[index].linear * pow(distance, 2) + spotlight[index].constant * distance + 1.0f);

    //caculate intensity
    vec3 direction = vec3(0.0f, -1.0f, 0.0f);
    float theta = dot(direction, -lightDirection);
    float intensity = clamp((theta - shadowCone) / (lightCone - shadowCone), 0.0f, 1.0f);

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular);
}

void main() {
    vec4 lights = vec4(0.0f);

    for(int i=0; i<MAXIMUM_POINTLIGHTS; i++) {
        if(pointlight[i].shouldCast) {
            lights += pointLight(i);
        }
    }

    for(int i=0; i<MAXIMUM_SPOTLIGHTS; i++) {
        if(spotlight[i].shouldCast) {
            lights += spotLight(i);
        }
    }

    FragColor = lights;
}