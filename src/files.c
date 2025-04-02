#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <string.h>
#include "files.h"
#include "config.h"

long vtShaderLength;
long frShaderLength;

const char* res(const char* path) {
    const char* resLoc = cfgGetResLoc();
    
    char* fullPath = malloc(strlen(resLoc) + strlen(path) + 1);
    
    if(fullPath) {
        snprintf(fullPath, strlen(resLoc) + strlen(path) + 1, "%s%s", resLoc, path);
    }
    
    return fullPath;
}

char* getVertexShaderSrc() {

    char* buffer = NULL;
    long length;
    FILE* fptr = fopen(res("/shaders/vertexShader.glsl"), "r");

    if (fptr) {
        fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);
        
        buffer = malloc(length + 1);
        if (buffer) {
            size_t readLength = fread(buffer, 1, length, fptr);
            buffer[readLength] = '\0';
        }
        fclose(fptr);
    }

    return buffer;
}

char* getFragmentShaderSrc() {

    char* buffer = NULL;
    long length;
    FILE* fptr = fopen(res("/shaders/fragmentShader.glsl"), "r");

    if (fptr) {
        fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);
        
        buffer = malloc(length + 1);
        if (buffer) {
            size_t readLength = fread(buffer, 1, length, fptr);
            buffer[readLength] = '\0';
        }
        fclose(fptr);
    }

    return buffer;
}

char* getFileSrc(const char* path) {

    char* buffer = NULL;
    long length;
    FILE* fptr = fopen(path, "r");

    if(!fptr) {
        printf("failed to load file %s\n", path);
        exit(1);
    }

    if (fptr) {
        fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);
        
        buffer = malloc(length + 1);
        if (buffer) {
            size_t readLength = fread(buffer, 1, length, fptr);
            buffer[readLength] = '\0';
        }
        fclose(fptr);
    }

    return buffer;
}

long getFileSize(const char* path) {
    long length;
    FILE* fptr = fopen(path, "r");

    if(!fptr) {
        printf("failed to load file %s\n", path);
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    fclose(fptr);
    return length;
}

void writeStringToFile(const char* path, char* contents) {
    FILE *fptr = fopen(path, "w");
    if (!fptr) {
        printf("failed to load file %s\n", path);
        exit(1);
    }
    
    if (fputs(contents, fptr) == EOF) {
        fclose(fptr);
        printf("failed to write to file %s", path);
    }

    fclose(fptr);
}
