#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "Audio.h"
#include <vector>

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void CheckCollisions();
	void OnKeyDown(SDL_Keycode keyCode);
	void OnQuit();

	Display _gameDisplay;
	GameState _gameState;
	Mesh mesh1;
	Mesh mesh2;
	Camera myCamera;
	//std::vector<Mesh*> sceneGraph;
	Mesh* sceneGraph[1];
	Audio audioManager;
	string modelPaths[1] = {"../res/Mew_Pokemon_OBJ.obj" };

	int noModels;

	float counter;


};

