#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TitleScene : public cocos2d::Layer
{
protected:
	//Zオーダー
	enum ZOrder
	{
		Z_Bg = 0,
		Z_Button,
		Z_Title,
	};

	void initBackground();//背景の表示

	void initButton();// ボタンの表示
	
	//ボタンのタッチイベント
	void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

public:
	virtual bool init();//初期化
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TitleScene);//create関数作成
};

#endif // __TITLE_SCENE_H__
