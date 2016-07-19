#include "GameScene.h"
#include "KBT\GameOver.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
//BGM（SimpleAudioEngine）使うために必要
using namespace CocosDenshion;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Vec2 GameScene::goalPos;
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
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Space,0);

	//ゲームシーンの作成
	auto GameLayer = Stage::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0, 0);
	GameLayer->StageCreate(SelectCount);
	this->addChild(GameLayer, 1);
	_stage1 = GameLayer;

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer,2);
	_UILayer = uiLayer;

	//マイフレーム更新作業を実行させる
	this->scheduleUpdate();

	//回転する星をリセットする
	axishosi = 0;

	//ゴールする星に入れる名前の設定
	goalmai = std::string("goal");
	Statics::clearFlg = false;

	Statics::gameOverFlg = false;

	auto _st = Start::create();
	this->addChild(_st,3);
	_start = _st;

	//タッチの処理を実行する
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
		if (_UILayer->getTouch() == true)return false;
		touchpoint = touch->getLocation();
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
		auto _Touch = touch->getLocation();
		auto move = _Touch - touchpoint;
		auto getstage = _stage1->getPosition();
		_stage1->setPosition(getstage - move);
		touchpoint = _Touch;
	};
	listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {

	};
	listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {

	};

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//BGM
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("BGM/BGMGame.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("BGM/BGMGame.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/BGMGame.mp3", true);

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){

	//必要な情報を獲得する
	_Start = _start->getStart();
	_goal = Statics::clearFlg;
	_touch = Statics::touchFlg;


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
