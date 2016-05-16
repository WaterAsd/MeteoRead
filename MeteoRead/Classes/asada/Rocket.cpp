#include "asada\Rocket.h"
#include "asada\booster.h"

USING_NS_CC;

//枚数どのくらいか？
const int FRAME_COUNT = 4;
//次のアニメーションに進むための時間速度
const float ANIMATION = 5;

//初期化関数
bool Rocket::init(){
	if (!Node::init()){
		return false;
	}
	//ロケットの座標を入れる
	auto rocket = Sprite::create("Rocket.png");
	this->addChild(rocket);

	//ブースターの座法を入れる
	auto booster = Booster::create();
	rocket->addChild(booster);

	return true;
}

//ロケットの座標を送る
Vec2 Rocket::getRocketPos(){ return RocketPos; }
//ロケットのRectを与える
Rect Rocket::getRocketRect(){ return RocketRect; }
//ロケットのスピードを設定する
int Rocket::setPower(int pw){ Power = pw;}
//ロケットのスピードを設定する
void Rocket::RocketSpeed(int Pw){

}

