#include "events.h"
#include <nuklear.h>
#include "nuklear.h"
#include <SDL2/SDL.h>
#include "nuklearManager.h"
enum Menu {
    None = 0,
    SplashScreen = 1,
    MainMenu = 2
};

enum Menu currentMenu = SplashScreen;

void displayMenu() {
    switch(currentMenu) {
        case None:
            if(isKeyPressed(SDL_SCANCODE_O)) {
                currentMenu = SplashScreen;
            }
            return;
        

        case SplashScreen:
            if(nk_begin(getContext(), "Splash Screen", nk_rect(50, 50, getWindowWidth() - 100, getWindowHeight() - 100), NK_WINDOW_TITLE|NK_WINDOW_BORDER|NK_WINDOW_MOVABLE)) {
                nk_layout_row_dynamic(getContext(), 30, 1);
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_label(getContext(), "FBLA 2024-2025 Financial App", NK_TEXT_CENTERED);
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_layout_row_dynamic(getContext(), 40, 5);
                nk_spacer(getContext());
                nk_spacer(getContext());
                nk_button_label(getContext(), "OK");
            }
            nk_end(getContext());
            break;


        case MainMenu:
            return;
    }
}

void changeMenu(enum Menu menu) {
    currentMenu = menu;
}
