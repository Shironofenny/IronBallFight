#include "AnimationEngine.h"

AnimationEngine::AnimationEngine()
{
	// TODO: Revise the defination first, then add any initialization code you want below:
	
	mScene = new Scene2D();
	//mScene->createScene();
	mRenderer = new Renderer2D(*mScene);
	mUpdater = new Updater2D(*mScene);
	mScene->createScene();
}

AnimationEngine::~AnimationEngine()
{
	// TODO: Delete any allocated pointers here.
	
	delete mScene;
	delete mRenderer;
	delete mUpdater;
}

void AnimationEngine::run()
{
	// TODO: Better not doing anything here.
	
	updateAnimation();
	renderAnimation();
}

void AnimationEngine::updateAnimation()
{
	// TODO: Add any codes that related to updating datas here
	// 	All calculations are recommended to be fulfilled here.
	
	mUpdater->Update(gDt);
}

void AnimationEngine::renderAnimation()
{
	// TODO: Add any codes that are related drawing figures, add textures, etc.
	// 	should be fulfilled here.
	
	mRenderer->Render();
}
