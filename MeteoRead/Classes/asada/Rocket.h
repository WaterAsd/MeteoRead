#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"
#include "asada/booster.h"
#include "asada\Earth.h"
using namespace cocos2d;

enum rocketstate{
	FLY = 0,	//���ł���
	Prelaunch,	//���ˑO
	revolution,	//���]���Ă���
	MAX = 3
};

class Rocket : public cocos2d::Node{
private:
	//�p���[�̗񋓕����쐬����
	enum Speed{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	};
	Speed _speed;
	int speed;
	float rot;

	Sprite *_arrow;//���摜�����Ă������߂̃|�C���^�[�ϐ�
	bool _flgarrow;//�����o���Ă��悢�����m�F����bool�^

	Sprite* _Rocket;//���P�b�g������l�ɂ���ׂ̃|�C���^�[
	Booster* _booster;//�u�[�X�^�[��������l�ɂ��邽�߂̃|�C���^�[

	
	Rect RocketRect;//���P�b�g�̋�`

	bool revolutionflg;//���]�����s������t���O

	void update(float dt);

public:
	//���P�b�g�̏�Ԃ�\���Ă���ϐ�
	CC_SYNTHESIZE(rocketstate, _rockcetstate, RocketState);

	static Vec2 RocketPos;//���P�b�g�̍��W
	//�摜�̍ő�T�C�Y
	const int MAXSPRITEX = 40;
	const int MAXSPRITEY = 60;

	//���P�b�g�̍��W�ɂ܂��֐�
	void setRocketPos(Vec2 pos);
	Vec2 getRocketPos();

	//���P�b�g�̋�`�ɂ܂��֐�
	void setRocketRect(Rect re);
	Rect getRocketRect();

	//���P�b�g�̑����ɂ܂��ϐ�
	float getSpeed();

	//���P�b�g�����]���邽�߂Ƀt���O
	void setRevolutionflg(bool flg);
	bool getRevolutionflg();

	//�ړ��Ɋւ���֐�����
	void move(float speed);
	void Col(const Earth*,int speed);

	//�����o���Ă��悢�����m�F���鏈��
	void setArrow(const bool flg);

	//�u�[�X�^�[�̉摜���ꖇ���ۑ����Ă������߂̓��ꕨ
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__