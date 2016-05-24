#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;


Vec2 GameScene::RoPos;

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
	rocket->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(rocket);
	_rocket = rocket;

	//ロケットのサイズを調べる為にNodeに画像を張る
	auto lc = LayerColor::create(Color4B(255, 0, 0, 255),rocket->getContentSize().width,rocket->getContentSize().height);
	lc->setPosition(Vec2(rocket->getContentSize().width / 2, rocket->getContentSize().height / 2));
	rocket->addChild(lc);

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//マイフレーム更新作業を実行させる
	this->scheduleUpdate();

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){
	//ＵＩのパワーをロケットに与えてスピード変更している。
	RoPos = _rocket->getPosition();
	_rocket->setPower(_UILayer->getmeterReturn());
	RoPos = Vec2(RoPos.x, RoPos.y + _rocket->getPower());
	_rocket->setPosition(RoPos);

	//ポジションの位置が画面越したら
	if (_rocket->getPositionY() > 600){
		_rocket->setPosition(Vec2(_rocket->getPositionX(),0));
	}
}

//星を出現させる
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//星の数増やす。
	stars.pushBack(earth);//星の情報を保存する。
}