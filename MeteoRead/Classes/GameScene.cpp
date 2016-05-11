#include "GameScene.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;

//Scene‚ğg‚¦‚é‚æ‚¤‚É‚·‚é
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

	//‰æ–ÊƒTƒCƒY‚ğŠl“¾‚·‚é
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//”wŒi‰æ‘œ‚Ìì¬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//UiLayer‚ğéŒ¾‚·‚éB
	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	return true;
}