#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "App/App.hpp"

App app;

void UpdateDrawFrame();

int main(void)
{
	app.Init();
	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		//SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	app.Update();
	app.Draw();
}