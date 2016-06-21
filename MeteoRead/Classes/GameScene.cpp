#include "GameScene.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;

//移動量
const float PlayerSpeed = 0.1f;

//公転する星との距離
const float Hosikoutenn = 80.0f;

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

	//ゲームシーンの作成
	auto GameLayer = Stage1::create();
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(GameLayer);
	_stage1 = GameLayer;

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//マイフレーム更新作業を実行させる
	this->scheduleUpdate();

	//回転する星をリセットする
	axishosi = 0;

	//ゴールする星に入れる名前の設定
	goalmai = std::string("goal");
	goalset = false;
	goalflg = false;

	auto _st = Start::create();
	this->addChild(_st);
	_start = _st;;

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){

	//必要な情報を獲得する
	bool Start = _start->getStart();
	bool goal = _stage1->getgoalflg();
	bool touch = _UILayer->getTouch();

	//ゲーム中なら
	if (Start == true && goal == false){
		_stage1->setrocketpower(_UILayer->getmeterReturn());
		_stage1->setbottontouch((int)touch);
	}
	else{
		_stage1->setrocketpower(_stage1->getRocketPower());
		if (goal == true&&goalflg == false){
			goalflg = true;
			auto goal = Goal::create();
			this->addChild(goal);
		}
	}
}