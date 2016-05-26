#include "UILayer.h"
#include "GameScene.h"

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
	for (int i = 1; i < 3; i++)
	{
		timer[0] = 2;
		timer[i] = 60;
	}
	for (int i = 0; i < 6; i++)
	{
		keta[i] = 0;
		keta[1] = 3;
	}
	power = 0.0f;
	touch = false;
	buttonColor = Color3B(255, 255, 255);

	// �C�x���g���X�i�[����
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);		// �^�b�`���������C�x���g���X�i�[�ɓo�^
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
	Button();
	MeterMove();
	Map();
	Timer();
}

void UILayer::Button()
{
	if (touch)
	{
		//�J�E���g���グ��
		upCount++;
		//�F�̕ύX
		buttonColor = Color3B(255, 0, 0);
		button->setColor(buttonColor);
	}
	else
	{
		//�{�^���������ꂽ�琔�l�����ɖ߂�
		up = 0;
		upCount = 1;
		//�F�����ɖ߂�
		buttonColor = Color3B(255, 255, 255);
		button->setColor(buttonColor);
	}
}

void UILayer::MeterMove()
{
	//�J�E���g��50�����邽�сA�ړ��ʂ�1������
	if (upCount %50 ==0)
	{
		power++;
	}
	//������4�i�K�オ�邽�сA���[�^�[�̗ʂ�1������
	if (upCount % 200 == 0)
	{
		up++;
	}

	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

void UILayer::Map()
{
	//���[���h���W�ɕϊ�
	Vec2 worldPosition = GameScene::RoPos;

	//�A�C�R�������P�b�g�ɒǏ]������
	Vec2 localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition/2.6 , Vec2(600, 340)));
	this->myIcon->setPosition(localPosition);
}

void UILayer::Timer()
{
	for (int i = 0; i < 3; i++)
	{
		if (timer[i] > 9)
		{
			clock[i]->setString(StringUtils::toString(timer[i]));
		}
		else
		{
			clock[i]->setString("0" + StringUtils::toString(timer[i]));
		}
	}

	timer[2] -= 1;
	if (timer[2] == 0)
	{
		timer[1]--;
		timer[2] = 60;
	}
	if (timer[1] == 00)
	{
		timer[0]--;
		timer[1] = 60;
	}
	//keta[5]--;
	//if (keta[5] < 0)
	//{
	//	keta[5] = 9;
	//	keta[4]--;
	//}
	//if (keta[4] < 0)
	//{
	//	keta[4] = 5;
	//	keta[3]--;
	//}
	//if (keta[3] < 0)
	//{
	//	keta[3] = 9;
	//	keta[2]--;
	//}
	//if (keta[2]<0)
	//{
	//	keta[2] = 5;
	//	keta[1]--;
	//}

	for (int a = 5; a > -1; a--)
	{
		keta[a]--;
		if (keta[a] < 0)
		{
			if (a % 2 == 0)
			{
				keta[a] = 9;
				keta[a - 1]--;
			}
			else
			{
				keta[a] = 5;
				keta[a - 1]--;
			}
		}
	}
	


	for (int i = 0; i < 6; i++)
	{
		number[i]->setTextureRect(Rect(62 * keta[i], 0, 62, 110));
	}
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

	//����
	for (int i = 0; i < 3; i++)
	{
		clock[i] = cocos2d::Label::createWithSystemFont("0" + cocos2d::StringUtils::toString(timer[i]), "arial", 100.0f);
		clock[i]->setAnchorPoint(Vec2::ZERO);
		clock[i]->setPosition(Vec2(150 * i, winSize.height*0.85f));
		clock[i]->setColor(Color3B::RED);
		this->addChild(clock[i]);
	}

	//����
	for (int i = 0; i < 6; i++)
	{
		number[i] = Sprite::create("Number.png");
		number[i]->setAnchorPoint(Vec2::ZERO);
		number[i]->setPosition(100+(i*100), 100);
		this->addChild(number[i]);
	}

}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	touchPoint = ptouch->getLocation();
	if (buttonRect.containsPoint(touchPoint))
	{
		touch = true;
	}
	return true;
}

void UILayer::onTouchEnded(cocos2d::Touch *ptouch, cocos2d::Event *pEvent)
{
	touch = false;
}

int UILayer::getmeterReturn()
{
	return power;
}
