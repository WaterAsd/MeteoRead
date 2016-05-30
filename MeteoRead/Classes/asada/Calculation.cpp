#include "asada\/Calculation.h"
USING_NS_CC;
//Playerの移動速度
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;

double s = 0.0f;//向きたい角度
Vec2 misdir = Vec2(0,1);//ミサイルの一応の向き

float PI = 3.14f;

float rot = 0.0f;

bool Calculation::init(){
	return true;
}

//２点のなす角を求める関数
/*
@moto:元の位置
@aite:向きたい場所の位置
*/
double Calculation::dot_product(Vec2 moto, Vec2 aite){
	return moto.x*aite.x + moto.y*aite.y;
}

//角度の計算表
//内容：ロケットを動かしたい場所に移動させる
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

	//回転に必要な座標を作成する
	if (power!=0)rot = power*0.01;
	if (rot >= 2.0f*PI)rot -= 2.0f*PI;
	C.x= (A.x - B.x)*cos(rot) -
							(A.y - B.y)*sin(rot) + B.x;

	C.y= (A.x- B.x)*sin(rot) +
							(A.y - B.y)*cos(rot) + B.y;

	//ロケットの向きを調整する
	AB = B - A;
	AC = C - A;

	//ベクトルが０より多いなら正規化する
	if(AB.length()>0)AB.normalize();
	if(AC.length()>0)AC.normalize();

	//s = acosf((float)dot_product(misdir, AB));
	////if ((imgDirVec.X * AB.Y - imgDirVec.Y * AB.X) < 0.0f) s = -s;
	//if ((misdir.x*AB.y - misdir.y*AB.x) < 0.0f)s = -s;
	//auto deg = CC_RADIANS_TO_DEGREES(s);
	//deg *= 1;

	float Angle = ccpToAngle(ccpSub(A,B));
	Angle = CC_RADIANS_TO_DEGREES(Angle);
	Angle *= -1;
	rocket->setRotation(Angle);
	//座標を更新する
	rocket->setPosition(C.x, C.y);


	////とりあえず使用する素材を使いやすくする
	//float RocketX = rocket->getPosition().x;
	//float RocketY = rocket->getPosition().y;
	//float HosiX = hosi->getPosition().x;
	//float HosiY = hosi->getPosition().y;

	////星の周りを回転するためにsin ,cosを使用した計算をする
	//rot = power*0.01f;
	//if (rot >= 2.0f*PI)rot -= 2.0f*PI;
	//float PlayerNewX = (RocketX-HosiX)*cos(rot)-
	//						(RocketY - HosiY)*sin(rot) + HosiX;

	//float PlayerNewY = (RocketX - HosiX)*sin(rot) +
	//						(RocketY - HosiY)*cos(rot) + HosiY;
	//Vec2 aite = Vec2(PlayerNewX, PlayerNewY);
	//Vec2 vec = Vec2(RocketX,RocketY)-aite;

	////元と向きたい場所を計算する
	//if (power != 0.0f){
	//	s = acos(dot_product(misdir,vec));
	//	auto deg = CC_RADIANS_TO_DEGREES(s);
	//	rocket->setRotation(s);
	//}
	//
	////最後に位置を更新する。
	//rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));

}