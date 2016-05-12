#include "UILayer.h"

USING_NS_CC;

using namespace cocos2d;
using namespace std;

bool UILayer::init()
{
	// �e�N���X�@������ 
	if (!Layer::init())
	{
		return false;
	}

	//int������
	up = 0;
	upCount = 0;

	// �X�v���C�g�쐬�N���X�Ăяo��
	CreateSprite();

	// �A�b�v�f�[�g�����s����B
	this->scheduleUpdate();

	return true;

}

void UILayer::update(float delta)
{
	meterMove();
}

void UILayer::meterMove()
{
	upCount++;
	if (upCount % 5 == 0)
	{
		up++;
		if (up >5)up=0;
	}
	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

void UILayer::CreateSprite()
{
	Sprite* button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);

	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(190, 91));
	this->addChild(meter);
}