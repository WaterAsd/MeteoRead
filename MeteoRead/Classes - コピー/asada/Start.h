#ifndef __METEOREAD__START__
#define __METEOREAD__START__

#include "cocos2d.h"

class Start: public cocos2d::Sprite{
protected:
	bool OK;//game���X�^�[�g���Ă��悢���ǂ���
public:
	bool getStart();//�X�^�[�g���Ă��悢���̊֐���^����
	virtual bool init();//�������ϐ�
	CREATE_FUNC(Start);
};

#endif//__METEOREAD__START__