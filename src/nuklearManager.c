#include "nuklearManager.h"
#include <SDL2/SDL_mouse.h>
#include <stdbool.h>
#include "window.h"
#include "files.h"
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION
#include <GL/glew.h>
#include <nuklear.h>
#include <nuklear_sdl_gl3.h>
#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024
struct nk_context* ctx;
struct nk_font_atlas* atlas;

struct nk_font* fonts[6];

void initNuklear() {
    ctx = nk_sdl_init(getWindow());
    {
        nk_sdl_font_stash_begin(&atlas);
        //reg24
        fonts[0] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Regular.ttf"), 24, 0);
        //bold24
        fonts[1] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Bold.ttf"), 24, 0);
        //itl24
        fonts[2] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Italic.ttf"), 24, 0);
        //reg30
        fonts[3] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Regular.ttf"), 30, 0);
        //bold30
        fonts[4] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Bold.ttf"), 30, 0);
        //itl30
        fonts[5] = nk_font_atlas_add_from_file(atlas, res("fonts/ClearSans-Italic.ttf"), 30, 0);
        nk_sdl_font_stash_end();
        nk_style_set_font(ctx, &fonts[0]->handle);
    }
}

void renderNuklear() {
    nk_sdl_render(NK_ANTI_ALIASING_OFF, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
}

struct nk_font** getFont(int font) {
    return &fonts[font];
}

struct nk_context* getContext() {
    return ctx;
}

