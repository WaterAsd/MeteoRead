#ifndef __MATEOREAD__SPACE__
#define __METEOREAD__SPACE__

#include "cocos2d.h"

class space:public cocos2d::Layer{
public:
	virtual bool init();
	CREATE_FUNC(space);
};

#endif //__METEOREAD__SPACE__