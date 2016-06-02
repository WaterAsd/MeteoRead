#include "asada\Rocket.h"
#include "asada\booster.h"

USING_NS_CC;

//ロケットの移動に関する変数名
float ROCKETSPEED = 0.5f;
float ROCKETMOVEX = 0.0f;
float ROCKETMOVEY = 0.1f;

//移動量に関する変数名
const int MAXPOWER = 4;

//初期化関数
bool Rocket::init(){
	if (!Node::init()){
		return false;
	}

	//一応画面サイズの取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//パワーの初期設定
	_speed = Speed::ONE;

	//ロケットを入れる
	auto rocket = Sprite::create("Rocket2.png");
	rocket->setScale(0.5f);
	this->addChild(rocket);
	_Rocket = rocket;

	//ブースターを入れる
	auto booster = Booster::create();
	rocket->addChild(booster);
	booster->setPosition(20, -20);
	_booster = booster;

	this->scheduleUpdate();

	//公転フラグをfalseにさせておく
	revolutionflg = false;

	return true;
}

//マイフレーム処理
void Rocket::update(float dt){

}

//ロケットの座標を送る
void Rocket::setRocketPos(Vec2 pos){ 
	RocketPos = pos;
}
Vec2 Rocket::getRocketPos(){
	return RocketPos;
}

//ロケットのRectを与える
void Rocket::setRocketRect(Rect rc){
	RocketRect = rc;
}
Rect Rocket::getRocketRect(){
	return _Rocket->getTextureRect();
}

//ロケットのスピードを設定する
float Rocket::getSpeed(){ return (int)_speed; }

//ロケットの公転フラグを設定する
void Rocket::setRevolutionflg(bool flg){ revolutionflg = flg; }
bool Rocket::getRevolutionflg(){ return revolutionflg; }

