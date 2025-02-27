#include "config.h"
#include "events.h"
#include "nuklearManager.h"
#include "renderer.h"
#include "window.h"

int main(int argc, char* argv[]) {

	initConfig("config.json");
	initWindow();
	initRenderer();
	initNuklear();

	while(isRunning()) {
		updateWindowEvents();
		updateWindow();
	}

	return 0;
}
