#include "Stage.h"
USING_NS_CC;
bool Stage::init(){
	if (!Layer::init()){ return false; }

	//��ʃT�C�Y���擾����
	_gamewindou = Director::getInstance()->getVisibleSize();

	//���P�b�g�̏��𐶐�
	auto rocket = Rocket::create();
	this->addChild(rocket);
	_rocket = rocket;

	auto black = Sprite::create("new black hole sample.png");
	black->setPosition(Vec2(_gamewindou.width / 2, _gamewindou.height / 2-100));
	this->addChild(black);

	auto action = RotateTo::create(1, 45);
	auto repeatForever = Repeat::create(action,-1);
	//�A�j���[�V�����J�n
	black->runAction(repeatForever);

	hosikouten = 80;
	goalmai = "goal";
	touchOK = true;
	_gameover = false;

	Statics::flyFlg = true;

	this->scheduleUpdate();

	return true;
}

//
void Stage::update(float dt){
	//�l�擾
	auto speed = _rocket->getSpeed() + Statics::touchCount*0.5f;
	//���P�b�g�̖��ǂ����邩�E�E�E
	_rocket->setArrow(Statics::touchFlg);

	if (_stagerect.containsPoint(_rocket->getPosition())==false){
		Statics::gameOverFlg = true;
	}

	//�z��ɓ����Ă��鐯�̐��܂�for���ŏ���
	if (Statics::flyFlg == true){
		Earth*karihosi = _axishosi;
		float smoleLength = NULL;
		for (auto hosis : _stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= hosikouten && (length < smoleLength || smoleLength == NULL) && karihosi != hosis){
				_rocket->LRCol(hosis, _rocket->getSpeed());
				_axishosi = hosis;
				smoleLength = length;
				Statics::flyFlg = false;
				_rocket->setRocketState(rocketstate::revolution);
			}
		}
	}

	//�S�[���̐��Ɍ��]�ł�����N���A��ʂ��o���B
	if (_rocket->getRocketState() == rocketstate::revolution&&
		_axishosi->getName() == goalmai&&
		Statics::clearFlg == false){
		Statics::clearFlg = true;
	}

	//��Ԃɂ���Đ��l��ύX���Ă���
	switch (_rocket->getRocketState())
	{
	case rocketstate::FLY:
		Statics::flyFlg = true;
		_rocket->move(_rocket->getSpeed());
		break;
	case rocketstate::Prelaunch:
		if (Statics::touchFlg != true)
			_rocket->setRocketState(rocketstate::FLY);
		else
			_rocket->Col(_axishosi, _rocket->getSpeed());//���]������
		break;

	case rocketstate::revolution:
		if (Statics::touchFlg == true)
			_rocket->setRocketState(rocketstate::Prelaunch);
		else if(Statics::touchFlg == false)
			_rocket->Col(_axishosi, _rocket->getSpeed());//���]������
		break;
	}

	_rocket->setArrow(Statics::touchFlg);

	Stage::staticset();
}

//���𐶐�����
void Stage::SetStar(Vec2 Pos, std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	_stars.push_back(earth);
}

//�S�[���̐��𐶐�����
void Stage::Setgoalstar(Vec2 Pos, std::string hosimei){
	if (_goal == 0){}
	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars2.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		_goal = earth;
		_stars.push_back(earth);
	}
}

//static�N���X�ɏ�������
void Stage::staticset(){
	Statics::myPos = _rocket->getPosition();
	Statics::myRot = _rocket->getRotation();
	Statics::starPos.clear();
	for (auto star:_stars){
		Statics::starPos.push_back(star->getPosition());
	}
	Statics::goalPos = _goal->getPosition();
	Statics::stageRect = _stagerect;
}

//�X�e�[�W�𐶐����邽�߂ɓ����N���X
void Stage::StageCreate(int count){
	auto hosimei = std::string("Earth.png");
	auto rocket = Rocket::create();
	Rect stagerect;
	switch (count)
	{
	case 1:
		/*�����ɃX�e�[�W�̑傫����ݒ肷��*/
		stagerect.setRect(-200, -200, _gamewindou.width + 400, _gamewindou.height + 400);
		_stagerect = stagerect;

		/*�����ɐ���z�u������̂���͂��Ă��������B*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*�����Ƀ��P�b�g�̔z�u�ꏊ����͂��Ă��������B*/
		rocket->setPosition(Vec2(_gamewindou.width, 1.0f));
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;
	case 2:
		/*�����ɐ���z�u������̂���͂��Ă��������B*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*�����Ƀ��P�b�g�̔z�u�ꏊ����͂��Ă��������B*/
		rocket->setPosition(_gamewindou.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	case 3:
		/*�����ɐ���z�u������̂���͂��Ă��������B*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*�����Ƀ��P�b�g�̔z�u�ꏊ����͂��Ă��������B*/
		rocket->setPosition(_gamewindou.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	default:
		break;
	}
}