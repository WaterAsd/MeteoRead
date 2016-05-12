#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "asada/Earth.h"

class GameScene : public cocos2d::Layer
{
private:
	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B
	void StarSet(Vec2 Pos);//��ʂɐ�������B

public:
	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	void update(float delta);	//���t���[���X�V����
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static UILayer* uiLayer;//UILayer���g����悤�ɂ���B
	static Earth* earth;//���N���X���g����l�ɂ���B
};

#endif //__METEOREAD__GAME__