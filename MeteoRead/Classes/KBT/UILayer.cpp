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

	// ��ʃT�C�Y������
	winSize = Director::sharedDirector()->getWinSize();

	//������
	up = 0;
	upCount = 1;

	buttonColor = Color3B(255, 255, 255);

	// �C�x���g���X�i�[����
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);		// �^�b�`���������C�x���g���X�i�[�ɓo�^
	listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);		// �^�b�`���Ă��鎞���C�x���g���X�i�[�ɓo�^
	listener->onTouchEnded = CC_CALLBACK_2(UILayer::onTouchEnded, this);		// �^�b�`�𗣂��������C�x���g���X�i�[�ɓo�^

	////�C�x���g���X�i�[��o�^
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// �X�v���C�g�쐬�N���X�Ăяo��
	CreateSprite();

	// �A�b�v�f�[�g�����s����B
	this->scheduleUpdate();
	
	return true;

}

void UILayer::update(float delta)
{
	MeterMove();
	Map();
}

void UILayer::MeterMove()
{
	if (upCount % 5 == 0)
	{
		//1�i�K�グ��
		up++;
		//5����ɂȂ�����0�ɖ߂�
		if (up >5)up=0;
	}
	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

void UILayer::Map()
{

}

void UILayer::CreateSprite()
{
	//�{�^��
	button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);
	buttonRect = button->boundingBox();

	//���[�^�[
	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(220, 91));
	this->addChild(meter);

	//�}�b�v
	map = Sprite::create();
	map->setAnchorPoint(Vec2::ZERO);
	map->setTextureRect(Rect(0, 0, 360, 202.5));
	map->setColor(Color3B::WHITE);
	map->setPosition(Vec2(winSize.width - 360, winSize.height - 202.5));
	this->addChild(map);
	map->setOpacity(100);

	//���P�b�g�̃A�C�R��
	myIcon = Sprite::create("icon01.png");
	this->addChild(myIcon);
}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	return true;
}

void UILayer::onTouchMoved(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	touchPoint = ptouch->getLocation();
	//�{�^���Ƀ^�b�`����Ă����
	if (buttonRect.containsPoint(touchPoint))
	{
		//�J�E���g���グ��
		upCount++;
		//�F�̕ύX
		buttonColor = Color3B(255, 0, 0);
		button->setColor(buttonColor);
	}
}

void UILayer::onTouchEnded(cocos2d::Touch *ptouch, cocos2d::Event *pEvent)
{
	//�{�^���������ꂽ�琔�l�����ɖ߂�
	up = 0;
	upCount = 1;
	//�F�����ɖ߂�
	buttonColor = Color3B(255, 255, 255);
	button->setColor(buttonColor);
}

int UILayer::getmeterReturn()
{
	return up;
}
