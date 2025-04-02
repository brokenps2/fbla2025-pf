#version 330 core

out vec4 fragColor;
  
in vec2 outTexCoord;

uniform vec3 color = vec3(0, 0, 1);

uniform sampler2D tex0;

void main() {
    fragColor = texture(tex0, outTexCoord) * vec4(color, 1);
    return;
}
