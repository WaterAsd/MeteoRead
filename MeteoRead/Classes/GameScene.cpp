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
	//initが存在しない場合は消す
	if (!Layer::init()){
		return false;
	}

	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	return true;
}