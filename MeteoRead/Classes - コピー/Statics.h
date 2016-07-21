#ifndef __STATICS_H__
#define __STATICS_H__

#include "cocos2d.h"
#include "Math.h"

USING_NS_CC;

using namespace cocos2d;

class Statics : public cocos2d::Ref
{
public:
	static Vec2 myPos;  //�v���C���[�̈ʒu
	static int myRot;  //�v���C���[�̉�]��
	static int myPower;//�v���C���[�̈ړ���
	static std::vector<Vec2> starPos;  //���̈ʒu
	static Vec2 goalPos;  //�S�[���̈ʒu
	static Vec2 gimmickPos;  //�M�~�b�N�̈ʒu
	static Rect stageRect;  //�X�e�[�W�̔䗦

	static bool clearFlg;  //�N���A�������ǂ���
	static bool gameOverFlg;  //�Q�[���I�[�o�[�̃t���O

	static bool touchFlg;  //�^�b�`�������ǂ���
	static bool flyFlg;  //���ł邩�ǂ���

	static int stageSelect;  //�X�e�[�W�̔ԍ�
	static int touchCount;
};


#endif//__STATICS__