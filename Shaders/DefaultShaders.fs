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
    vec3 rotation; //Don't Change

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
    return vec4(1.0);
}

vec4 pointLight(int index) {
    //LightPosition and Brightness
    vec3 lightDirection = (pointlight[index].position - globalModelPos);

    float distance = length(lightDirection);
    float intensity = pointlight[index].intensity / (pointlight[index].linear * pow(distance, 2) + pointlight[index].constant * distance + 1.0);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection);
    
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 reflection = reflect(-lightDirection, normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16) * 0.5;

    vec4 diffuse = texture(texture0, texCoord) * diff * intensity;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle * intensity;

    return (diffuse + specular);
}

vec4 spotLight(int index) {
    //LightPosition and Brightness
    vec3 lightDirection = (spotlight[index].position - globalModelPos);

    float distance = length(lightDirection);
    float intensity = 1.0 / (spotlight[index].linear * pow(distance, 2) + spotlight[index].constant * distance + 1.0);

    vec3 normaly = normalize(normal);
    lightDirection = normalize(lightDirection);
    
    vec3 cameraView = normalize(cameraPos - globalModelPos);

    vec3 reflection = reflect(-lightDirection, normalize(normal));

    float diff = max(dot(normaly, lightDirection), 0.0);

    //Play around with this more.
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16) * 0.5;

    //Spotlight Stuff
    vec3 direction = vec3(0.0, -1.0, 0.0);
    float theta = dot(direction, -lightDirection);
    float spotLightInten = (spotlight[index].outerCutOff - (spotlight[index].outerCutOff - theta)/(spotlight[index].outerCutOff - spotlight[index].cutOff));

    vec4 diffuse = texture(texture0, texCoord) * diff;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle;

    //Organize intensity
    diffuse *= (intensity * spotlight[index].intensity) * spotLightInten;
    specular *= intensity * spotLightInten;

    return (diffuse + specular);
}

void main() {
    vec4 lights = vec4(0.0);

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

    FragColor = lights + 0.1f;
}