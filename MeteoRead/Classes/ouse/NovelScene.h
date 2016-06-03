#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
private:
	//現在の文字番目
	int _chrcount;

	//現在の行版目
	int _index;

	//文字送りのスピード
	float _speed;

	//毎フレームのカウント数
	int count;

	//現在表示させたい行の文字一覧
	std::string _currentString;

public:
	//シーンを作成する
	static cocos2d::Scene* createScene();

	//初期化メソッド
	virtual bool init();

	//行の一覧を作成した。文字列
	std::string str[1024];
	//ゲーム画面の表示させるためのstring型
	std::string s;
	//作業しやすくするためにポインターを作成する
	cocos2d::Label *label;

	int autoflg;
	int autoframe;
	int autocnt;
	int autospeed;
	int mojiframe;
	int mojicnt;
	int mojicnt2;
	bool mojinext;

	void update(float dt);

	//CREATE_FUNCマクロを使用して、staticなcreateメソッドを実装する
	CREATE_FUNC(NovelScene);

private:

	void autospeedup();
	void autospeeddown();
	std::vector<std::string> split(const std::string& input, char delimiter);
	
};

#endif // _NOVEL_SCENE_H_