#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static UILayer* uiLayer;//UILayer���g����悤�ɂ���B
};

#endif //__METEOREAD__GAME__