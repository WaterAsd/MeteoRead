#include "asada/Stage1.h"

//���]���鐯�Ƃ̋���
const float Hosikoutenn = 80.0f;

//�������̍쐬���܂����B
bool Stage1::init(){
	if (!Layer::init())return false;

	_startflg=false;		
	_goalflg=false;		
	_buttontouch=false;	
	_rocketspeed = 1;
	_rocketpower = 1;

	_star = SpriteBatchNode::create("star2.png");
	this->addChild(_star);

	//��ʃT�C�Y���l������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Space);

	//�����o��������
	auto hosimei = std::string("Earth.png");
	StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
	StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
	StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);

	//�S�[�����鐯�ɓ���閼�O�̐ݒ�
	goalmai = std::string("goal");
	goalset = false;
	GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

	//���P�b�g���o��������
	auto rocket = Rocket::create();
	rocket->setPosition(visibleSize.width, 0);
	rocket->setRotation(-90);
	this->addChild(rocket);
	_rocket = rocket;

	//�v�Z�@���쐬����
	auto Cal = Calculation::create();
	_Cal = Cal;

	this->scheduleUpdate();

	return true;
}

//�X�V����
void Stage1::update(float delta){

	auto speed = _rocketspeed + _rocketpower*0.5f;

	//�z��ɓ����Ă��鐯�̐��܂�for���ŏ�������
	//���e�F���P�b�g�ɋ߂��������邩�ǂ����i��������Ȃ��ԋ߂��ꏊ��I������j
	if (_rocket->getRevolutionflg() == false){
		Earth*karihosi = axishosi;
		float smoleLength = NULL;
		for (auto hosis : stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= Hosikoutenn && (length < smoleLength || smoleLength == NULL) && karihosi != hosis){
				axishosi = hosis;
				smoleLength = length;
				_rocket->setRevolutionflg(true);
			}
		}
	}

	//�S�[���̐��Ɍ��]�ł�����N���A��ʂ��o���B
	if (_rocket->getRevolutionflg() == true &&
		axishosi->getName() == goalmai&&
		_goalflg == false){
		_goalflg = true;
	}

	/*���]�t���O��true��UiLayer��touch��true�Ȃ�
	touchOK��false�ɂ��Ĕ��˂���*/
	if (_rocket->getRevolutionflg() == true &&
		_buttontouch == false &&
		touchOK == true){
		touchOK = false;
		_rocket->setRevolutionflg(false);
	}

	/*���]�t���O��true�ŁAUiLayer��touch��false�Ȃ�
	touchOK��true�ɂ��Ĕ��˂̏���������*/
	if (_rocket->getRevolutionflg() == true &&
		_buttontouch == true){
		touchOK = true;
	}
	//�������]�t���O��true�Ȃ�Ό��]�����āA
	//false�Ȃ�΁A�����Ă�����Ɉړ�������B
	if (_rocket->getRevolutionflg() == true){
		_Cal->angle(axishosi, _rocket, speed);//���]������
	}
	else{
		_Cal->move(_rocket,speed);//���i�^��������
	}

	//�����{�^���������Ă���̂Ȃ����\��������B

	auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);

	_Cal->hosiangle(hosi1, hosi2, 1.0f);
}

void Stage1::setRoad(){
	auto hoge = Sprite::createWithTexture(_star->getTexture());
	hoge->setPosition(_rocket->getPosition());
	this->addChild(hoge,-1);
}