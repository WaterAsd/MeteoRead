#ifndef __MATEOREAD__STAGE1__
#define __METEOREAD__STAGE1__

#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:

private:
	virtual bool init();			//�������錾
	void update(float delta);	//���t���[���X�V����
	void setRoad();				//�����쐬����
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(Stage1);//�N���X�̐錾
};
#endif//__METEOREAD__STAGE1__