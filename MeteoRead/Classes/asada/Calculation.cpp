#include "asada\/Calculation.h"
USING_NS_CC;
//Player�̈ړ����x
const float PLAYER_SPEED = 1.0f;
float PLAYER_MOVE_X;
float PLAYER_MOVE_Y;

double s = 0.0f;//���������p�x
Vec2 misdir = Vec2(0,1);//�~�T�C���̈ꉞ�̌���

float PI = 3.14f;

float rot=0.0f;
float Calculation::Angle;

bool Calculation::init(){
	return true;
}

//�Q�_�̂Ȃ��p�����߂�֐�
/*
@moto:���̈ʒu
@aite:���������ꏊ�̈ʒu
*/
double Calculation::dot_product(Vec2 moto, Vec2 aite){
	return moto.x*aite.x + moto.y*aite.y;
}

//���]�̏���
//���e�F���P�b�g�����]���邽�߂Ɏg���֐�
/*
@hosi �s���������̏��
@rocket �������������P�b�g�̏��
@power�@�������������P�b�g�̈ړ���
*/
void Calculation::angle(const Earth* hosi,Rocket*rocket,const int power){
	//�K�v�ȏ����쐬����
	Vec2 A, B,C,AB,AC;
	A = rocket->getPosition();
	B = hosi->getPosition();

	//���]�ɕK�v�ȐV�������W���쐬����
	if (power!=0)rot = power*0.01;
	if (rot >= 2.0f*PI)rot -= 2.0f*PI;
	C.x= (A.x - B.x)*cos(rot) -
							(A.y - B.y)*sin(rot) + B.x;

	C.y= (A.x- B.x)*sin(rot) +
							(A.y - B.y)*cos(rot) + B.y;

	//���������p�x�Ɍ�������
	Angle = ccpToAngle(ccpSub(A,B));
	Angle = CC_RADIANS_TO_DEGREES(Angle);
	Angle *= -1;
	rocket->setRotation(Angle);

	//���W���X�V����
	rocket->setPosition(C.x, C.y);
}


//���P�b�g�������Ă�����ɓ������B
void Calculation::move(Rocket*rocket, const int power){

}