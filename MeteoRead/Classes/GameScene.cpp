#include "GameScene.h"
#include "asada/Rocket.h"
#include "asada/Start.h"
#include "asada/Goal.h"
#include "KBT\GameOver.h"
#include "isiwaki\SelectScene.h"

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Rocket* GameScene::_rocket;

Vec2 GameScene::starPos[4];
Vec2 GameScene::goalPos;
Vector<Earth*> GameScene::stars;
bool GameScene::gameOver;

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
	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);

	starPos[0] = Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 100);
	starPos[1] = Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200);
	starPos[2] = Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100);
	starPos[3] = Vec2(visibleSize.width / 2, visibleSize.height / 2);

	//�����o��������
	auto hosimei = std::string("Earth.png");
	StarSet(starPos[0], hosimei);
	StarSet(starPos[1], hosimei);
	StarSet(starPos[2], hosimei);
	StarSet(starPos[3], hosimei);

	//���P�b�g���o��������
	auto rocket = Rocket::create();
	rocket->setPosition(visibleSize.width-100,200);
	rocket->setRotation(-90);
	_rocket = rocket;

	//���̏o��
	auto road = Road::create();
	this->addChild(road);
	_road = road;
	this->addChild(rocket);

	//�v�Z�@���g����悤�ɂ���
	auto Cal = Calculation::create();
	_Cal = Cal;

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	//��]���鐯�����Z�b�g����
	axishosi = 0;

	//�������������𔻒肷�邽�߂̏������L������
	touchOK = false;

	//�S�[�����鐯�ɓ���閼�O�̐ݒ�
	goalPos = Vec2(200, visibleSize.height - 200);

	goalmai = std::string("goal");
	goalset = false;
	goalflg = false;
	GoalStarset(goalPos,goalmai);

	gameOver = false;

	auto _st = Start::create();
	this->addChild(_st);
	_start = _st;

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){

	float power;
	//�K�v�ȑf�ނ��쐬����
	if (_start->getStart() == true)
		power = _rocket->getSpeed() + _UILayer->getmeterReturn();
	else
		power = _rocket->getSpeed();

	//�z��ɓ����Ă��鐯�̐��܂�for���ŏ�������
	//���e�F���P�b�g�ɋ߂��������邩�ǂ����i��������Ȃ��ԋ߂��ꏊ��I������j
	if (_rocket->getRevolutionflg() == false){
		Earth*karihosi = axishosi;
		float smoleLength = NULL;
		for (auto hosis : stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= Hosikoutenn && (length < smoleLength || smoleLength == NULL)&&karihosi!=hosis){
				axishosi = hosis;
				smoleLength = length;
				_rocket->setRevolutionflg(true);
			}
		}
	}

	//�S�[���̐��Ɍ��]�ł�����N���A��ʂ��o���B
	if (_rocket->getRevolutionflg() == true &&
				axishosi->getName() == goalmai&&
							goalflg == false){
		auto _st = Goal::create();
		this->addChild(_st);
		goalflg = true;
	}

	/*���]�t���O��true��UiLayer��touch��true�Ȃ�
		touchOK��false�ɂ��Ĕ��˂���*/
	if (_rocket->getRevolutionflg() == true &&
		_UILayer->touch == false &&
		touchOK == true){
		touchOK = false;
		_rocket->setRevolutionflg(false);
	}

	/*���]�t���O��true�ŁAUiLayer��touch��false�Ȃ�
		touchOK��true�ɂ��Ĕ��˂̏���������*/
	if (_rocket->getRevolutionflg() == true &&
		_UILayer->touch == true){
		touchOK = true;
	}
	//�������]�t���O��true�Ȃ�Ό��]�����āA
	//false�Ȃ�΁A�����Ă�����Ɉړ�������B
	if (_rocket->getRevolutionflg() == true){
		_Cal->angle(axishosi, _rocket, power);//���]������
	}else{
		_Cal->move(_rocket, power);//���i�^��������
	}

	//�����{�^���������Ă���̂Ȃ����\��������B

	auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);
	
	_Cal->hosiangle(hosi1,hosi2,1.0f);

	//�}�b�v�̃A�C�R���Ɠ���
	RoPos = _rocket->getPosition();
	for (int i = 0; i < 4; i++)
	{
		starPos[i] = stars.at(i)->getPosition();
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

//�����o��������
void GameScene::StarSet(Vec2 Pos,std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//���̐����₷�B
	stars.pushBack(earth);//���̏���ۑ�����B
	//starsname.pushBack(hosimei);//���̖��O���擾���Ă���
}

//���݋߂��������邩�ǂ��������o����
/*
@*hosi:�������݂���Ȃ�g�p����̂ŕۑ�����
*/
void GameScene::selectSter(Earth*hosi){
	float smoleLength = NULL;
	Earth*karihosi = 0;
	//�z��ɓ����Ă��鐯�̐��܂�for���ŏ�������
	//���e�F���P�b�g�ɋ߂��������邩�ǂ����i��������Ȃ��ԋ߂��ꏊ��I������j
	for (auto hosis : stars){
		float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
		if (length <= 100.0f && (length < smoleLength || smoleLength == NULL)){
			karihosi = hosis;
			smoleLength = length;
			_rocket->setRevolutionflg(true);
		}
	}
	hosi = karihosi;
}

//�S�[���ɕK�v�Ȑ����쐬����
/*
@Pos:���̏ꏊ��ݒ肷��
��hosimei:���ɓ����isetName�j�̕���
*/
void GameScene::GoalStarset(Vec2 Pos, std::string hosimei){
	if (goalset == true){}

	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		starCount++;//���̐����₷�B
		stars.pushBack(earth);//���̏���ۑ�����B
		goalset == false;
	}
}
