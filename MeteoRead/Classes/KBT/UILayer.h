#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d;

class MapNode : public cocos2d::Node{
public:
	//��ʂɕ\��������ׂ̑f�ނ��l�����邽�߂̊֐�
	void setrocket(Vec2 rocket);
	void setstarpos(std::vector<Vec2> pos);
	void setgoalpos(Vec2 goal);
	void setStagerect(Rect stagesize);

	//��ʃT�C�Y�̒�����}�邽�߂̕ϐ�
	void mapcreate();
	void Mapsize();

	//�N���X�����ׂɕK�v�Ȃ���
	CREATE_FUNC(MapNode);
private:
	//mapcreate�����x���쐬����̂Ő�����������
	bool oneflg;

	//�ȒP�ɕK�v�Ȃ���
	virtual bool init();
	void update(float dt);

	//���݂̐��̍��W���l������
	Vec2 _rocketpos;
	Vec2 _goalpos;
	std::vector<Vec2>_starpos;
	Rect _stagesize;

	//���P�b�g�̉摜��K�v�ȑf�ނ̉摜�̎��
	Sprite *_rocket;
	cocos2d::Vector<CCDrawNode*> _star;
	CCDrawNode *_goal;

	//�}�b�v�̕��ϓI�ȃT�C�Y���l������
	Vec2 mapsize;

	//�}�b�v�̔w�i���擾���邽�߂̂���
	Sprite *_map;
};

/*--------------------------------------------------------------------------------------------------------------------

��������UiLayer�ł��B




---------------------------------------------------------------------------------------------------------------------*/

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// ��ʃT�C�Y

	//Sprite
	Sprite* meter;              //���[�^�[�̉摜
	Sprite* button;             //�{�^���̉摜
	Sprite* myIcon;             //���P�b�g�̃A�C�R��
	Sprite* starIcon;
	Sprite* number[6];             //����

	//int
	int up;                     //���[�^�[�̕\���p�̕ϐ��@0�`5
	int upCount;                //�J�E���g
	int timer[6];	//0,1=���@2,3=�b�@4,5=�R���}

	//float
	float power;//���P�b�g�̈ړ���

	//Point
	Point touchPoint;				// �^�b�`���ꂽ�ꏊ

	//Rect
	Rect buttonRect;             //�{�^���̃��N�g

	//Label
	Label *clock[3];

	//Color3B
	Color3B buttonColor;//�{�^���̐F

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�������̏���
	virtual void onTouchEnded(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// �^�b�`�𗣂������̏���

	void Button();
	void MeterMove();//���[�^�[�̃N���X
	void Map();//�}�b�v�̃N���X
	void Timer();//���Ԃ̃N���X

	void CreateSprite();	// �摜�쐬�N���X

	//���݂̐��̍��W���l������
	Vec2 _rocket;
	Vec2 _goal;
	std::vector<Vec2>_starpos;
	//�}�b�v�̕��ϓI�ȃT�C�Y���l������
	Rect mapsize;

private:

public:
	MapNode *_minimap;

	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	bool getTouch();

	int getmeterReturn();

	bool touch;

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__