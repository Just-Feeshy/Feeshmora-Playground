#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform float anim;

out vec3 vrtxColor;
out vec2 TexCoord;

void main() {
  gl_Position = vec4(aPos.x + cos(anim / 2) / 2, aPos.y + (abs(sin(anim)) / 2), aPos.z, 1);
  vrtxColor = aColor;
  TexCoord = aTexCoord;
}