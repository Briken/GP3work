#include "MainGame.h"
#include "Camera.h"
#include <iostream>
#include <string>



Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
					Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
					Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };

unsigned int indices[] = { 0, 1, 2 };



MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	Display* _gameDisplay = new Display(); //new display
	Mesh* mesh;
	for (int i = 0; i < 1; i++)
	{
		mesh = new Mesh();
		sceneGraph[i] = mesh;
	}
    //Mesh* mesh1();
	//Mesh* mesh2();
	
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems(); 
	gameLoop();
}

void MainGame::initSystems()
{
	_gameDisplay.initDisplay(); 
	//mesh1.loadModel("../res/Zuccarello.obj");
	//mesh2.loadModel("../res/monkey3.obj");
	//for (int i = 0; i < modelPaths->length(); i++)
	//{
		sceneGraph[0]->loadModel(modelPaths[0]);
	//}

	myCamera.initCamera(glm::vec3(0, 0, -5), 70.0f, (float)_gameDisplay.getWidth()/_gameDisplay.getHeight(), 0.01f, 1000.0f);
	counter = 0.0f;
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				OnQuit();
				break;
			case SDL_KEYDOWN:
				OnKeyDown(evnt.key.keysym.sym);
				if (evnt.key.keysym.sym == SDLK_ESCAPE)
				{
					OnQuit();
				}
		}
	}
	
}


void MainGame::drawGame()
{
	_gameDisplay.clearDisplay(0.0f, 0.0f, 0.0f, 1.0f);
	
	Shader shader("../res/shader"); //new shader
	Texture texture("../res/bricks.jpg"); //load texture
	Texture texture1("../res/water.jpg"); //load texture
	
	sceneGraph[0]->transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
	sceneGraph[0]->transform.SetRot(glm::vec3(0.0, counter * 5, counter * 5));
	sceneGraph[0]->transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));

	

	shader.Bind();
	shader.Update(sceneGraph[0]->transform, myCamera);
	texture.Bind(0);
	//mesh1.draw();
	//mesh2.draw();
	
	//for (int i = 0; i < modelPaths->length(); i++)
	//{
		sceneGraph[0]->draw();
	//}

	CheckCollisions();
	counter = counter + 0.01f;
				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
}

void MainGame::CheckCollisions()
{
	//for (int i; i < noModels; i++)
	//{
	//	if (sceneGraph[i])
	//	{

	//	}
	//}
}

void MainGame::OnKeyDown(SDL_Keycode keyCode)
{
	if (keyCode == SDLK_w)
	{
		myCamera.MoveForward(10);
	}
	if (keyCode == SDLK_a)
	{
		myCamera.MoveRight(-20);
	}
	if (keyCode == SDLK_s)
	{
		myCamera.MoveForward(-20);
	}
	if (keyCode == SDLK_d)
	{
		myCamera.MoveRight(20);
	}
}

void MainGame::OnQuit()
{
	_gameState = GameState::EXIT;
}
