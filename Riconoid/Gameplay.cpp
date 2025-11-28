#include <string>
#include "gameplay.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"

// This file represents the gameplay class functionality

using namespace Riconoid;

// Initialize the gameplay's static variables to be used globally
int Gameplay::screenWidth;
int Gameplay::screenHeight;
int Gameplay::borderPadding;
int Gameplay::score;
int Gameplay::bricksLeft;
int Gameplay::lives;
bool Gameplay::gameIsOver;

// Theses vectors are also static; which are the integral "lists" for the game
std::vector<GameObject*> Gameplay::gameObjects;
std::vector<GameObject*> Gameplay::pendingDeletion;

void Gameplay::Start()
{
	// The very beginning function that launches the game by setting up all necessary gameplay features
	// - The player paddle
	// - The ball
	// - The bricks

	float padding = borderPadding;

	Paddle* paddle = new Paddle({ (float)(screenWidth / 2), (float)(screenHeight - 40) }, { 40, 10 }, borderPadding, screenWidth - borderPadding);
	paddle->colliderColour = RED;

	gameObjects.push_back(paddle);

	Ball* ball = new Ball(10, 5, 20, 0.05f);
	ball->colliderColour = YELLOW;
	ball->Reset({ (float)(Gameplay::screenWidth / 2), (float)(Gameplay::screenHeight - 50) });

	gameObjects.push_back(ball);

	GameObject* topWall = new GameObject({ 0, 0 }, { padding - 1, padding }, { (float)(screenWidth - padding + 2), padding });
	GameObject* leftWall = new GameObject({ 0, 0 }, { padding - 1, (float)screenHeight }, { padding - 1, padding });
	GameObject* rightWall = new GameObject({ 0, 0 }, { (float)(screenWidth - padding + 2), padding }, { (float)(screenWidth - padding + 2), (float)screenHeight });
	topWall->colliderColour = RED;
	leftWall->colliderColour = RED;
	rightWall->colliderColour = RED;

	gameObjects.push_back(topWall);
	gameObjects.push_back(leftWall);
	gameObjects.push_back(rightWall);

	BuildBricks();
}

void Gameplay::BuildBricks()
{
	// This function builds out the bricks in their respective formation and colour

	float padding = borderPadding;

	int brickWidth = 20;
	int brickHeight = 10;
	int columns = (screenWidth - (padding * 2)) / (brickWidth * 2);
	int rows = 6;

	for (int j = 0; j < rows; j++)
	{
		Color colour = { GetRandomValue(0, 255),  GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };

		for (int i = 0; i < columns; i++)
		{
			float x = padding + brickWidth + ((brickWidth * 2) * i);
			float y = padding + (brickHeight * 8) + ((brickHeight * 2) * j);

			Brick* brick = new Brick({ x, y }, { (float)brickWidth, (float)brickHeight });
			brick->colliderColour = colour;

			gameObjects.push_back(brick);

			Gameplay::bricksLeft++;
		}
	}
}

void Gameplay::Update()
{
	// This is where gameplay is processed every frame
	// - Game object updating
	// - Deletion of pending-to-be-deleted game objects

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Update();

		if (gameObject->pendingDeletion)
			pendingDeletion.push_back(gameObject);
	}

	for (GameObject* gameObject : pendingDeletion)
	{
		auto itr = std::remove(gameObjects.begin(), gameObjects.end(), gameObject);
		gameObjects.erase(itr, gameObjects.end());

		delete[] gameObject;
	}

	pendingDeletion.clear();
}

void Gameplay::Draw()
{
	// This is where game objects are drawn every frame

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw();
	}

	std::string score_s1 = "Score: ";
	std::string score_s2 = score_s1.append(std::to_string(Gameplay::score));

	DrawText(score_s2.c_str(), 20, 20, 20, RED);

	std::string lives_s1 = "Lives: ";
	std::string lives_s2 = lives_s1.append(std::to_string(Gameplay::lives));

	DrawText(lives_s2.c_str(), 20, 45, 20, RED);
}

void Gameplay::Close()
{
	// Clear the game object vectors as a "good practice", even though it's not really necessary since the game is ending anyway

	gameObjects.clear();
	pendingDeletion.clear();
}