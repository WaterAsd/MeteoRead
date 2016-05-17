#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"
#include "asada/booster.h"
using namespace cocos2d;

class Rocket : public cocos2d::Node{
private:
	Sprite* _Rocket;//���P�b�g������l�ɂ���ׂ̃|�C���^�[
	Booster* _booster;//�u�[�X�^�[��������l�ɂ��邽�߂̃|�C���^�[

	Vec2 RocketPos;//���P�b�g�̍��W
	Rect RocketRect;//���P�b�g�̋�`
	int  Power;//���P�b�g�̃p���[(��)
	void RocketSpeed(int Pw);//���P�b�g�̃X�s�[�h��ݒ肷��

	void update(float dt);

public:

	//�摜�̍ő�T�C�Y
	const int MAXSPRITEX = 40;
	const int MAXSPRITEY = 60;

	void setRocketPos(Vec2 pos);//���P�b�g�̍��W�𑗂�
	void setRocketRect(Rect re);//���P�b�g�̋�`�𑗂�
	void setPower(int pw);//���P�b�g�̑�����ς���

	//�u�[�X�^�[�̉摜���ꖇ���ۑ����Ă������߂̓��ꕨ
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__