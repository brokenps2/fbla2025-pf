#pragma once

enum Menu {
    SplashScreen = 0,
    MainMenu = 1
};

void displayMenu();

void changeMenu(enum Menu menu);
