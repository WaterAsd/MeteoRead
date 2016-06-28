#include "GameScene.h"
#include "KBT\GameOver.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
int GameScene::SelectCount;
bool GameScene::gameOver;

//�ړ���
const float PlayerSpeed = 0.1f;

//���]���鐯�Ƃ̋���
const float Hosikoutenn = 80.0f;

//�Z���N�g�V�[���őI�������������X�e�[�W�ɕύX����


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
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	//�Q�[���V�[���̍쐬
	auto GameLayer = Stage1::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0,0);
	GameLayer->stageSelect(SelectCount);
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
	_start = _st;

	//�^�b�`�̏��������s����
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
		if (_UILayer->getTouch() == true)return false;
		touchpoint = touch->getLocation();
		_stage1->stopRocket();
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
		auto Touch = touch->getLocation();
		auto move = Touch - touchpoint;
		auto getstage = _stage1->getPosition();
		_stage1->setPosition(Vec2::ZERO);
		touchpoint = _stage1->getPosition();

	};
	listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {
		
	};
	listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {
		
	};

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	gameOver = false;

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){

	//�K�v�ȏ����l������
	_Start = _start->getStart();
	_goal = _stage1->getgoalflg();
	_touch = _UILayer->getTouch();

	//�Q�[�����Ȃ�
	if (_Start == true && _goal == false){
		_stage1->setrocketpower(_UILayer->getmeterReturn());
		_stage1->setbottontouch((int)_touch);
	}
	else{
		_stage1->setrocketpower(_stage1->getRocketPower());
		if (_goal == true&&goalflg == false){
			goalflg = true;
			auto goal = Goal::create();
			this->addChild(goal);
		}
	}

	//��ʊO�ɏo����Q�[���I�[�o�[
	if (RoPos.x < 0 || visibleSize.width < RoPos.x || RoPos.y < 0 || visibleSize.height < RoPos.y)
	{
		gameOver = true;
	}
	if (gameOver)
	{
		auto _st = GameOver::create();
		this->addChild(_st);
	}
}

//���ݗV��ł���Q�[�����擾����
void GameScene::getStage(int count){

}
