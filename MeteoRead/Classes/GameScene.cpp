#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;

//�ړ���
const float PlayerSpeed = 0.1f;

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

	//�����o��������
	StarSet(visibleSize/2);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
	StarSet(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));

	//���P�b�g���o��������
	auto rocket = Rocket::create();
	rocket->setPosition(100,100);
	rocket->setRotation(30);
	this->addChild(rocket);
	_rocket = rocket;

	//�v�Z�@���g����悤�ɂ���
	auto Cal = Calculation::create();
	_Cal = Cal;

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){
	//�K�v�ȑf�ނ��l������
	Earth *hosis = 0;
	float smoleLength=NULL;

	//�z��ɓ����Ă��鐯�̐��܂�for���ŏ�������
	//���e�F���P�b�g�ɋ߂��������邩�ǂ����i��������Ȃ��ԋ߂��ꏊ��I������j
	for (auto hosi : stars){
		float length = ccpDistance(hosi->getPosition(),_rocket->getPosition());
		if (length <= 100.0f&&(length < smoleLength||smoleLength==NULL)){
			hosis = hosi;
			smoleLength = length;
		}
	}

	//�����߂��������݂���Ȃ�Ό��]�������ĉ����Ȃ�΁A
	//�����Ă�����Ɉړ�������B
	if (hosis != 0)
		_Cal->angle(hosis, _rocket, _UILayer->getmeterReturn());//���]������
	else
		_Cal->move(_rocket, _UILayer->getmeterReturn());//���i�^��������
}

//�����o��������
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//���̐����₷�B
	stars.pushBack(earth);//���̏���ۑ�����B
}
