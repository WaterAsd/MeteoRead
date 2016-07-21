#ifndef __STAGE__H__
#define __STGAE__H__

#include "cocos2d.h"
#include "Statics.h"
#include "asada/Rocket.h"
#include "asada/Earth.h"

class Stage :public cocos2d::Layer{
private:

	Size _gamewindou;
	int hosikouten;
	bool touchOK;

	//���̖��O������ϐ�
	std::string goalmai;

	//����ϐ�
	Rocket *_rocket;				//���P�b�g�̏��
	std::vector<Earth*> _stars;		//���̏��
	Earth* _goal;					//�S�[���̏��
	Rect _stagerect;				//�X�e�[�W�̑傫��

	bool _gameover, _gameclear;		//�Q�[���I�[�o�[�ƃQ�[���N���A
	bool _col;						//���]���Ă��邩�ǂ���

	Earth *_axishosi;				//���ݑI�����Ă��鐯

	//����N���X
	void SetStar(Vec2 Pos, std::string hosimei);
	void Setgoalstar(Vec2 Pos, std::string hosimei);

public:
	void StageCreate(int count);

	void staticset();

	//�N���X�����ɕK�v�Œ���̃N���X
	virtual bool init();			
	void update(float delta);

	CREATE_FUNC(Stage);
};

#endif//__STAGE__H__