#include "config.h"
#include "events.h"
#include <nuklear.h>
#include "nuklear.h"
#include <SDL2/SDL.h>
#include "nuklearManager.h"
#include "renderer.h"
enum Menu {
    None = 0,
    SplashScreen = 1,
    MainMenu = 2,
    Options = 3
};

enum Menu currentMenu = SplashScreen;

void changeMenu(enum Menu menu) {
    currentMenu = menu;
}

vec3 backColor = {0, 1, 0};
struct nk_colorf colorf;

void displayMenu() {
    switch(currentMenu) {
        case None:
            if(isKeyPressed(SDL_SCANCODE_O)) {
                currentMenu = SplashScreen;
            }
            return;
        

        case SplashScreen:
            if(nk_begin(getContext(), "Splash Screen", nk_rect(200, 200, getWindowWidth() - 400, getWindowHeight() - 400), NK_WINDOW_TITLE|NK_WINDOW_BORDER|NK_WINDOW_MOVABLE)) {
                nk_layout_row_dynamic(getContext(), 30, 1);
                nk_spacer(getContext());
                nk_label(getContext(), "FBLA 2024-2025 Financial App", NK_TEXT_CENTERED);
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_layout_row_dynamic(getContext(), 40, 7);
                nk_spacer(getContext());
                if(nk_button_label(getContext(), "OK")) {
                    changeMenu(MainMenu);
                }
            }
            nk_end(getContext());
            break;


        case MainMenu:
            if(nk_begin(getContext(), "Main Menu", nk_rect(50, 50, getWindowWidth() - 100, getWindowHeight() - 100), NK_WINDOW_TITLE|NK_WINDOW_BORDER|NK_WINDOW_MOVABLE)) {
                nk_layout_row_dynamic(getContext(), 30, 1);
                nk_label(getContext(), "Choose a Function", NK_TEXT_CENTERED);
                nk_spacer(getContext());
                nk_layout_row_dynamic(getContext(), 40, 4);
                nk_spacer(getContext());
                if(nk_button_label(getContext(), "Options")) {
                    changeMenu(Options);
                }
            }
            nk_end(getContext());
            break;

        case Options:
            if(nk_begin(getContext(), "Options", nk_rect(150, 150, getWindowWidth() - 300, getWindowHeight() - 300), NK_WINDOW_TITLE|NK_WINDOW_BORDER|NK_WINDOW_MOVABLE)) {
                nk_layout_row_dynamic(getContext(), 30, 1);
                nk_label(getContext(), "Options", NK_TEXT_CENTERED);
                nk_spacer(getContext());
                nk_label(getContext(), "Set Background Color", NK_TEXT_ALIGN_LEFT);
                nk_layout_row_dynamic(getContext(), 225, 4);
                nk_color_pick(getContext(), &colorf, NK_RGB);
                backColor.x = colorf.r;
                backColor.y = colorf.g;
                backColor.z = colorf.b;
                setBackgroundColor(backColor.x, backColor.z, backColor.y);
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_layout_row_dynamic(getContext(), 30, 5);
                nk_spacer(getContext());
                nk_spacer(getContext());
                if(nk_button_label(getContext(), "Save BG Color")) {
                    cfgSetVec3("bg", backColor);
                }
            }
            nk_end(getContext());
            break;
    }
}
