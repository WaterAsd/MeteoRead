#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"
#include "asada/Start.h"
#include "KBT/Road.h"
#include "asada/Goal.h"
#include "asada/Stage1.h"
#include "KBT/UILayer.h"

class GameScene : public cocos2d::Layer
{
private:
	//�ꎞ�I�̓��e��ۑ����Ă�������
	std::vector<Vec2> OK;

	bool _Start;
	bool _goal;
	bool _touch;

	Vec2 touchpoint;

	Size visibleSize;
	Vec2 origin;

	Stage1 *_stage1;
	
	UILayer* _UILayer;//UI�̃|�C���^�[
	Calculation* _Cal;//�v�Z�@�̃|�C���^�[
	Start* _start;
	Road* _road;

	std::string goalmai;//���ɓ���閼�O�i�S�[���t���O�H�j
	bool goalset;		//���̃S�[���͈�Ȃ̂Ńt���O���쐬
	bool goalflg;

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B

	void StarSet(Vec2 Pos, std::string hosimei);//��ʂɐ�������B
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//���]����ق����߂��ɂ��邩�ǂ���

	Earth *axishosi;//���ƂȂ���]�̐�

	bool touchOK;	//���]���ɔ��˂̏�����݂���B
					//true:���ˏ�����
					//false:���˂������͒��i��

	//�~�j�}�b�v�ɕK�v�ȏ�������
	void minimapdate();

public:
	static int SelectCount;
	void getStage(int count);
	Stagebase craeateStage(int count);

	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	void update(float delta);	//���t���[���X�V����
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static UILayer* uiLayer;//UILayer���g����悤�ɂ���B
	static Earth* earth;//���N���X���g����l�ɂ���B
};

#endif //__METEOREAD__GAME__