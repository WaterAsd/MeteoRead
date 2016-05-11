#ifndef __METEOREAD__EARTH__
#define __METEOREAD__EARTH__

#include "cocos2d.h"

class Earth : public cocos2d::Sprite{
protected:
	Earth();
	virtual ~Earth();
	virtual bool init();
	const int UP_PIC = 2;//�㉺�ɉ����̉摜�����邩�H
	const int Frame_Count = 8;//�ꖇ�̒��ɂ����摜�̑�����
	const float Anemation = 0.11;//���̉摜�ɐi�ނ܂ł̎���
public:
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _earth,earth);//�����̉摜��Vector
	CREATE_FUNC(Earth);
};

#endif//__METEOREAD__EARTH__