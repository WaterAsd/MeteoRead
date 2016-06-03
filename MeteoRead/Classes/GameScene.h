#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "KBT/Road.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"

class GameScene : public cocos2d::Layer
{
private:
	Rocket* _rocket;//���P�b�g�̃|�C���^�[
	UILayer* _UILayer;//UI�̃|�C���^�[
	Calculation* _Cal;//�v�Z�@�̃|�C���^�[
	Road* _road;

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B
	void StarSet(Vec2 Pos);//��ʂɐ�������B

	void move();//���ō�����̂Ŏg��Ȃ��ł��������B
	void move2();//���ō�����̂Ŏg��Ȃ��ł��������B

public:
	static Vec2 RoPos;
	static Sprite rocket;
	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	void update(float delta);	//���t���[���X�V����
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static UILayer* uiLayer;//UILayer���g����悤�ɂ���B
	static Earth* earth;//���N���X���g����l�ɂ���B
};

#endif //__METEOREAD__GAME__