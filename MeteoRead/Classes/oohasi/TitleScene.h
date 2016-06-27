#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class TitleScene : public cocos2d::Layer
{
protected:
	//Z�I�[�_�[
	enum ZOrder
	{
		Z_Bg = 0,
		Z_Button,
		Z_Title,
	};

	void initBackground();//�w�i�̕\��

	void initButton();// �{�^���̕\��
	
	//�{�^���̃^�b�`�C�x���g
	void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

public:
	virtual bool init();//������
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TitleScene);//create�֐��쐬
};

#endif // __TITLE_SCENE_H__
