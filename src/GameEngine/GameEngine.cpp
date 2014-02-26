#include "GameEngine.h"

GameEngine::GameEngine()
{
	// TODO Revise the defination first, then add any initialization code you want below:
	
	m_Scene = new Scene3D();
	m_Renderer = new Renderer3D(*m_Scene);
	m_Updater = new Updater3D(*m_Scene);
}

GameEngine::~GameEngine()
{
	// TODO Delete any allocated pointers here.
	
	delete m_Scene;
	delete m_Renderer;
	delete m_Updater;
}

void GameEngine::initialize(std::string _runDir)
{
	//initializeLight();
	Shader::getInstance().initialize(_runDir);
	OBJLoader::getInstance().initialize(_runDir);
	TextureLoader::getInstance().initialize(_runDir);
	m_Scene->createScene();
}

void GameEngine::run()
{
	// TODO Better not doing anything here.
	
	updateGame();
	renderGame();
}

void GameEngine::updateGame()
{
	// TODO Add any codes that related to updating datas here
	// All calculations are recommended to be fulfilled here.
	
	FPSCounter::getInstance().update();
	m_Updater->Update(FPSCounter::getInstance().getTimeInterval());
}

void GameEngine::renderGame()
{
	// TODO Add any codes that are related drawing figures, add textures, etc.
	// should be fulfilled here.
	
	m_Renderer->Render();
	//FPSCounter::getInstance().renderFPS();
}

void GameEngine::initializeLight()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
