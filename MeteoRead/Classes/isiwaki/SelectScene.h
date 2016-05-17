#ifndef __SEKECTSCENE_SCENE_H__
#define __SELECTSCENE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class SelectScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	int sceneInit();
	void update(float delta);


    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(SelectScene);

private:
	void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	

};

#endif // __HELLOWORLD_SCENE_H__