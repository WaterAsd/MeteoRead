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

	//�w�i�ؑ֗p�t���O
	bool back2; //back2.png�ɐؑ�
	bool back3; //back3.png�ɐؑ�

	//�s�̈ꗗ���쐬�����B������
	std::string str[8];
	std::string str2[8];//@a2�̔��f�p
	std::string str3[8];//@a3�̔��f�p

	//�Q�[����ʂ̕\�������邽�߂�string�^
	std::string s;
	//��Ƃ��₷�����邽�߂Ƀ|�C���^�[���쐬����
	cocos2d::Label *label;
	//string
	std::string _currentString;//���ݕ\�����������s�̕����ꗗ

	//BGM
	float BGM;

	//�w�i�����Ă������߂̔�
	cocos2d::Sprite* background2;
	cocos2d::Sprite* background3;

	void autospeedup();
	void autospeeddown();
	std::vector<std::string> split2(const std::string& input, char delimiter);

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void update(float dt);

	//CREATE_FUNC�}�N�����g�p���āAstatic��create���\�b�h����������
	CREATE_FUNC(NovelScene);
};

#endif // _NOVEL_SCENE_H_