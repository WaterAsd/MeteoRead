#ifndef __METEOREAD__START__
#define __METEOREAD__START__

#include "cocos2d.h"

class StartScene:public cocos2d::Layer{
protected:
	bool OK;//gameがスタートしてもよいかどうか
public:
	bool getStart();//スタートしてもよいかの関数を与える
	virtual bool init();//初期化変数
	CREATE_FUNC(StartScene);
};

#endif//__METEOREAD__START__