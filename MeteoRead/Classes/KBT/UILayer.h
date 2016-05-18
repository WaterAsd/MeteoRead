#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d;

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// ��ʃT�C�Y

	//Sprite
	Sprite* meter;              //���[�^�[�̉摜
	Sprite* button;             //�{�^���̉摜
	Sprite* map;                //�}�b�v�摜

	//int
	int up;                     //���[�^�[�̗ʁ@0�`5
	int upCount;                //up�̃J�E���g

	//Point
	Point touchPoint;				// �^�b�`���ꂽ�ꏊ

	//Rect
	Rect buttonRect;             //�{�^���̃��N�g

	//Color3B
	Color3B buttonColor;//�{�^���̐F

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�������̏���
	virtual void onTouchMoved(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`���̎��̏���
	virtual void onTouchEnded(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�𗣂������̏���

	void CreateSprite();	// �摜�쐬�N���X

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);
	void meterMove();//���[�^�[�̊֐�
	int getmeterReturn();

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__