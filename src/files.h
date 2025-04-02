#pragma once

const char* res(const char* path);

char* getVertexShaderSrc();
char* getFragmentShaderSrc();

char* getFileSrc(const char* path);

long getFileSize(const char* path);

void writeStringToFile(const char* path, char* contents);

long getVtShaderLen();
long getFrShaderLen();
