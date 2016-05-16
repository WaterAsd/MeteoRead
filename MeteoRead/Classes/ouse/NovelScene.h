#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
public:
	//�V�[�����쐬����
	static cocos2d::Scene* createScene();

	//���������\�b�h
	virtual bool init();

	Sprite *background;

	int mojiframe;
	int mojicnt;
	int mojicnt2;
	bool mojinext;

	//CREATE_FUNC�}�N�����g�p���āAstatic��create���\�b�h����������
	CREATE_FUNC(NovelScene);

	//�R�[���o�b�N���\�b�h
private:
	virtual void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif // _NOVEL_SCENE_H_