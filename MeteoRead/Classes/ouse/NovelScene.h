#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : private cocos2d::Layer
{
public:
	//�V�[�����쐬����
	static cocos2d::Scene* createScene();

	//���������\�b�h
	virtual bool init();

	//�R�[���o�b�N���\�b�h
	void menuCloseCallback(cocos2d::Ref* pSender);

	//CREATE_FUNC�}�N�����g�p���āAstatic��create���\�b�h����������
	CREATE_FUNC(HelloWorld);
};

#endif // _NOVEL_SCENE_H_