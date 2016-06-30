#include "UILayer.h"
#include "asada\Rocket.h"
#include "asada\Calculation.h"

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
		timer[1] = 3;
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
	////�A�C�R�������P�b�g�ɒǏ]������
	//Vec2 localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition/2.6 , Vec2(600, 340)));
	//this->myIcon->setPosition(localPosition);
	//myIcon->setRotation(Calculation::Angle);
	
}

void UILayer::Timer()
{
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
	if (timer[2]<0)
	{
		timer[2] = 5;
		timer[1]--;
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
	_minimap = MapNode::create();
	_minimap->setPosition(Vec2(600,340));
	this->addChild(_minimap);

	//���P�b�g�̃A�C�R��
	myIcon = Sprite::create("icon01.png");
	this->addChild(myIcon);

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
/*-------------------------------------------------------------------------------------------------------------------------------
----------------------------�����܂ł�UILayer�̃N���X�̊֐�----------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------*/

//�}�b�v�̏���������
bool MapNode::init(){
	if (!Node::init()){
		return false;
	}
	
	oneflg = false;

	//���̔w�i���쐬����
	_map = Sprite::create();
	_map->setAnchorPoint(Vec2::ZERO);
	_map->setTextureRect(Rect(0, 0, 360, 202.5));
	_map->setColor(Color3B::WHITE);
	_map->setOpacity(128);
	this->addChild(_map,-1);

	return true;
}

//�}�b�v�̍X�V����
void MapNode::update(float dt){
	//�}�b�v���ړ����邩������Ȃ��̂ňꉞ
	_rocket->setPosition(Vec2((_rocketpos.x*mapsize.x), (_rocketpos.y*mapsize.y)));
	for (int i = 0; i < _starpos.size(); i++){
		auto starpos = _starpos.at(i);
		auto star = _star.at(i);
		star->setPosition(Vec2((starpos.x*mapsize.x), (starpos.y*mapsize.y)));
	}
	_goal->setPosition(Vec2((_goalpos.x*mapsize.x), (_goalpos.y*mapsize.y)));
}

//�ق����ꏊ�������Ă���B
void MapNode::setrocket(Vec2 rocket){ _rocketpos = rocket; }
void MapNode::setstarpos(std::vector<Vec2> pos){
	_starpos=pos;
}
void MapNode::setgoalpos(Vec2 goal){ _goalpos = goal; }
void MapNode::setStagerect(Rect stagesize){	_stagesize = stagesize;}

//�摜���쐬���邽�߂̕�
void MapNode::mapcreate(){

	if (oneflg != true){
		Mapsize();

		_rocket = Sprite::create("icon01.png");
		_rocket->setPosition(Vec2((_rocketpos.x*mapsize.x), (_rocketpos.y*mapsize.y)));
		this->addChild(_rocket);

		for (int i = 0; i < _starpos.size(); i++){
			auto Star = CCDrawNode::create();
			auto starpos = _starpos.at(i);
			Star->drawDot(Vec2((starpos.x*mapsize.x), (starpos.y*mapsize.y))
				, 5, Color4F::BLUE);
			this->addChild(Star);
			_star.pushBack(Star);
		}

		_goal = CCDrawNode::create();
		_goal->drawDot(Vec2((_goalpos.x*mapsize.x), (_goalpos.y*mapsize.y))
			, 5, Color4F::BLUE);
		this->addChild(_goal);

		//�A�b�v�f�[�g�����s������
		this->scheduleUpdate();

		oneflg = true;
	}
}

//�}�b�v�̔䗦���ꏏ�ɂ���
void MapNode::Mapsize(){
	//�摜/�X�e�[�W�̃T�C�Y�Ŋ����Ēl�𓱂��o���B
	mapsize.x = (_map->getTextureRect().getMaxX()) / (_stagesize.getMaxX() - _stagesize.getMinX());
	mapsize.y = (_map->getTextureRect().getMaxY()) / (_stagesize.getMaxY() - _stagesize.getMinY());
}