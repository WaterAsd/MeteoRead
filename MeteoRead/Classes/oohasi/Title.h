#ifndef __HELLOWORLD_TITLE_H__
#define __HELLOWORLD_TITLE_H__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
public:
	virtual bool init();
    static cocos2d::Scene* createScene();

	void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Title);
};

//BGM
//float BGM;

#endif // __HELLOWORLD_TITLE_H__
