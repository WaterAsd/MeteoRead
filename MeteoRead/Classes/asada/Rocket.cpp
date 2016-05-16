#include "asada\Rocket.h"
#include "asada\booster.h"

USING_NS_CC;

float ROCKETSPEED = 0.5f;
float ROCKETMOVEX = 0.0f;
float ROCKETMOVEY = 0.0f;

//初期化関数
bool Rocket::init(){
	if (!Node::init()){
		return false;
	}
	//ロケットを入れる
	auto rocket = Sprite::create("Rocket.png");
	this->addChild(rocket);
	_Rocket = rocket;

	//ブースターを入れる
	auto booster = Booster::create();
	rocket->addChild(booster);
	booster->setPosition(20, -21);
	_booster = booster;

	this->setContentSize(Size(100.0f,40.0f));

	return true;
}

//ロケットの座標を送る
Vec2 Rocket::getRocketPos(){ 
	return RocketPos;
}
//ロケットのRectを与える
Rect Rocket::getRocketRect(){
	return RocketRect;
}
//ロケットのスピードを設定する
void Rocket::setPower(int pw){ Power = pw;}
//ロケットのスピードを設定する
void Rocket::RocketSpeed(int Pw){

}

