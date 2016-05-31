#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;

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
	rocket->setPosition(100,100);
	rocket->setRotation(30);
	this->addChild(rocket);
	_rocket = rocket;

	//計算機を使えるようにする
	auto Cal = Calculation::create();
	_Cal = Cal;

	//UiLayerを宣言する。
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//マイフレーム更新作業を実行させる
	this->scheduleUpdate();

	//回転する星をリセットする
	axishosi = 0;

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){
	

	//必要な素材を作成する
	float smoleLength = NULL;
	float power = _rocket->getSpeed() + _UILayer->getmeterReturn();

	//配列に入っている星の数までfor分で処理する
	//内容：ロケットに近く星があるかどうか（複数個あるなら一番近い場所を選択する）
	if (_rocket->getRevolutionflg() == false){
		for (auto hosis : stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= 100.0f && (length < smoleLength || smoleLength == NULL)){
				axishosi = hosis;
				smoleLength = length;
				_rocket->setRevolutionflg(true);
			}
		}
	}

	//もし公転フラグがtrueならば公転させて、
	//falseならば、向いてる方向に移動させる。
	if (_rocket->getRevolutionflg() == true)
		_Cal->angle(axishosi, _rocket,power);//公転させる
	else
		_Cal->move(_rocket,power);//直進運動させる
}

//星を出現させる
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//星の数増やす。
	stars.pushBack(earth);//星の情報を保存する。
}

//現在近い星があるかどうかを検出する
/*
@*hosi:もし存在するなら使用するので保存する
*/
void GameScene::selectSter(Earth*hosi){
	float smoleLength = NULL;
	Earth*karihosi = 0;
	//配列に入っている星の数までfor分で処理する
	//内容：ロケットに近く星があるかどうか（複数個あるなら一番近い場所を選択する）
	for (auto hosis : stars){
		float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
		if (length <= 100.0f && (length < smoleLength || smoleLength == NULL)){
			karihosi = hosis;
			smoleLength = length;
			_rocket->setRevolutionflg(true);
		}
	}
	hosi = karihosi;
}
