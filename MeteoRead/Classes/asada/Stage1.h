#ifndef __MATEOREAD__STAGE1__
#define __METEOREAD__STAGE1__

#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:

private:
	virtual bool init();			//初期化宣言
	void update(float delta);	//毎フレーム更新する
	void setRoad();				//道を作成する
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(Stage1);//クラスの宣言
};
#endif//__METEOREAD__STAGE1__