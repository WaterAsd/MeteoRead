#include "GameScene.h"
#include "KBT\GameOver.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
int GameScene::SelectCount;
bool GameScene::gameOver;

//移動量
const float PlayerSpeed = 0.1f;

//公転する星との距離
const float Hosikoutenn = 80.0f;

//セレクトシーンで選択した数字をステージに変更する


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
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//背景画像の作成
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//ゲームシーンの作成
	auto GameLayer = Stage1::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0,0);
	GameLayer->stageSelect(SelectCount);
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
	_start = _st;

	//タッチの処理を実行する
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
		if (_UILayer->getTouch() == true)return false;
		touchpoint = touch->getLocation();
		_stage1->stopRocket();
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
		auto Touch = touch->getLocation();
		auto move = Touch - touchpoint;
		auto getstage = _stage1->getPosition();
		_stage1->setPosition(Vec2::ZERO);
		touchpoint = _stage1->getPosition();

	};
	listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {
		
	};
	listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {
		
	};

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	gameOver = false;

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){

	//必要な情報を獲得する
	_Start = _start->getStart();
	_goal = _stage1->getgoalflg();
	_touch = _UILayer->getTouch();

	//ゲーム中なら
	if (_Start == true && _goal == false){
		_stage1->setrocketpower(_UILayer->getmeterReturn());
		_stage1->setbottontouch((int)_touch);
	}
	else{
		_stage1->setrocketpower(_stage1->getRocketPower());
		if (_goal == true&&goalflg == false){
			goalflg = true;
			auto goal = Goal::create();
			this->addChild(goal);
		}
	}

	//画面外に出たらゲームオーバー
	if (RoPos.x < 0 || visibleSize.width < RoPos.x || RoPos.y < 0 || visibleSize.height < RoPos.y)
	{
		gameOver = true;
	}
	if (gameOver)
	{
		auto _st = GameOver::create();
		this->addChild(_st);
	}
}

//現在遊んでいるゲームを取得する
void GameScene::getStage(int count){

}
