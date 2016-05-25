#include "asada\/Calculation.h"
USING_NS_CC;
//Playerの移動速度
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;
bool Calculation::init(){
	return true;
}

//角度の計算表
void Calculation::angle(Earth* hosi, Rocket*rocket, int power){

	//もしGameSceneが更新されて消えたらこれをGameSceneのupdate内に入れてほしい
	//ロケットと目的の星を検出する。
	//auto vec2hosi = stars.at(1);
	//_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	/*これでこの仕組みは動く*/


	//角度を求める
	float angle = ccpToAngle(ccpSub(hosi->getPosition(), rocket->getPosition()));
	//移動量を決める
	float PlayerMoveX = power*cos(angle);
	float PlayerMoveY = power*sin(angle);
	//条件が成立しているなら実際に移動させる
	if (ccpDistance(rocket->getPosition(), hosi->getPosition()) > 1.0f){
		float PlayerNewX = rocket->getPosition().x + PlayerMoveX;
		float PlayerNewY = rocket->getPosition().y + PlayerMoveY;
		rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));
	}
}