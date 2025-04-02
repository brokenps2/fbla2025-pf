#include <GL/glew.h>
#include <SDL2/SDL_surface.h>
#include "config.h"
#include "files.h"
#include "menus.h"
#include "events.h"
#include "renderer.h"
#include <stb_image.h>
#include <stdint.h>
#include "nuklearManager.h"
#include "window.h"

Texture bgTexture;
Shader shader;
unsigned int VAO;
unsigned int VBO;

float clearColor[4] = {1, 1, 1, 1};
float bgColor[3] = {0, 0.5, 0};
float backgroundVertices[] = {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
        1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
        1.0f, -1.0f,  1.0f, 0.0f,
        1.0f,  1.0f,  1.0f, 1.0f
};

void createShader(Shader* shader) {
    shader->vtShaderSrc = getFileSrc(res("shader/vertexShader.glsl"));
    shader->frShaderSrc = getFileSrc(res("shader/fragmentShader.glsl"));

    int success;
    char infoLog[512];

    shader->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader->vertexShader, 1, (const char**)&shader->vtShaderSrc, NULL);
    glCompileShader(shader->vertexShader);

    free(shader->vtShaderSrc);

    glGetShaderiv(shader->vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader->vertexShader, 512, NULL, infoLog);
        printf("vertex shader compile failed\n%s\n", infoLog);
    };


    shader->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader->fragmentShader, 1, (const char**)&shader->frShaderSrc, NULL);
    glCompileShader(shader->fragmentShader);

    free(shader->frShaderSrc);

    glGetShaderiv(shader->fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader->fragmentShader, 512, NULL, infoLog);
        printf("fragment shader compile failed\n%s\n", infoLog);
    };

    shader->id = glCreateProgram();

    glAttachShader(shader->id, shader->vertexShader);
    glAttachShader(shader->id, shader->fragmentShader);

    glLinkProgram(shader->id);

    glDeleteShader(shader->vertexShader);
    glDeleteShader(shader->fragmentShader);

}

void createTexture(Texture* tex, const char* path) {
    stbi_set_flip_vertically_on_load(1);
    tex->data = stbi_load(path, &tex->w, &tex->h, &tex->channels, 0);   
   
    glGenTextures(1, &tex->id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if(tex->channels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->w, tex->h, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->w, tex->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex->data);
    }

    stbi_image_free(tex->data);
}

void initRenderer() {
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);

    bgColor[0] = cfgLookupVec3("bg").x;
    bgColor[1] = cfgLookupVec3("bg").y;
    bgColor[2] = cfgLookupVec3("bg").z;

    createTexture(&bgTexture, res("images/bg.png"));

    createShader(&shader);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(backgroundVertices), backgroundVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindTexture(GL_TEXTURE_2D, bgTexture.id);
}

void setClearColor(float r, float g, float b, float a) {
    clearColor[0] = r;
    clearColor[1] = g;
    clearColor[2] = b;
    clearColor[3] = a;

}

void setBackgroundColor(float r, float b, float g) {
    bgColor[0] = r;
    bgColor[1] = g;
    bgColor[2] = b;
}

void gtmaUseShader(Shader* shader) {
    glUseProgram(shader->id);
}

void setFloat(Shader* shader, const char* name, float value) { 
    glUniform1f(glGetUniformLocation(shader->id, name), value);
}

void gtmaSetVec3(Shader* shader, const char* name, float value[3]) {
    glUniform3f(glGetUniformLocation(shader->id, name), value[0], value[1], value[2]);
}

void updateRenderer() {
    setFloat(&shader, "width", getWindowWidth());
    setFloat(&shader, "height", getWindowHeight());
    glViewport(0, 0, getWindowWidth(), getWindowHeight());
    glClearColor((float)9/255, (float)8/255, (float)22/255, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gtmaUseShader(&shader);
    gtmaSetVec3(&shader, "color", bgColor);
    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_2D, bgTexture.id);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    renderNuklear();
    displayMenu();
}
