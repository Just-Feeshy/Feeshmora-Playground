out vec4 FragColor;

in vec3 vrtxColor;
in vec2 TexCoord;

uniform sampler2D texture0; 

void main() {
    FragColor = texture(texture0, TexCoord);
}