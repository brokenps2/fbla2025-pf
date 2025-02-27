#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include "config.h"
#include "renderer.h"
#include "events.h"
#include <stdio.h>
#include <stdbool.h>
#include <GL/glew.h>

SDL_Window* window;

void initWindow() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL init failed\n");
        exit(1);
    }
    
    const char* title = cfgLookupString("title");

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, cfgLookupInt("width"), cfgLookupInt("height"), SDL_WINDOW_OPENGL);

    SDL_SetWindowResizable(window, true);

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    
    const GLenum err = glewInit();
    glewExperimental = GL_TRUE;
    if (GLEW_OK != err) {
        printf("GLEW Error: %s", glewGetErrorString(err));
        exit(1);
    }

    glViewport(0, 0, cfgLookupInt("width"), cfgLookupInt("height"));
}

void updateWindow() {

    if(isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        exit(1);
    }

    updateRenderer();

    SDL_GL_SwapWindow(window);

}

SDL_Window* getWindow() {
    return window;
}
