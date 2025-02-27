#include <GL/glew.h>
#include <SDL2/SDL_surface.h>
#include "menus.h"
#include "nuklearManager.h"

float clearColor[4] = {1, 1, 1, 1};

void initRenderer() {
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}

void setClearColor(float r, float g, float b, float a) {
    clearColor[0] = r;
    clearColor[1] = g;
    clearColor[2] = b;
    clearColor[3] = a;

}

void updateRenderer() {
    glClear(GL_COLOR_BUFFER_BIT);
    renderNuklear();
    displayMenu();
}
