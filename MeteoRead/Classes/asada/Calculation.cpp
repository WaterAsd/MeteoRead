#include "asada\/Calculation.h"
USING_NS_CC;
//Player�̈ړ����x
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;
bool Calculation::init(){
	return true;
}

//�p�x�̌v�Z�\
void Calculation::angle(Earth* hosi, Rocket*rocket, int power){

	//����GameScene���X�V����ď������炱���GameScene��update���ɓ���Ăق���
	//���P�b�g�ƖړI�̐������o����B
	//auto vec2hosi = stars.at(1);
	//_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	/*����ł��̎d�g�݂͓���*/


	//�p�x�����߂�
	float angle = ccpToAngle(ccpSub(hosi->getPosition(), rocket->getPosition()));
	//�ړ��ʂ����߂�
	float PlayerMoveX = power*cos(angle);
	float PlayerMoveY = power*sin(angle);
	//�������������Ă���Ȃ���ۂɈړ�������
	if (ccpDistance(rocket->getPosition(), hosi->getPosition()) > 1.0f){
		float PlayerNewX = rocket->getPosition().x + PlayerMoveX;
		float PlayerNewY = rocket->getPosition().y + PlayerMoveY;
		rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));
	}
}