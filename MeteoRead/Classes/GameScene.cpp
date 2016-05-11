#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init(){
	//init‚ª‘¶İ‚µ‚È‚¢ê‡‚ÍÁ‚·
	if (!Layer::init()){
		return false;
	}

	return true;
}