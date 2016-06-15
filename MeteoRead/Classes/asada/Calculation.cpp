#include "asada\/Calculation.h"
USING_NS_CC;
//Playerの移動速度
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;
float Calculation::Angle;

double s = 0.0f;//向きたい角度
Vec2 misdir = Vec2(0,1);//ミサイルの一応の向き

float PI = 3.14f;

float rot = 0.0f;
float rot1 = 0.0f;

bool Calculation::init(){
	return true;
}
//
//void Calculation::update(Rocket*rocket)
//{}

//２点のなす角を求める関数
/*
@moto:元の位置
@aite:向きたい場所の位置
*/
double Calculation::dot_product(Vec2 moto, Vec2 aite){
	return moto.x*aite.x + moto.y*aite.y;
}

//公転の処理
//内容：ロケットを公転するために使う関数
/*
@hosi 行きたい星の情報
@rocket 動かしたいロケットの情報
@power　動かしたいロケットの移動量
*/
void Calculation::angle(const Earth* hosi,Rocket*rocket,const int power){
	//必要な情報を作成する
	Vec2 A, B,C,AB,AC;
	A = rocket->getPosition();
	B = hosi->getPosition();

	//公転に必要な新しい座標を作成する
	if (power!=0)rot = power*0.01;
	if (rot >= 2.0f*PI)rot -= 2.0f*PI;
	C.x= (A.x - B.x)*cos(rot) -
							(A.y - B.y)*sin(rot) + B.x;

	C.y= (A.x- B.x)*sin(rot) +
							(A.y - B.y)*cos(rot) + B.y;

	//向きたい角度に向かせる
	float Angle = ccpToAngle(ccpSub(A,B));
	Angle = CC_RADIANS_TO_DEGREES(Angle);
	Angle *= -1;
	rocket->setRotation(Angle);

	//座標を更新する
	rocket->setPosition(C.x, C.y);
}

//星同士公転の処理
//内容：星同士を公転するために使う関数
/*
@hosi 　軸となる星の情報
@rocket 公転したい星の情報
@power　公転したい星の移動量
*/
void Calculation::hosiangle(const Earth* hosi,Earth*hosi2, const int powers){
	//必要な情報を作成する
	Vec2 A, B, C, AB, AC;
	A = hosi2->getPosition();
	B = hosi->getPosition();

	//公転に必要な新しい座標を作成する
	if (powers != 0)rot1 = powers*0.01;
	if (rot1 >= 2.0f*PI)rot1 -= 2.0f*PI;
	C.x = (A.x - B.x)*cos(rot1) -
		(A.y - B.y)*sin(rot1) + B.x;

	C.y = (A.x - B.x)*sin(rot1) +
		(A.y - B.y)*cos(rot1) + B.y;

	//座標を更新する
	hosi2->setPosition(C.x, C.y);
}


//ロケットを向いてる方向に動かす。
void Calculation::move(Rocket*rocket, const int power){
	double del = rocket->getRotation();
	del *= -1;
	del += 90;
	if (del >= 360.0f)del -= 360.0f;
	del = CC_DEGREES_TO_RADIANS(del);
	Vec2 c;
	c.x = (power)*cosf(del);
	c.y = (power)*sinf(del);
	Vec2 a = rocket->getPosition();
	Vec2 AC = a + c;
	rocket->setPosition(AC.x, AC.y);
}