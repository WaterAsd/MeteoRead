#include "asada\Rocket.h"
#include "asada\booster.h"

USING_NS_CC;

//�����ǂ̂��炢���H
const int FRAME_COUNT = 4;
//���̃A�j���[�V�����ɐi�ނ��߂̎��ԑ��x
const float ANIMATION = 5;

//�������֐�
bool Rocket::init(){
	if (!Node::init()){
		return false;
	}
	//���P�b�g�̍��W������
	auto rocket = Sprite::create("Rocket.png");
	this->addChild(rocket);

	//�u�[�X�^�[�̍��@������
	auto booster = Booster::create();
	rocket->addChild(booster);

	return true;
}

//���P�b�g�̍��W�𑗂�
Vec2 Rocket::getRocketPos(){ return RocketPos; }
//���P�b�g��Rect��^����
Rect Rocket::getRocketRect(){ return RocketRect; }
//���P�b�g�̃X�s�[�h��ݒ肷��
int Rocket::setPower(int pw){ Power = pw;}
//���P�b�g�̃X�s�[�h��ݒ肷��
void Rocket::RocketSpeed(int Pw){

}

