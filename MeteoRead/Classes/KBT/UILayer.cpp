#include "UILayer.h"
#include "GameScene.h"
#include "asada\Rocket.h"
#include "asada\/Calculation.h"

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
	power = 0.0f;
	touch = false;
	buttonColor = Color3B(255, 255, 255);

	//���Ԃ̏������@�X�^�[�g3��
	for (int i = 0; i < 6; i++)
	{
		timer[i] = 0;
		timer[1] = 1;
	}

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
	//worldPosition = GameScene::RoPos; 
	//starWorldPosition[4];
	//goalWorldPosition=GameScene::goalPos;
	//starLocalPosition[4];
	//goalLocalPosition;

	////�A�C�R�������P�b�g�ɒǏ]������
	//localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition/2.6 , Vec2(600, 340)));
	//this->myIcon->setPosition(localPosition);
	//myIcon->setRotation(Calculation::Angle);

	//iconPos = myIcon->getPosition();

	////�~�j�}�b�v�O�ɏo���烍�P�b�g����
	//if (iconPos.x < winSize.width - 360 || iconPos.y < winSize.height - 202.5)
	//{
	//	myIcon->setVisible(false);
	//}

	////���ɒǏ]
	//for (int i = 0; i < 4; i++)
	//{
	//	starWorldPosition[i] = GameScene::starPos[i];
	//	starLocalPosition[i] = starIcon[i]->getParent()->convertToNodeSpace(ccpAdd(starWorldPosition[i] / 2.6, Vec2(600, 340)));
	//	this->starIcon[i]->setPosition(starLocalPosition[i]);
	//}
	//goalLocalPosition = goalIcon->getParent()->convertToNodeSpace(ccpAdd(goalWorldPosition / 2.6, Vec2(600, 340)));
	//this->goalIcon->setPosition(goalLocalPosition);
}

void UILayer::Timer()
{
	if (GameScene::gameOver == false)
	{
		//���Ԃ̃J�E���g
		timer[5]--;
		if (timer[5] < 0)
		{
			timer[5] = 9;
			timer[4]--;
		}
		if (timer[4] < 0)
		{
			timer[4] = 5;
			timer[3]--;
		}
		if (timer[3] < 0)
		{
			timer[3] = 9;
			timer[2]--;
		}
		if (timer[2] < 0)
		{
			timer[2] = 5;
			timer[1]--;
		}
	}
	//�S��0�ɂȂ�����Q�[���I�[�o�[
	if (timer[1] == 0 && timer[2] == 0 && timer[3] == 0 &&
		timer[4] == 0 && timer[5] == 0)
	{
		GameScene::gameOver = true;
	}

	for (int i = 0; i < 6; i++)
	{
		number[i]->setTextureRect(Rect(62 * timer[i], 0, 62, 102));
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
	//�e���̃A�C�R��
	for (int i = 0; i < 4; i++)
	{
		starIcon[i] = Sprite::create("starIcon.png");
		this->addChild(starIcon[i]);
	}
	//�S�[���̃A�C�R��
	goalIcon = Sprite::create("starIcon.png");
	this->addChild(goalIcon);

	//����
	for (int i = 0; i < 6; i++)
	{
		number[i] = Sprite::create("count.png");
		number[i]->setAnchorPoint(Vec2::ZERO);
		number[i]->setPosition(100+(i*80), 450);
		number[i]->setScale(0.6);
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

//�^�b�`���Ă��邩�ǂ������m�F���邽�߂Ɋ֐�
bool UILayer::getTouch(){
	return touch;
}

int UILayer::getmeterReturn()
{
	return power;
}

void UILayer::setStar(Vec2 pos,int star)
{
	//���ɒǏ]
	//for (int i = 0; i < star; i++)
	//{
	//	starWorldPosition[i] = GameScene::starPos[i];
	//	starLocalPosition[i] = starIcon[i]->getParent()->convertToNodeSpace(ccpAdd(starWorldPosition[i] / 2.6, Vec2(600, 340)));
	//	this->starIcon[i]->setPosition(starLocalPosition[i]);
	//}
}