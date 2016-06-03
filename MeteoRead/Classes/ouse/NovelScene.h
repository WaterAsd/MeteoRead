#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
private:
	//���݂̕����Ԗ�
	int _chrcount;

	//���݂̍s�Ŗ�
	int _index;

	//��������̃X�s�[�h
	float _speed;

	//���t���[���̃J�E���g��
	int count;

	//���ݕ\�����������s�̕����ꗗ
	std::string _currentString;

public:
	//�V�[�����쐬����
	static cocos2d::Scene* createScene();

	//���������\�b�h
	virtual bool init();

	//�s�̈ꗗ���쐬�����B������
	std::string str[1024];
	//�Q�[����ʂ̕\�������邽�߂�string�^
	std::string s;
	//��Ƃ��₷�����邽�߂Ƀ|�C���^�[���쐬����
	cocos2d::Label *label;

	int autoflg;
	int autoframe;
	int autocnt;
	int autospeed;
	int mojiframe;
	int mojicnt;
	int mojicnt2;
	bool mojinext;

	void update(float dt);

	//CREATE_FUNC�}�N�����g�p���āAstatic��create���\�b�h����������
	CREATE_FUNC(NovelScene);

private:

	void autospeedup();
	void autospeeddown();
	std::vector<std::string> split(const std::string& input, char delimiter);
	
};

#endif // _NOVEL_SCENE_H_