#pragma once
#include "renderer.h"

void initConfig(const char* path);

const char* cfgGetResLoc();
const char* cfgLookupString(const char* key);
int cfgLookupInt(const char* key);
float cfgLookupFloat(const char* key);
int cfgLookupBool(const char* key);
vec3 cfgLookupVec3(const char* key);
void cfgSetVec3(const char* key, vec3 value);
