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

	// �X�v���C�g�쐬�N���X�Ăяo��
	CreateSprite();

	// �A�b�v�f�[�g�����s����B
	this->scheduleUpdate();

	return true;

}

void UILayer::update(float delta)
{

}

void UILayer::CreateSprite()
{
	Sprite* button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);

	Sprite* meter=Sprite::create("button02.png");
	meter->setPosition(Vec2(190, 91));
	this->addChild(meter);

	Sprite* box = Sprite::create();
	box->setTextureRect(Rect(0, 0, 100, 100));
	box->setColor(Color3B::WHITE);
	box->setPosition(Vec2(800, 100));
	this->addChild(box);
}