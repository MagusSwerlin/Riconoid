#include <vector>
#include "gameobject.h"

// Defines the game's gameplay class

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Riconoid
{
	class Gameplay
	{
	public:
		static int screenWidth;
		static int screenHeight;
		static int borderPadding;
		static int lives;
		static int score;
		static int bricksLeft;
		static bool gameIsOver;

		static std::vector<GameObject*> gameObjects;
		static std::vector<GameObject*> pendingDeletion;

		Gameplay(int screenWidth, int screenHeight, int borderPadding)
		{
			this->screenWidth = screenWidth;
			this->screenHeight = screenHeight;
			this->borderPadding = borderPadding;

			lives = 3;
			score = 0;
			bricksLeft = 0;
			gameIsOver = false;
		}

		void Start();
		static void BuildBricks();
		void Update();
		void Draw();
		void Close();
	};
}

#endif