#ifndef __METEOREAD__GOAL__
#define __METEOREAD__GOAL__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace std;

class Goal : public cocos2d::Layer{
protected:
private:
	/*�ϐ�*/
	cocos2d::Sprite *_goalimage;
	cocos2d::ui::Button *_nextimage;
	cocos2d::ui::Button *_backimage;
	/*�ϐ��I��*/

	/*�֐�*/
	void nexttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	/*�֐��I��*/

public:
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(Goal);
};

#endif//__METEOREAD__GOAL__