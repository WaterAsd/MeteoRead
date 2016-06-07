#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"
#include "asada/Start.h"

class GameScene : public cocos2d::Layer
{
private:
	Rocket* _rocket;//���P�b�g�̃|�C���^�[
	UILayer* _UILayer;//UI�̃|�C���^�[
	Calculation* _Cal;//�v�Z�@�̃|�C���^�[
	Start* _start;

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B
	void StarSet(Vec2 Pos);//��ʂɐ�������B
	void selectSter(Earth* hosi);//���]����ق����߂��ɂ��邩�ǂ���

	Earth *axishosi;//���ƂȂ���]�̐�

	bool touchOK;	//���]���ɔ��˂̏�����݂���B
					//true:���ˏ�����
					//false:���˂������͒��i��

public:
	static Vec2 RoPos;
	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	void update(float delta);	//���t���[���X�V����
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static UILayer* uiLayer;//UILayer���g����悤�ɂ���B
	static Earth* earth;//���N���X���g����l�ɂ���B
};

#endif //__METEOREAD__GAME__