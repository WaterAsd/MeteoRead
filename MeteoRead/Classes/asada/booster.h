#ifndef __METEOREAD__BOOSTER__
#define __METEOREAD__BOOSTER__

#include "cocos2d.h"

class Booster : public cocos2d::Sprite{
protected:
	Booster();
	virtual ~Booster();
	virtual bool init();
	const int Frame_Count = 4;//���Ɍ������ĉ摜���������邩
	float ANIMETION = 0.1f;//���̉摜�ɐi�ނ܂ł̎���
public:
	void SetPower(int power);
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _boost, Boost);//�����̉摜��Vector
	CREATE_FUNC(Booster);
};

#endif//__METEOREAD__Booster__