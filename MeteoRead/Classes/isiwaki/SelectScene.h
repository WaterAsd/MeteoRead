#ifndef __SEKECTSCENE_SCENE_H__
#define __SELECTSCENE_SCENE_H__

#include "cocos2d.h"

class SelectScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(SelectScene);
};

#endif // __HELLOWORLD_SCENE_H__