#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:
	//��ʃT�C�Y�̕\�L�Ɛ^�񒆂̒��S��ϐ��Ƃ��ē���Ă���
	Size visibleSize;
	Vec2 origin;
	
	//���P�b�g�ɃJ������ǔ������邽�߂Ɏg�p����ϐ�
	Follow *_setrocket;

	//�I�������X�e�[�W�̕ϐ�
	int _stageselect;

	//�X�e�[�W�̑傫��
	Rect _stagesize;

private:
	virtual bool init();			//�������錾
	void update(float delta);	//���t���[���X�V����
	void setRoad();				//�����쐬����

	void setStagesize();		//���݂̃X�e�[�W�̑傫���������Ă�����

public:
	//layer�����ǂ�������
	void moveLayer(Vec2 move);

	//rocket�ɃJ������ǔ����邽�߂̏���
	void follorRocket(Rocket* rocket);	

	//rocket�ɃJ������ǔ������Ȃ����߂ɂ̏���
	void stopRocket();

	//�I�������X�e�[�W��\��������
	void stagecreate(int count);

	//�I�������X�e�[�W�̔ԍ����擾����
	void setStageSelect(int count);

	//���P�b�g�̈ʒu����n��
	Vec2 getrocket();
	//���̈ʒu����n��
	Vec2 getstar(int i);
	//�S�[���ȊO�̐��̐����擾����
	int getstarcount();
	//stage�̑傫����n��
	Rect getstagesize();
	//�S�[���̏ꏊ��n��
	Vec2 getgoal();


	CREATE_FUNC(Stage1);//�N���X�̐錾
};