#ifndef __SEKECTSCENE_SCENE_H__
#define __SELECTSCENE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
//SimpleAudioEngineが利用できるように設定する
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

using namespace std;

class SelectScene: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	int sceneInit();
	void update(float delta);
	static int StageText;
	//int SelectCount;
	int ButtonFlashing;
	cocos2d::ui::Button *ButtnSET;
	//string font; // 使用するフォント
	float fontopacity;;
	


    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(SelectScene);


private:
	void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void thochButton(Ref *pSender, cocos2d::ui::Widget::TouchEventType type, int i);
	
};

#endif // __HELLOWORLD_SCENE_H__