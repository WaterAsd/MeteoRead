#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"
#include "asada/StartScene.h"
#include "KBT/Road.h"
#include "asada/Goal.h"
#include "asada/Stage1.h"
#include "Stage.h"

//�Q�[���̏�Ԃ�\���Ă���񋓌`
enum GameState{
	START = 0,
	GAME,
	CLEAR,
	GAMEOVER,
	GAMEEND,
	MAXGAMESTATE
};

class GameScene : public cocos2d::Layer
{
private:
	//�Q�[����Ԃ�\���Ă���ϐ�
	GameState _gamestate;

	UILayer* uiLayer;

	bool _startflg;

	Vec2 touchpoint;

	Size visibleSize;
	Vec2 origin;

	Stage *_stage1;
	
	Calculation* _Cal;//�v�Z�@�̃|�C���^�[
	StartScene* _start;
	Road* _road;

	std::string goalmai;//���ɓ���閼�O�i�S�[���t���O�H�j
	bool goalset;		//���̃S�[���͈�Ȃ̂Ńt���O���쐬
	bool goalflg;

	UILayer* _UILayer;

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//���̐����o���Ă���
	Vector<Earth*> stars;//���̍��W�ꗗ���擾����B

	void StarSet(Vec2 Pos, std::string hosimei);//��ʂɐ�������B
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//���]����ق����߂��ɂ��邩�ǂ���

	Earth *axishosi;//���ƂȂ���]�̐�

	bool touchOK;	//���]���ɔ��˂̏�����݂���B
					//true:���ˏ�����
					//false:���˂������͒��i��

	//�t�h�̃~�j�}�b�v�ɕK�v�ȏ�������
	void minimapdate();

public:
	void Start();
	void GameOver();
	void GameClear();

	static int SelectCount;
	void getStage(int count);
	Stagebase craeateStage(int count);

	static bool gameOver;

	static Vec2 RoPos;
	static Vec2 starPos[4];
	static Vec2 goalPos;

	static cocos2d::Scene* createScene();//�Q�[���V�[���̍쐬
	virtual bool init();//�������錾
	void update(float delta);	//���t���[���X�V����
	CREATE_FUNC(GameScene);//�N���X�̐錾
	static Earth* earth;//���N���X���g����l�ɂ���B
};

#endif //__METEOREAD__GAME__