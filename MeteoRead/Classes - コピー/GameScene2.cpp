#include "GameScene2.h"
USING_NS_CC;

Scene* GameScene2::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene2::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene2::init(){
	if (!Layer::init()){
		return false;
	}
	this->setScale(2,2);
	return true;
}