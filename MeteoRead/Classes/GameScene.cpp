#include "GameScene.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
int GameScene::SelectCount;

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
	this->addChild(Space);

	//ゲームシーンの作成
	auto GameLayer = Stage1::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0, 0);
	GameLayer->stagecreate(SelectCount);
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

	////タッチの処理を実行する
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
	//	if (_UILayer->getTouch() == true)return false;
	//	touchpoint = touch->getLocation();
	//	_stage1->stopRocket();
	//	return true;
	//};
	//listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
	//	auto _Touch = touch->getLocation();
	//	auto move = _Touch - touchpoint;
	//	auto getstage = _stage1->getPosition();
	//	_stage1->setPosition(getstage + move);
	//	touchpoint = _Touch;
	//};
	//listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {

	//};
	//listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {

	//};

	//auto dispatcher = Director::getInstance()->getEventDispatcher();
	//dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){

	//必要な情報を獲得する
	_Start = _start->getStart();
	_goal = _stage1->getgoalflg();
	_touch = _UILayer->getTouch();

	//UiLayerに送るために必要な情報を入れる
	minimapdate();
	if (_touch == true) _stage1->follorRocket(_stage1->_rocket);

	//ゲーム中なら
	if (_Start == true && _goal == false){
		_stage1->setrocketpower(_UILayer->getmeterReturn());
		_stage1->setbottontouch((int)_touch);
	}
	else{
		_stage1->setrocketpower(_stage1->getRocketPower());
		if (_goal == true && goalflg == false){
			goalflg = true;
			auto goal = Goal::create();
			this->addChild(goal);
		}
	}
}

//現在遊んでいるゲームを取得する
void GameScene::getStage(int count){

}

void GameScene::minimapdate(){
	//ゲームシーンから必要な情報を取得する
	auto rocketpos = _stage1->getrocket();
	auto starcount = _stage1->getstarcount();
	vector<Vec2> starspos;
	for (int i = 0; i < starcount; i++){
		auto star = _stage1->getstar(i);
		starspos.push_back(star);
	}
	auto rect = _stage1->getstagesize();
	auto goalpos = _stage1->getgoal();

	//UiSceneに必要の変数の値を上げる
	_UILayer->getRocketPos(rocketpos);
	for (auto star : starspos){ _UILayer->getStarsPos(star);}
	_UILayer->getStageRect(rect);
	_UILayer->getgoalPos(goalpos);
}
