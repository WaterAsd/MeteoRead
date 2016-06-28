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
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//�S�[�����鐯�ɓ���閼�O�̐ݒ�
	goalset = false;
	goalmai = std::string("goal");

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
	/*auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);

	_Cal->hosiangle(hosi1, hosi2, 1.0f);*/
}

//���̓���\������
void Stage1::setRoad(){
	auto hoge = Sprite::createWithTexture(_star->getTexture());
	hoge->setPosition(_rocket->getPosition());
	this->addChild(hoge,-1);
}

//�X�e�[�W�ɂ���Đ���z�u����
void Stage1::stagecreate(int count){
	auto hosimei = std::string("Earth.png");
	auto rocket = Rocket::create();

	switch (count)
	{
	case 1:
		/*�����ɐ���z�u������̂���͂��Ă��������B*/
		StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
		StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);
		GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

		/*�����Ƀ��P�b�g�̔z�u�ꏊ����͂��Ă��������B*/
		rocket->setPosition(visibleSize.width,0);
		rocket->setRotation(-90);
		follorRocket(rocket);
		this->addChild(rocket);
		_rocket = rocket;
		break;
	case 2:
		/*�����ɐ���z�u������̂���͂��Ă��������B*/
		StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
		StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);
		GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

		/*�����Ƀ��P�b�g�̔z�u�ꏊ����͂��Ă��������B*/
		rocket->setPosition(visibleSize.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	default:
		break;
	}
}

//�I�������X�e�[�W��\������B
void Stage1::setStageSelect(const int count){
	_stageselect = count;
}

//rocket�ɃJ������ǔ����邽�߂̏���
void Stage1::follorRocket(Rocket* rocket){
	_setrocket = Follow::create(rocket);
	_setrocket->setTag(20);
	this->runAction(_setrocket);
}

//Rocket�̎����ǔ�����߂邽�߂̏���
void Stage1::stopRocket(){
	this->stopActionByTag(20);
}

//Layer���ړ�������
void Stage1::moveLayer(Vec2 move){
	this->setPosition(this->getPosition() + move);
}

//���P�b�g�̈ʒu����n��
Vec2 Stage1::getrocket(){
	return _rocket->getPosition();
}
//���̈ʒu����n��
Vec2 Stage1::getstar(int i){
	if (stars.size() > i){
		auto star = stars.at(i);
		return star->getPosition();
	}
}
//�S�[���ȊO�̐��̐����擾����
int Stage1::getstarcount(){
	return stars.size();
}
//stage�̑傫����n��
Rect* Stage1::getstagesize(){
	return _stagesize;
}
//�S�[���̏ꏊ��n��
Vec2 Stage1::getgoal(){
	for (auto star:stars){
		if (star->getName() == goalmai){
			return star->getPosition();
		}
	}
}