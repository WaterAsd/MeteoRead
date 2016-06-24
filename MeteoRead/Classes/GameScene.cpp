#include "GameScene.h"
#include "asada/Rocket.h"
#include "asada/Start.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//BGM（SimpleAudioEngine）使うために必要
using namespace CocosDenshion;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Rocket *GameScene::_rocket;

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

	//BGM
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("BGM/BGMGame.mp3");

	//画面サイズを獲得する
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景画像の作成
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//星を出現させる
	auto hosimei = std::string("Earth.png");
	StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200),hosimei);
	StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200),hosimei);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100),hosimei);
	StarSet(Vec2(visibleSize.width / 2 , visibleSize.height / 2 ),hosimei);

	//ロケットを出現させる
	auto rocket = Rocket::create();
	rocket->setPosition(visibleSize.width,0);
	rocket->setRotation(-90);
	this->addChild(rocket);
	_rocket = rocket;

	//道の出現
	auto road = Road::create();
	this->addChild(road);
	_road = road;

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

	//押したか胴かを判定するための処理を記入する
	touchOK = false;

	//ゴールする星に入れる名前の設定
	goalmai = std::string("goal");
	goalset = false;
	goalflg = false;
	GoalStarset(Vec2(200, visibleSize.height - 200),goalmai);


	auto _st = Start::create();
	this->addChild(_st);
	_start = _st;

	return true;
}

//マイフレーム更新関数
void GameScene::update(float delta){

	float power;
	//必要な素材を作成する
	if (_start->getStart() == true)
		power = _rocket->getSpeed() + _UILayer->getmeterReturn();
	else
		power = _rocket->getSpeed();

	//配列に入っている星の数までfor分で処理する
	//内容：ロケットに近く星があるかどうか（複数個あるなら一番近い場所を選択する）
	if (_rocket->getRevolutionflg() == false){
		Earth*karihosi = axishosi;
		float smoleLength = NULL;
		for (auto hosis : stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= Hosikoutenn && (length < smoleLength || smoleLength == NULL)&&karihosi!=hosis){
				axishosi = hosis;
				smoleLength = length;
				_rocket->setRevolutionflg(true);
			}
		}
	}

	//ゴールの星に公転できたらクリア画面を出す。
	if (_rocket->getRevolutionflg() == true &&
							axishosi->getName() == goalmai&&
							goalflg == false){
		auto _st = Start::create();
		this->addChild(_st);
		_start = _st;
		goalflg = true;
	}

	/*公転フラグがtrueでUiLayerのtouchがtrueなら
		touchOKをfalseにして発射する*/
	if (_rocket->getRevolutionflg() == true &&
		_UILayer->touch == false &&
		touchOK == true){
		touchOK = false;
		_rocket->setRevolutionflg(false);
	}

	/*公転フラグがtrueで、UiLayerのtouchがfalseなら
		touchOKをtrueにして発射の準備をする*/
	if (_rocket->getRevolutionflg() == true &&
		_UILayer->touch == true){
		touchOK = true;
	}
	//もし公転フラグがtrueならば公転させて、
	//falseならば、向いてる方向に移動させる。
	if (_rocket->getRevolutionflg() == true){
		_Cal->angle(axishosi, _rocket, power);//公転させる
	}else{
		_Cal->move(_rocket, power);//直進運動させる
	}

	//もしボタンを押しているのなら矢印を表示させる。

	auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);
	
	_Cal->hosiangle(hosi1,hosi2,1.0f);

	RoPos = _rocket->getPosition();

}

//星を出現させる
void GameScene::StarSet(Vec2 Pos,std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//星の数増やす。
	stars.pushBack(earth);//星の情報を保存する。
	//starsname.pushBack(hosimei);//星の名前を取得しておく
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

//ゴールに必要な星を作成する
/*
@Pos:星の場所を設定する
＠hosimei:星に入れる（setName）の文字
*/
void GameScene::GoalStarset(Vec2 Pos, std::string hosimei){
	if (goalset == true){}

	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		starCount++;//星の数増やす。
		stars.pushBack(earth);//星の情報を保存する。
		goalset == false;
	}
}
