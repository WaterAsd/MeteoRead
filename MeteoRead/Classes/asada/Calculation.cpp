#include "asada\/Calculation.h"
USING_NS_CC;
//Player�̈ړ����x
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;

float PI = 3.14f;

float rot = 0.0f;

bool Calculation::init(){
	return true;
}

//�p�x�̌v�Z�\
//���e�F���P�b�g�𓮂��������ꏊ�Ɉړ�������
/*
@hosi �s���������̏��
@rocket �������������P�b�g�̏��
@power�@�������������P�b�g�̈ړ���
*/
void Calculation::angle(Earth* hosi, Rocket*rocket, int power){

	//����GameScene���X�V����ď������炱���GameScene��update���ɓ���Ăق���
	//���P�b�g�ƖړI�̐������o����B
	//auto vec2hosi = stars.at(1);
	//_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	/*����ł��̎d�g�݂͓���*/


	//�p�x�����߂�
	/*float angle = ccpToAngle(ccpSub(hosi->getPosition(), rocket->getPosition()));
	auto deg = CC_RADIANS_TO_DEGREES(angle);*/
	//�ړ��ʂ����߂�
	//float PlayerMoveX = power*cos(angle);
	//float PlayerMoveY = power*sin(angle);
	////�������������Ă���Ȃ���ۂɈړ�������
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