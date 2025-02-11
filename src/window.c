#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

SDL_Window* window;

void createWindow() {
	window = SDL_CreateWindow("fbla2025-pf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if(!window) {
		printf("failed to create window\n");
		exit(1);
	}
	
}
