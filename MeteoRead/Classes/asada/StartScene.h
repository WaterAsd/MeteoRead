#ifndef __METEOREAD__START__
#define __METEOREAD__START__

#include "cocos2d.h"

class StartScene:public cocos2d::Layer{
protected:
	bool OK;//game���X�^�[�g���Ă��悢���ǂ���
public:
	bool getStart();//�X�^�[�g���Ă��悢���̊֐���^����
	virtual bool init();//�������ϐ�
	CREATE_FUNC(StartScene);
};

#endif//__METEOREAD__START__