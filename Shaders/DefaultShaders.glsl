layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec2 TextureCoord;
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec3 aNormal;

out vec3 vrtxColor;
out vec2 texCoord;

uniform mat4 pViewMatrix;
uniform mat4 modelMatrix;

out vec3 globalModelPos;
out vec3 normal;

void main() {
    globalModelPos = vec3(modelMatrix * vec4(VertexPosition, 1));

    gl_Position = pViewMatrix * vec4(globalModelPos, 1);
    
    vrtxColor = aColor;
    normal = aNormal;
    texCoord = TextureCoord;
}