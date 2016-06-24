#include "GameScene.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;

//�ړ���
const float PlayerSpeed = 0.1f;

//���]���鐯�Ƃ̋���
const float Hosikoutenn = 80.0f;

//Scene���g����悤�ɂ���
Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init(){
	//init�����݂��Ȃ��ꍇ�͏���
	if (!Layer::init()){
		return false;
	}

	//��ʃT�C�Y���l������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//�Q�[���V�[���̍쐬
	auto GameLayer = Stage1::create();
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(GameLayer);
	_stage1 = GameLayer;

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	//��]���鐯�����Z�b�g����
	axishosi = 0;

	//�S�[�����鐯�ɓ���閼�O�̐ݒ�
	goalmai = std::string("goal");
	goalset = false;
	goalflg = false;

	auto _st = Start::create();
	this->addChild(_st);
	_start = _st;;

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){

	//�K�v�ȏ����l������
	bool Start = _start->getStart();
	bool goal = _stage1->getgoalflg();
	bool touch = _UILayer->getTouch();

	//�Q�[�����Ȃ�
	if (Start == true && goal == false){
		_stage1->setrocketpower(_UILayer->getmeterReturn());
		_stage1->setbottontouch((int)touch);
	}
	else{
		_stage1->setrocketpower(_stage1->getRocketPower());
		if (goal == true&&goalflg == false){
			goalflg = true;
			auto goal = Goal::create();
			this->addChild(goal);
		}
	}
}