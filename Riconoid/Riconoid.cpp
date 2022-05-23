// This file initializes Raylib and the gameplay class that is used to play the game

#include "gameplay.h";

using namespace Riconoid;

int main()
{
	// Constant variables for display
	const int screenWidth = 860;
	const int screenHeight = 640;
	const int FPS = 60;

	// Initializes Raylib
	InitWindow(screenWidth, screenHeight, "Riconoid by Ryan");
	SetTargetFPS(FPS);
	HideCursor();

	// The gameplay class used to actually play the game
	Gameplay* gameplay = new Gameplay(screenWidth, screenHeight, 10);

	gameplay->Start();

	// A while loop for processing and rendering the gameplay
	// If the "gameIsOver" boolean is set to true, that means the while loop will break out
	while (!WindowShouldClose() && !Gameplay::gameIsOver)
	{
		gameplay->Update();

		BeginDrawing();

		ClearBackground(BLACK);

		gameplay->Draw();

		EndDrawing();
	}

	// Finally, close out the game once had exited the while loop
	gameplay->Close();

	// Return no errors
	return 0;
}