#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"

class Rocket : public cocos2d::Node{
private:

	Vec2 RocketPos;//���P�b�g�̍��W
	Rect RocketRect;//���P�b�g�̍��W
	int Power;//���P�b�g�̃p���[��

	void RocketSpeed(int Pw);//���P�b�g�̃X�s�[�h��ݒ肷��

	void boosterCreate();
public:

	Vec2 getRocketPos();
	Rect getRocketRect();
	int  setPower(int pw);

	//�u�[�X�^�[�̉摜���ꖇ���ۑ����Ă������߂̓��ꕨ
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__