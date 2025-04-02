#pragma once
#include <GL/glew.h>
#include <stdbool.h>

typedef struct Texture {
    int w;
    int h;
    int channels;
    unsigned char* data;
    unsigned int id;
} Texture;

typedef struct Shader {

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint id;

    int sType;

    char* vtShaderSrc;
    char* frShaderSrc;

} Shader;

typedef struct vec3 {
    float x, y, z;
} vec3;

void gtmaCreateShader(Shader* shader);
void gtmaUseShader(Shader* shader);

void gtmaSetBool(Shader* shader, const char* name, bool value);
void gtmaSetInt(Shader* shader, const char* name, int value);
void gtmaSetFloat(Shader* shader, const char* name, float value);

GLint gtmaGetBool(Shader* shader, const char* name);
GLint gtmaGetInt(Shader* shader, const char* name);
GLfloat gtmaGetFloat(Shader* shader, const char* name);

void initRenderer();
void setClearColor(float r, float g, float b, float a);
void setBackgroundColor(float r, float b, float g);
void updateRenderer();
