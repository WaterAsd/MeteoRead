#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Rocket* GameScene::_rocket;

//移動量
const float PlayerSpeed = 0.1f;

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
	StarSet(visibleSize/2);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
	StarSet(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));

	//ロケットを出現させる
	auto rocket = Rocket::create();
	rocket->setPosition(300,300);
	this->addChild(rocket);
	_rocket = rocket;

	//計算機を使えるようにする
	auto Cal = Calculation::create();
	_Cal = Cal;

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//道の出現
	auto road = Road::create();
	this->addChild(road);
	_road = road;

	//マイフレーム更新作業を実行させる
	this->scheduleUpdate();

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){
	auto vec2hosi = stars.at(0);
	auto vec2 = vec2hosi->getPosition();
	vec2.x += 0.1f;
	vec2hosi->setPosition(vec2);
	_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	RoPos = _rocket->getPosition();
}

//星を出現させる
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//星の数増やす。
	stars.pushBack(earth);//星の情報を保存する。
}

void GameScene::move(){
	//ＵＩのパワーをロケットに与えてスピード変更している。
	RoPos = _rocket->getPosition();
	_rocket->setPower(_UILayer->getmeterReturn());
	RoPos = Vec2(RoPos.x, RoPos.y + _rocket->getPower());
	_rocket->setPosition(RoPos);

	//ポジションの位置が画面越したら
	if (_rocket->getPositionY() > 600){
		_rocket->setPosition(Vec2(_rocket->getPositionX(), 0));
	}
}

void GameScene::move2(){
	//ロケットと目的の星を検出する。
	auto vec2hosi = stars.at(1);

	//角度を求める
	float angle = ccpToAngle(ccpSub(_rocket->getPosition(),vec2hosi->getPosition()));

	//移動量を決める
	float PlayerMoveX = _UILayer->getmeterReturn()*cos(angle);
	float PlayerMoveY = _UILayer->getmeterReturn()*sin(angle);

	//条件が成立しているなら実際に移動させる
	if (ccpDistance(_rocket->getPosition(), vec2hosi->getPosition()) > 1.0f){
		float PlayerNewX = _rocket->getPosition().x - PlayerMoveX;
		float PlayerNewY = _rocket->getPosition().y - PlayerMoveY;
		_rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));
	}
}