//Messy. Ik.
out vec4 FragColor;

in vec3 globalModelPos;
in vec3 vrtxColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D texture0;
uniform sampler2D texture1;

//uniform float near;
//uniform float far;

struct PointLight {
    vec3 position;
    
    float intensity;
    float linear;
    float constant;

    bool shouldCast;
};

struct SpotLight {
    float cutOff;
    float outerCutOff;

    vec3 position;
    vec3 direction;

    float intensity;
    float linear;
    float constant;

    bool shouldCast;
};

struct DirecLight {
    float intensity;

    bool shouldCast;
};

uniform vec3 cameraPos;
//uniform vec3 colors;

#ifndef MAXIMUM_POINTLIGHTS
#define MAXIMUM_POINTLIGHTS 1
#endif

#ifndef MAXIMUM_SPOTLIGHTS
#define MAXIMUM_SPOTLIGHTS 1
#endif

//Always 1. unless...
#ifndef MAXIMUM_DIRECLIGHTS
#define MAXIMUM_DIRECLIGHTS 1
#endif

uniform PointLight pointlight[MAXIMUM_POINTLIGHTS];
uniform SpotLight spotlight[MAXIMUM_SPOTLIGHTS];
uniform DirecLight direclight[MAXIMUM_DIRECLIGHTS];

vec4 directionLight(int index) {
    vec3 normaly = normalize(normal);
    vec3 lightDirection = normalize(vec3(1.0, 1.0, 0.0));
    float diff = max(dot(normaly, lightDirection), 0.0);

    //Specular but Organized
    vec3 cameraView = normalize(cameraPos - globalModelPos);
    vec3 reflection = reflect(-lightDirection, normalize(normal));
    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16) * 0.5;

    vec4 diffuse = texture(texture0, texCoord) * diff * direclight[index].intensity;
    vec4 specular = texture(texture1, texCoord) * specularAngle * direclight[index].intensity;

    return (diffuse + specular);
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

    float specularAngle = pow(max(dot(cameraView, reflection), 0), 16) * 0.5;

    //Spotlight Stuff
    vec3 direction = vec3(spotlight[index].direction.x, -1.0, spotlight[index].direction.z);
    float theta = dot(direction, -lightDirection);
    float spotLightInten = (spotlight[index].outerCutOff - (spotlight[index].outerCutOff - theta)/(spotlight[index].outerCutOff - spotlight[index].cutOff));

    vec4 diffuse = texture(texture0, texCoord) * diff;
    
    vec4 specular = texture(texture1, texCoord) * specularAngle;

    //Organize intensity
    diffuse *= (intensity * spotlight[index].intensity) * spotLightInten;
    specular *= intensity * spotLightInten;

    return (diffuse + specular);
}

float linearDepth(float depth) {
    float near = 0.1;
    float far = 2000.0;

    return (2.0 * near * far) / (far + near - (depth * 2.0 - 1.0) * (far - near));
}


float logDepth(float depth, float steepness, float offset) {
    float zVal = linearDepth(depth);
	return (1.0 / (1.0 + exp(-steepness * (zVal - offset))));
}

void main() {
    vec4 lights = vec4(0.0);

    if(texture(texture0, texCoord).a < 0.1) {
        discard;
    }

    if(texture(texture1, texCoord).a < 0.1) {
        discard;
    }

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

    if(direclight[0].shouldCast) {
        lights += directionLight(0);
    }

    float depth = logDepth(gl_FragCoord.z, 0.5, 5.0);
    FragColor = lights * (1.0 - depth) + vec4(depth * vec3(0.02, 0.02, 0.02), 1.0);
}