#include "GameScene.h"

USING_NS_CC;

#define COUNT 180.0f;

//UiLayer
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
int GameScene::SelectCount;

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

	//�Q�[���J�n���̏���
	_gamestate = GameState::START;

	//��ʃT�C�Y���l������
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Space);

	//�Q�[���V�[���̍쐬
	auto GameLayer = Stage::create();
	GameLayer->setAnchorPoint(Vec2::ZERO);
	GameLayer->setPosition(0, 0);
	GameLayer->StageCreate(SelectCount);
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

	////�^�b�`�̏��������s����
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
	//	if (_UILayer->getTouch() == true)return false;
	//	touchpoint = touch->getLocation();
	//	_stage1->stopRocket();
	//	return true;
	//};
	//listener->onTouchMoved = [=](Touch* touch, Event* event) -> void {
	//	auto _Touch = touch->getLocation();
	//	auto move = _Touch - touchpoint;
	//	auto getstage = _stage1->getPosition();
	//	_stage1->setPosition(getstage + move);
	//	touchpoint = _Touch;
	//};
	//listener->onTouchEnded = [=](Touch* touch, Event* event) -> void {

	//};
	//listener->onTouchCancelled = [=](Touch* touch, Event* event) -> void {

	//};

	//auto dispatcher = Director::getInstance()->getEventDispatcher();
	//dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){
	switch (_gamestate)
	{
	case START:
		Start();
		if (_start->getStart()==true){
			this->removeChildByTag(1);
			_gamestate = GameState::GAME;
		}
		break;
	case GAME:
		if (Statics::clearFlg == true){
			_gamestate = GameState::CLEAR;
		}
		else if (Statics::gameOverFlg == true){
			_gamestate = GameState::GAMEOVER;
		}
		break;
	case CLEAR:
		GameClear();
		break;
	case GAMEOVER:
		GameOver();
		break;
	case GAMEEND:
		break;
	}
}

//���ݗV��ł���Q�[�����擾����
void GameScene::getStage(int count){

}

void GameScene::minimapdate(){
	
}

//�X�^�[�g�V�[�����쐬����
void GameScene::Start(){

	if (_startflg != true){
		_start = StartScene::create();
		_start->setTag(1);
		_start->setAnchorPoint(Vec2::ZERO);
		_start->setPosition(Vec2(0, 0));
		this->addChild(_start);
		_startflg = true;
	}
}

void GameScene::GameOver(){
	auto clear = Goal::create();
	clear->setAnchorPoint(Vec2::ZERO);
	clear->setPosition(Vec2::ZERO);
	this->addChild(clear);
	_gamestate = GameState::GAMEEND;
}
void GameScene::GameClear(){
	auto gameover = Goal::create();
	gameover->setAnchorPoint(Vec2::ZERO);
	gameover->setPosition(Vec2::ZERO);
	this->addChild(gameover);
	_gamestate = GameState::GAMEEND;
}