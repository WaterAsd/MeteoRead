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
}