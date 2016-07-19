#include "GameScene.h"
#include "KBT\GameOver.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
//BGM�iSimpleAudioEngine�j�g�����߂ɕK�v
using namespace CocosDenshion;

#define COUNT 180.0f;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Vec2 GameScene::goalPos;
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
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Space,0);

	//�Q�[���V�[���̍쐬
	auto GameLayer = Stage::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0, 0);
	GameLayer->StageCreate(SelectCount);
	this->addChild(GameLayer, 1);
	_stage1 = GameLayer;

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer,2);
	_UILayer = uiLayer;

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	//��]���鐯�����Z�b�g����
	axishosi = 0;

	//�S�[�����鐯�ɓ���閼�O�̐ݒ�
	goalmai = std::string("goal");
	Statics::clearFlg = false;

	Statics::gameOverFlg = false;

	auto _st = Start::create();
	this->addChild(_st,3);
	_start = _st;

	//�^�b�`�̏��������s����
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
		if (_UILayer->getTouch() == true)return false;
		touchpoint = touch->getLocation();
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
		auto _Touch = touch->getLocation();
		auto move = _Touch - touchpoint;
		auto getstage = _stage1->getPosition();
		_stage1->setPosition(getstage - move);
		touchpoint = _Touch;
	};
	listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {

	};
	listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {

	};

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//BGM
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("BGM/BGMGame.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("BGM/BGMGame.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/BGMGame.mp3", true);

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){

	//�K�v�ȏ����l������
	_Start = _start->getStart();
	_goal = Statics::clearFlg;
	_touch = Statics::touchFlg;


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
