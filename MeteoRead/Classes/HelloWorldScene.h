#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
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

#endif // __HELLOWORLD_SCENE_H__
