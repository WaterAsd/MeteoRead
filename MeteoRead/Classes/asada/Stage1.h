#include "cocos2d.h"
#include "asada/Stagebase.h"

class Stage1 :public Stagebase{
protected:
	//画面サイズの表記と真ん中の中心を変数として入れておく
	Size visibleSize;
	Vec2 origin;
	
	//ロケットにカメラを追尾させるために使用する変数
	Follow *_setrocket;

	//選択したステージの変数
	int _stageselect;

	//ステージの大きさ
	Rect _stagesize;

private:
	virtual bool init();			//初期化宣言
	void update(float delta);	//毎フレーム更新する
	void setRoad();				//道を作成する

	void setStagesize();		//現在のステージの大きさをせっていする

public:
	//layerをいどうさせる
	void moveLayer(Vec2 move);

	//rocketにカメラを追尾するための処理
	void follorRocket(Rocket* rocket);	

	//rocketにカメラを追尾させないためにの処理
	void stopRocket();

	//選択したステージを表示させる
	void stagecreate(int count);

	//選択したステージの番号を取得する
	void setStageSelect(int count);

	//ロケットの位置情報を渡す
	Vec2 getrocket();
	//星の位置情報を渡す
	Vec2 getstar(int i);
	//ゴール以外の星の数を取得する
	int getstarcount();
	//stageの大きさを渡す
	Rect getstagesize();
	//ゴールの場所を渡す
	Vec2 getgoal();


	CREATE_FUNC(Stage1);//クラスの宣言
};