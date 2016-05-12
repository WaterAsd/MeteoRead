#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"

USING_NS_CC;

using namespace cocos2d;

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// ��ʃT�C�Y

	//Sprite
	Sprite* meter;              //���[�^�[�̉摜

	//int
	int up;                     //���[�^�[���������߂̕ϐ�
	int upCount;

	void CreateSprite();	// �摜�쐬�N���X

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);
	void meterMove();
	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__