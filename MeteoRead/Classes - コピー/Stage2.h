#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage2 :public Stagebase{
protected:

private:
	virtual bool init();			//�������錾
	void update(float delta);	//���t���[���X�V����
	void setRoad();				//�����쐬����
public:
	CREATE_FUNC(Stage2);//�N���X�̐錾
};