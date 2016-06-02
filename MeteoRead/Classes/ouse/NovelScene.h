#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
public:
	//シーンを作成する
	static cocos2d::Scene* createScene();

	//初期化メソッド
	virtual bool init();

	cocos2d::Label *label;
	//cocos2d::String str[1024];
	std::string str[1024];
	std::string str2[1024];
	std::string str3[1024];
	std::string str4[1024];
	std::string str5[1024];
	std::string str6[1024];

	int autoflg;
	int autoframe;
	int autocnt;
	int autospeed;
	int mojiframe;
	int mojicnt;
	int mojicnt2;
	bool mojinext;

	//CREATE_FUNCマクロを使用して、staticなcreateメソッドを実装する
	CREATE_FUNC(NovelScene);

private:

	void autospeedup();
	void autospeeddown();
	
};

#endif // _NOVEL_SCENE_H_