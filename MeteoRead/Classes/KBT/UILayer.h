#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "ui/CocosGUI.h"

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
	Sprite* myIcon;             //���P�b�g�̃A�C�R��
	Sprite* starIcon[10];            //���̃A�C�R��
	Sprite* goalIcon;            //�S�[���̃A�C�R��
	Sprite* number[6];             //����

	//int
	int up;                     //���[�^�[�̕\���p�̕ϐ��@0�`5
	int upCount;                //�J�E���g
	int timer[6];	//0,1=���@2,3=�b�@4,5=�R���}

	//float
	float power;//���P�b�g�̈ړ���

	//Point
	Point touchPoint;				// �^�b�`���ꂽ�ꏊ

	//Rect
	Rect buttonRect;             //�{�^���̃��N�g

	//Label
	Label *clock[3];

	//Vec2
	Vec2 iconPos;
	//�A�C�R���p
	Vec2 worldPosition;
	Vec2 localPosition;
	std::vector<Vec2>starWorldPosition;
	Vec2 goalWorldPosition;
	std::vector<Vec2>starLocalPosition;
	Vec2 goalLocalPosition;
	Vec2 pos[4];
	Vec2 pos2[4];

	//Color3B
	Color3B buttonColor;//�{�^���̐F

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�������̏���
	virtual void onTouchEnded(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�𗣂������̏���

	void Button();
	void MeterMove();//���[�^�[�̃N���X
	void Map();//�}�b�v�̃N���X
	void Timer();//���Ԃ̃N���X

	void CreateSprite();	// �摜�쐬�N���X

private:


public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	void starset(int star);

	bool getTouch();

	int getmeterReturn();

	bool touch;

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__