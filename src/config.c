#include "files.h"
#include <stdio.h>
#include "renderer.h"
#include <stdlib.h>
#include <cjson/cJSON.h>

const char* configPath;
char* contents;

cJSON* json;
cJSON* outJson;

void initConfig(const char* path) {
    
    configPath = path;
    contents = malloc((getFileSize(configPath) * sizeof(char)));
    contents = getFileSrc(configPath);

    if(!contents) {
        printf("config file of path %s contents is NULL\n", path);
        exit(1);
    }

    json = cJSON_Parse(contents);

    if(!json) {
        printf("error reading config file %s\n", path);
        exit(1);
    }

}

const char* cfgGetResLoc() {

    cJSON* resLocPath = cJSON_GetObjectItem(json, "resLoc");

    if(cJSON_IsString(resLocPath)) {
        return resLocPath->valuestring;
    } else {
        printf("error reading config file value \"resLoc\"\n");
        exit(1);
    }
}

const char* cfgLookupString(const char* key) {

    cJSON* value = cJSON_GetObjectItem(json, key);
 
    if(cJSON_IsString(value)) {
        return value->valuestring;
    } else {
        printf("error reading config file value \"%s\"\n", key);
        exit(1);
    }

}

int cfgLookupInt(const char* key) {
    cJSON* value = cJSON_GetObjectItem(json, key);
    
    if(cJSON_IsNumber(value)) {
        return value->valueint;
    } else {
        printf("error reading config file value \"%s\"\n", key);
        exit(1);
    }

}

float cfgLookupFloat(const char* key) {

    cJSON* value = cJSON_GetObjectItem(json, key);
 
    if(cJSON_IsNumber(value)) {
        return value->valuedouble;
    } else {
        printf("error reading config file value \"%s\"\n", key);
        exit(1);
    }

}

int cfgLookupBool(const char* key) {
    cJSON* value = cJSON_GetObjectItem(json, key);
 
    if(cJSON_IsBool(value)) {
        return value->valueint;
    } else {
        printf("error reading config file value \"%s\"\n", key);
        exit(1);
    }

}


vec3 cfgLookupVec3(const char* key) {
    cJSON* value = cJSON_GetObjectItem(json, key);
    if (cJSON_IsArray(value) && cJSON_GetArraySize(value) == 3) {
        cJSON* x = cJSON_GetArrayItem(value, 0);
        cJSON* y = cJSON_GetArrayItem(value, 1);
        cJSON* z = cJSON_GetArrayItem(value, 2);
        
        if (cJSON_IsNumber(x) && cJSON_IsNumber(y) && cJSON_IsNumber(z)) {
            return (vec3){ (float)x->valuedouble, (float)y->valuedouble, (float)z->valuedouble };
        }
    }
    
    printf("error reading config file value \"%s\"\n", key);
    exit(1);
}

void cfgSetVec3(const char* key, vec3 value) {
    cJSON* array = cJSON_CreateArray();
    cJSON_AddItemToArray(array, cJSON_CreateNumber(value.x));
    cJSON_AddItemToArray(array, cJSON_CreateNumber(value.y));
    cJSON_AddItemToArray(array, cJSON_CreateNumber(value.z));
    
    cJSON* item = cJSON_DetachItemFromObject(json, key);
    if (item) {
        cJSON_Delete(item);
    }
    cJSON_AddItemToObject(json, key, array);

    char* string = cJSON_Print(json);
    writeStringToFile(configPath, string);
}


void gtmaDestroyConfig() {
    free(contents);
    cJSON_Delete(json);
}
