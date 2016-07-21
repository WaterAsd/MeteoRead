#ifndef __METEOREAD__GAMEOVER__
#define __METEOREAD__GAMEOVER__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace std;
class GameOver : public cocos2d::Layer{
protected:
private:
	//ïœêî
	cocos2d::Sprite *_goalimage;
	cocos2d::ui::Button *_backimage;
	cocos2d::ui::Button*_restart;

	void restarttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

public:
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(GameOver);
};

#endif//__METEOREAD__GAMEOVER__