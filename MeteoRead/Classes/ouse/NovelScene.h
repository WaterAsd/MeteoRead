#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
private:
	
	//int
	int
		_chrcount,		//���݂̕����Ԗ�
		_autoflg,       //NovelScene�ɓ�������true��
		_autocnt,       //�����\����Ɏ��̍s�ɕς��܂őҋ@���鎞��
		_index,			//���݂̍s�Ŗ�
		count;			//���t���[���̃J�E���g��
	
	//float
	float _speed;		//��������̃X�s�[�h	

	//�s�̈ꗗ���쐬�����B������
	std::string str[1024];
	//�Q�[����ʂ̕\�������邽�߂�string�^
	std::string s;
	//��Ƃ��₷�����邽�߂Ƀ|�C���^�[���쐬����
	cocos2d::Label *label;
	//string
	std::string _currentString;//���ݕ\�����������s�̕����ꗗ

	void autospeedup();
	void autospeeddown();
	std::vector<std::string> split(const std::string& input, char delimiter);

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void update(float dt);

	//CREATE_FUNC�}�N�����g�p���āAstatic��create���\�b�h����������
	CREATE_FUNC(NovelScene);
};

#endif // _NOVEL_SCENE_H_