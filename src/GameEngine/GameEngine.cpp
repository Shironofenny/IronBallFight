#include "GameEngine.h"

GameEngine::GameEngine()
{
	// TODO: Revise the defination first, then add any initialization code you want below:
	
	m_Scene = new Scene3D();
	//m_Scene->createScene();
	m_Renderer = new Renderer3D(*m_Scene);
	m_Updater = new Updater3D(*m_Scene);
	m_Scene->createScene();
}

GameEngine::~GameEngine()
{
	// TODO: Delete any allocated pointers here.
	
	delete m_Scene;
	delete m_Renderer;
	delete m_Updater;
}

void GameEngine::run()
{
	// TODO: Better not doing anything here.
	
	updateGame();
	renderGame();
}

void GameEngine::updateGame()
{
	// TODO: Add any codes that related to updating datas here
	// 	All calculations are recommended to be fulfilled here.
	
	m_Updater->Update(sceneUtility::gDt);
}

void GameEngine::renderGame()
{
	// TODO: Add any codes that are related drawing figures, add textures, etc.
	// 	should be fulfilled here.
	
	m_Renderer->Render();
}
