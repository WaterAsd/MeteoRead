#ifndef __METEOREAD__GOAL__
#define __METEOREAD__GOAL__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace std;

class Goal : public cocos2d::Layer{
protected:
private:
	/*変数*/
	cocos2d::Sprite *_goalimage;
	cocos2d::ui::Button *_nextimage;
	cocos2d::ui::Button *_backimage;
	cocos2d::ui::Button*_restart;
	/*変数終了*/

	/*関数*/
	void nexttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	/*関数終了*/

public:
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(Goal);
};

#endif//__METEOREAD__GOAL__