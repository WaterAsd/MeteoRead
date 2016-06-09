#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
private:
	
	//int
	int
		_chrcount,		//現在の文字番目
		_autoflg,       //NovelSceneに入ったらtrueに
		_autocnt,       //文字表示後に次の行に変わるまで待機する時間
		_index,			//現在の行版目
		count;			//毎フレームのカウント数
	
	//float
	float _speed;		//文字送りのスピード	

	//行の一覧を作成した。文字列
	std::string str[1024];
	//ゲーム画面の表示させるためのstring型
	std::string s;
	//作業しやすくするためにポインターを作成する
	cocos2d::Label *label;
	//string
	std::string _currentString;//現在表示させたい行の文字一覧

	void autospeedup();
	void autospeeddown();
	std::vector<std::string> split(const std::string& input, char delimiter);

public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void update(float dt);

	//CREATE_FUNCマクロを使用して、staticなcreateメソッドを実装する
	CREATE_FUNC(NovelScene);
};

#endif // _NOVEL_SCENE_H_