#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:
	Size visibleSize;
	Vec2 origin;
	
	Follow *_setrocket;
	int _stageselect;
private:
	virtual bool init();			//�������錾
	void update(float delta);	//���t���[���X�V����
	void setRoad();				//�����쐬����
public:
	static Vec2 starPos[4];
	void moveLayer(Vec2 move);

	void follorRocket(Rocket* rocket);	//rocket�ɃJ������ǔ����邽�߂̏���
	void stopRocket();	//rocket�ɃJ������ǔ������Ȃ����߂ɂ̏���

	void stageSelect(int count);
	void setStageSelect(int count);
	CREATE_FUNC(Stage1);//�N���X�̐錾
};