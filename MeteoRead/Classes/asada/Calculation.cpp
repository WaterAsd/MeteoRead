#include "asada\/Calculation.h"
USING_NS_CC;
//Playerの移動速度
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;

float PI = 3.14f;

float rot = 0.0f;

bool Calculation::init(){
	return true;
}

//角度の計算表
//内容：ロケットを動かしたい場所に移動させる
/*
@hosi 行きたい星の情報
@rocket 動かしたいロケットの情報
@power　動かしたいロケットの移動量
*/
void Calculation::angle(Earth* hosi, Rocket*rocket, int power){

	//もしGameSceneが更新されて消えたらこれをGameSceneのupdate内に入れてほしい
	//ロケットと目的の星を検出する。
	//auto vec2hosi = stars.at(1);
	//_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	/*これでこの仕組みは動く*/


	//角度を求める
	/*float angle = ccpToAngle(ccpSub(hosi->getPosition(), rocket->getPosition()));
	auto deg = CC_RADIANS_TO_DEGREES(angle);*/
	//移動量を決める
	//float PlayerMoveX = power*cos(angle);
	//float PlayerMoveY = power*sin(angle);
	////条件が成立しているなら実際に移動させる
	//if (ccpDistance(rocket->getPosition(), hosi->getPosition()) > 1.0f){
	//	float PlayerNewX = rocket->getPosition().x + PlayerMoveX;
	//	float PlayerNewY = rocket->getPosition().y + PlayerMoveY;
	//	rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));
	//}

	float RocketX = rocket->getPosition().x;
	float RocketY = rocket->getPosition().y;
	float HosiX = hosi->getPosition().x;
	float HosiY = hosi->getPosition().y;

	rot = power*0.01f;
	if (rot >= 2.0f*PI)rot -= 2.0f*PI;

	float PlayerNewX = (RocketX-HosiX)*cos(rot)-
							(RocketY - HosiY)*sin(rot) + HosiX;

	float PlayerNewY = (RocketX - HosiX)*sin(rot) +
							(RocketY - HosiY)*cos(rot) + HosiY;

	float angle = ccpToAngle(ccpSub(rocket->getPosition(),
										Vec2(PlayerNewX,PlayerNewY)));

	auto rots = rocket->getRotation();
	auto deg = CC_RADIANS_TO_DEGREES(angle);
	rocket->setRotation(deg);

	rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));

}