#version 330 core
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 TextureCoord;
layout (location = 2) in vec3 aColor;

out vec3 vrtxColor;
out vec2 texCoord;

uniform mat4 pViewMatrix;

uniform int MODELS_AMOUNT;

uniform mat4 modelMatrix_Array;

out vec3 globalModelPos;

void main() {
    //for(int i=0; i<MODELS_AMOUNT; i++) {
        globalModelPos = vec3(modelMatrix_Array * vec4(VertexPosition, 1));
    //}

    gl_Position = pViewMatrix * vec4(globalModelPos, 1);
    
    vrtxColor = aColor;
    texCoord = TextureCoord;
}