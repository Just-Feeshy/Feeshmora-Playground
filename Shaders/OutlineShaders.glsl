layout (location = 0) in vec3 VertexPosition;

uniform mat4 pViewMatrix;
uniform mat4 modelMatrix;

out vec3 globalModelPos;

void main() {
    globalModelPos = vec3(modelMatrix * 2 * vec4(VertexPosition, 1));

	//gl_Position = pViewMatrix * vec4(globalModelPos, 1);
}