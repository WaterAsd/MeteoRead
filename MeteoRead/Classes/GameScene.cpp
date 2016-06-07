#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;
Vec2 GameScene::RoPos;
Rocket* GameScene::_rocket;

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
	rocket->setPosition(300,300);
	this->addChild(rocket);
	_rocket = rocket;

	//�v�Z�@���g����悤�ɂ���
	auto Cal = Calculation::create();
	_Cal = Cal;

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer);
	_UILayer = uiLayer;

	//���̏o��
	auto road = Road::create();
	this->addChild(road);
	_road = road;

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){
	auto vec2hosi = stars.at(0);
	auto vec2 = vec2hosi->getPosition();
	vec2.x += 0.1f;
	vec2hosi->setPosition(vec2);
	_Cal->angle(vec2hosi, _rocket, _UILayer->getmeterReturn());
	RoPos = _rocket->getPosition();
}

//�����o��������
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//���̐����₷�B
	stars.pushBack(earth);//���̏���ۑ�����B
}

void GameScene::move(){
	//�t�h�̃p���[�����P�b�g�ɗ^���ăX�s�[�h�ύX���Ă���B
	RoPos = _rocket->getPosition();
	_rocket->setPower(_UILayer->getmeterReturn());
	RoPos = Vec2(RoPos.x, RoPos.y + _rocket->getPower());
	_rocket->setPosition(RoPos);

	//�|�W�V�����̈ʒu����ʉz������
	if (_rocket->getPositionY() > 600){
		_rocket->setPosition(Vec2(_rocket->getPositionX(), 0));
	}
}

void GameScene::move2(){
	//���P�b�g�ƖړI�̐������o����B
	auto vec2hosi = stars.at(1);

	//�p�x�����߂�
	float angle = ccpToAngle(ccpSub(_rocket->getPosition(),vec2hosi->getPosition()));

	//�ړ��ʂ����߂�
	float PlayerMoveX = _UILayer->getmeterReturn()*cos(angle);
	float PlayerMoveY = _UILayer->getmeterReturn()*sin(angle);

	//�������������Ă���Ȃ���ۂɈړ�������
	if (ccpDistance(_rocket->getPosition(), vec2hosi->getPosition()) > 1.0f){
		float PlayerNewX = _rocket->getPosition().x - PlayerMoveX;
		float PlayerNewY = _rocket->getPosition().y - PlayerMoveY;
		_rocket->setPosition(Vec2(PlayerNewX, PlayerNewY));
	}
}