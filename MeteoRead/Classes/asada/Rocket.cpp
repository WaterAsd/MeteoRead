#include "asada\Rocket.h"
#include "asada\booster.h"
#include "asada/Calculation.h"

USING_NS_CC;

//ロケットの移動に関する変数名
float ROCKETSPEED = 0.5f;
float ROCKETMOVEX = 0.0f;
float ROCKETMOVEY = 0.1f;

//円周率に関する変数の作成
float PI2 = 3.14f;

//移動量に関する変数名
const int MAXPOWER = 4;
Vec2 Rocket::RocketPos;

//初期化関数
bool Rocket::init(){
	if (!Node::init()){
		return false;
	}

	//一応画面サイズの取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	speed = 10;

	//パワーの初期設定
	_speed = Speed::ONE;

	//ロケットを入れる
	auto rocket = Sprite::create("Rocket2.png");
	rocket->setScale(0.5f);
	this->addChild(rocket);
	_Rocket = rocket;

	//ブースターを入れる
	auto booster = Booster::create();
	rocket->addChild(booster,-1);
	booster->setPosition(20, -20);
	_booster = booster;

	//矢印を入れる(基本的には出さない）
	auto Arrow = Sprite::create("Arror.png");
	Arrow->setPosition(20, 80);
	rocket->addChild(Arrow,-2);
	_arrow = Arrow;

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

//向いてる方向に移動する
void Rocket::move(const Earth*ea){
	//必要な情報を作成する
	Vec2 A, B, C, AB, AC;
	A = this->getPosition();
	B = ea->getPosition();

	//公転に必要な新しい座標を作成する
	if (speed != 0)rot = speed*0.01;
	if (rot >= 2.0f*PI2)rot -= 2.0f*PI2;
	C.x = (A.x - B.x)*cos(rot) -
		(A.y - B.y)*sin(rot) + B.x;

	C.y = (A.x - B.x)*sin(rot) +
		(A.y - B.y)*cos(rot) + B.y;

	//向きたい角度に向かせる
	float Angle = ccpToAngle(ccpSub(A, B));
	Angle = CC_RADIANS_TO_DEGREES(Angle);
	Angle *= -1;
	this->setRotation(Angle);

	//座標を更新する
	this->setPosition(C.x, C.y);
}

//星に対して公転する
void Rocket::Col(const Earth*ea){
	double del = this->getRotation();
	del *= -1;
	del += 90;
	if (del >= 360.0f)del -= 360.0f;
	del = CC_DEGREES_TO_RADIANS(del);
	Vec2 c;
	c.x = (speed)*cosf(del);
	c.y = (speed)*sinf(del);
	Vec2 a = this->getPosition();
	Vec2 AC = a + c;
	this->setPosition(AC.x, AC.y);
}

//矢印を出してもよいかを確認する処理
void Rocket::setArrow(const bool flg){
	_flgarrow = flg;
}
