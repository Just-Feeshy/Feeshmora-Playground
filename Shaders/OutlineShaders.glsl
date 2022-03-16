layout (location = 0) in vec3 VertexPosition;

uniform mat4 cameraMatrix;
uniform mat4 model;
uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;

void main() {
	gl_Position = cameraMatrix * vec4(vec3(model * translation * rotation * scale * vec4(aPos, 1.0f)), 1.0);
}