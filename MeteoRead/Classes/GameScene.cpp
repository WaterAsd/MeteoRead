#include "GameScene.h"

USING_NS_CC;

UILayer *GameScene::uiLayer;

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

	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	return true;
}