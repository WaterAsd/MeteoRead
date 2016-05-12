#include "GameScene.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;

//Sceneを使えるようにする
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

	//画面サイズを獲得する
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景画像の作成
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//星を出現させる
	auto earth = Earth::create();
	earth->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(earth);

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	return true;
}