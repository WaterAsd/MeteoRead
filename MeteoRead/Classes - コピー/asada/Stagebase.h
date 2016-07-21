#ifndef __MATEOREAD__STAGEBASE__
#define __METEOREAD__STAGEBASE__

#include "cocos2d.h"
#include "asada/Earth.h"
#include "asada\Rocket.h"
#include "asada/Calculation.h"
#include "KBT\Road.h"

class Stagebase :public cocos2d::Layer{

protected:

	bool _startflg;		//�X�^�[�g�������ǂ����̃t���O
	bool _goalflg;		//�S�[�����Ă��悢���̃t���O
	bool _buttontouch;	//�{�^�����^�b�`�������ǂ������m�F����t���O

	int _rocketspeed;	//���P�b�g�̂��Ƃ��Ƃ̐��l
	int _rocketpower;	//UiLayer�Œǉ����ꂽ���l����power

	Road *_road;		//���̏��
	Calculation *_Cal;	//�v�Z�@�̏��

	std::string goalmai;//���ɓ���閼�O�i�S�[���t���O�H�j
	bool goalset;		//���̃S�[���͈�Ȃ̂Ńt���O���쐬

	SpriteBatchNode *_star;

	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B

	void StarSet(Vec2 Pos, std::string hosimei);//��ʂɐ�������B
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//���]����ق����߂��ɂ��邩�ǂ���

	Earth *axishosi;//���ƂȂ���]�̐�

	bool touchOK;	//���]���ɔ��˂̏�����݂���B
					//true:���ˏ�����
					//false:���˂������͒��i��

private:
	

public:
	Rocket *_rocket;	//���P�b�g�̏��

	void setstartflg(bool flg);			//�Q�[�����X�^�[�g�������ǂ������m�F����̃t���O
	void setrocketpower(int power);		//���P�b�g�̃X�s�[�h���󂯎�邽�߂̃t���O
	void setbottontouch(bool touch);		//�{�^�����^�b�`�������ǂ������m�F���邽�߂̃t���O

	bool getgoalflg();					//�S�[���������ǂ������m�F����֐�
	int getRocketPower();				//���P�b�g�̃p���[�i�X�s�[�h�́j
};

#endif __METEOREAD__STAGEBASE__