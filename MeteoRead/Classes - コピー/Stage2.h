#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage2 :public Stagebase{
protected:

private:
	virtual bool init();			//初期化宣言
	void update(float delta);	//毎フレーム更新する
	void setRoad();				//道を作成する
public:
	CREATE_FUNC(Stage2);//クラスの宣言
};