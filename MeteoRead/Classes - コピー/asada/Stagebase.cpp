#include "Stagebase.h"

//�����쐬���邱�Ƃ��ł��܂�
void Stagebase::StarSet(Vec2 Pos, std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//���̐����₷�B
	stars.pushBack(earth);//���̏���ۑ�����B
	//starsname.pushBack(hosimei);//���̖��O���擾���Ă���
}

//�S�[���ƂȂ鐯���쐬���邱�Ƃ��ł��܂��B
void Stagebase::GoalStarset(Vec2 Pos, std::string hosimei){
	if (goalset == true){}

	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars2.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		starCount++;//���̐����₷�B
		stars.pushBack(earth);//���̏���ۑ�����B
		goalset == false;
	}
}

//���]����ق����߂��ɂ��邩�ǂ���
void Stagebase::selectSter(Earth* hosi){
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

//�X�^�[�g���Ă��悢���̃t���O
void Stagebase::setstartflg(const bool flg){
	_startflg = flg;
}

//���P�b�g�̃p���[�����炤�֐�
void Stagebase::setrocketpower(const int power){
	_rocketpower = power;
}

//�{�^�����^�b�`�������ǂ����𔻒肷��֐�
void Stagebase::setbottontouch(bool touch){
	_buttontouch = touch;
}

//�S�[���������ǂ�����Ԃ����߂̊֐�
bool Stagebase::getgoalflg(){
	return _goalflg;
}

//���P�b�g�̃p���[���󂯎��t���O
int Stagebase::getRocketPower(){
	return _rocketpower;
}