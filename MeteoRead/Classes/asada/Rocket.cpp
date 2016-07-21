#include "asada\Rocket.h"
#include "asada\booster.h"
#include "asada/Calculation.h"

USING_NS_CC;

//ロケットの移動に関する変数名
float ROCKETSPEED = 0.5f;
float ROCKETMOVEX = 0.0f;
float ROCKETMOVEY = 0.1f;

//円周率に関する変数の作成
float pi = 3.14f;

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
	rot = 0;

	//変数を与えている。
	_rockcetstate = rocketstate::FLY;
	_rocketcolstate = rocketcolState::FRY;

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
	Arrow->setVisible(false);
	rocket->addChild(Arrow,-2);
	_arrow = Arrow;

	this->scheduleUpdate();

	//公転フラグをfalseにさせておく
	revolutionflg = false;

	return true;
}

//マイフレーム処理
void Rocket::update(float dt){
	_arrow->setVisible(_flgarrow);
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
void Rocket::move(float speed){
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

//星に対して公転する
void Rocket::Col(const Earth *ea, int speed){
	//必要な情報を作成する
	Vec2 A, B, C, AB, AC;
	A = this->getPosition();
	B = ea->getPosition();

	//公転に必要な新しい座標を作成する
	switch (_rocketcolstate)
	{
	case rocketcolState::LEFT:rot = -speed*pi / 180; break;
	case rocketcolState::RIGHT:rot = speed*pi / 180; break;
	}
	C.x= (A.x - B.x)*cos(rot) -
							(A.y - B.y)*sin(rot) + B.x;

	C.y= (A.x- B.x)*sin(rot) +
							(A.y - B.y)*cos(rot) + B.y;

	float Angle;
	//向きたい角度に向かせる
	switch (_rocketcolstate)
	{
	case rocketcolState::LEFT:Angle = ccpToAngle(ccpSub(B,A)); break;
	case rocketcolState::RIGHT:Angle = ccpToAngle(ccpSub(A, B)); break;
	}
	Angle = CC_RADIANS_TO_DEGREES(Angle);
	Angle *= -1;
	this->setRotation(Angle);

	//座標を更新する
	this->setPosition(Vec2(C.x, C.y));
}

//右回転なのか左回転なのかを調べる方法
void Rocket::LRCol(const Earth*earth,float speed){
	Vec2 A = this->getPosition();
	Vec2 B = earth->getPosition();
	Vec2 C = movekari(speed);
	Vec2 AB = Vec2((B.x - A.x), (B.y - A.y));
	Vec2 AC = Vec2((C.x - A.x), (C.y - A.y));
	float Cols = (AB.x*AC.y) - (AB.y*AC.x);
	if (Cols == 0){
		_rocketcolstate = rocketcolState::MIDDLE;
	}
	if (Cols > 0){
		_rocketcolstate = rocketcolState::LEFT;
	}
	if (Cols < 0){
		_rocketcolstate = rocketcolState::RIGHT;
	}
}

Vec2 Rocket::movekari(float speed){
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
	return AC;
}

//矢印を出してもよいかを確認する処理
void Rocket::setArrow(const bool flg){
	_flgarrow = flg;
}
