#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:
	Size visibleSize;
	Vec2 origin;
	
	Follow *_setrocket;
	int _stageselect;
private:
	virtual bool init();			//初期化宣言
	void update(float delta);	//毎フレーム更新する
	void setRoad();				//道を作成する
public:
	static Vec2 starPos[4];
	void moveLayer(Vec2 move);

	void follorRocket(Rocket* rocket);	//rocketにカメラを追尾するための処理
	void stopRocket();	//rocketにカメラを追尾させないためにの処理

	void stageSelect(int count);
	void setStageSelect(int count);
	CREATE_FUNC(Stage1);//クラスの宣言
};