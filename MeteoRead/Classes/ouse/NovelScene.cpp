#pragma execution_character_set("utf-8")
#include "ouse/NovelScene.h"
#include "ui/CocosGUI.h"
#include "oohasi\Title.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//BGM（SimpleAudioEngine）使うために必要
using namespace CocosDenshion;

Scene* NovelScene::createScene()
{
	// scene 自動生成オブジェクト
	auto scene = Scene::create();
	// layer 自動生成オブジェクト
	auto layer = NovelScene::create();
	// layer sceneの子として追加
	scene->addChild(layer);
	// scene の値を返す
	return scene;
}

// 初期化メソッド
bool NovelScene::init()
{
	// 親であるLayerクラスの初期化
	if (!Layer::init())
	{
		return false;
	}
	_autoflg = false;

	//背景切替フラグ
	back2 = false;
	back3 = false;

	//BGM
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("BGM/BGMNovel.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("BGM/BGMNovel.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/BGMNovel.mp3", true);

	//ゲームの画面サイズと画面の一番端の座標を取得する
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//画像読み込み
	//背景
	auto background = Sprite::create("back.jpg");
	//座標
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//画像の大きさ
	background->setScale(1.0);
	background->setScaleX(1.5);
	//表示　後ろの数字はレイヤーみたいなもん!
	this->addChild(background, 0);

	//背景2
	background2 = Sprite::create("back2.png");
	//座標
	background2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//画像の大きさ
	background2->setVisible(false);
	background2->setScale(1.0);
	background2->setScaleX(1.5);
	//表示　後ろの数字はレイヤーみたいなもん!
	this->addChild(background2, 1);

	//背景3
	background3 = Sprite::create("back3.png");
	//座標
	background3->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//画像の大きさ
	background3->setVisible(false);
	background3->setScale(1.0);
	background3->setScaleX(1.5);
	//表示　後ろの数字はレイヤーみたいなもん!
	this->addChild(background3, 1);

	//メッセージウィンドウの設定
	auto Back = Sprite::create("box_blue.png");
	//座標
	Back->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	//画像の大きさ
	Back->setScale(1.3);
	//表示　後ろの数字はレイヤーみたいなもん!
	this->addChild(Back, 3);

	// 文字の一覧を特定の条件を満たしたときに入れ物を入れ替える
	// Vector型の入れ物を作成する。
	/*
		@input:入れる元となる文字の一覧
		@delimiter:入れ替えるタイミングのchar型
					（この文字が来たら次の箱に入れていく）
	*/
	auto split = [](const std::string& input, char delimiter)
	{
		std::istringstream stream(input);
		std::string field;
		std::vector<std::string> result;
		while (std::getline(stream, field, delimiter))
		{
			result.push_back(field);
		}
		return result;
	};

	//自分が作成したテキストファイルを特定のstring型に入れる
	auto fileText = FileUtils::getInstance()->getStringFromFile("titlez.csv");
	auto lines = split(fileText,'P');

	//先ほど作成したファイルを
	int i = 0;
	std::string go;
	for (const auto &line : lines){
		auto linego = split(line, ',');
		str[i] = StringUtils::format("%s", linego[1].c_str());  //本編
		str2[i] = StringUtils::format("%s", linego[0].c_str());  //本編
		str3[i] = StringUtils::format("%s", linego[0].c_str());  //本編
		i++;
	}

	//文字表示
	//文字を表示するために必要な情報を記入する
	/*
		文字サイズ：２５px
		文字カラー:白色
		文字は左寄せで表示
		位置は525×135のところで
		最後にポインターに入れてどこでも使えるようにする。
	*/
	label = Label::createWithSystemFont("", "fonts/HGRPP1.TTC", 25);
	label->setWidth(650);
	label->setOpacity(255);
	label->setColor(Color3B::WHITE);
	label->setAnchorPoint(Vec2(0.0f,1.0f));
	label->setPosition(150,150);
	this->addChild(label,100);

	//文字に関する変数の初期化
	_index = 0;
	_chrcount = 0;
	_autocnt = 120;
	_speed = 0;
	count = 0;

	//updateを使えるようにする
	this->scheduleUpdate();
	
	return true;
}

//更新処理
void NovelScene::update(float dt){
	//条件に満たしたら文字を表示させる(数字は次の文字へ送るまでのカウント)
	if (count >= 1){
		count = 0;
		_chrcount++;
	}

	s = str[_index].substr(0, _chrcount).c_str();//0～chrcountの文字をsに入れる
	//現在の行の文字を表示させる
	label->setString(s);//sの内容をlabelに入れる

	//もし一行の文字を全部表示したら・・・
	//autocnt開始
	if (str[_index] == s){
		_autocnt--;
	}

	//autocntが0になったら、改行して次の行の文字を表示させる。
	if (_autocnt == 0){
		_chrcount = 0;
		_index++;
		_autocnt = 120;
	}

	auto ok = str->size();

	//そして、全部を表示させることができたら
	//Sceneを変更する
	if (8 == _index){
		auto Scenes = Title::createScene();
		auto trnscene = TransitionFadeUp::create(1.0f, Scenes);
		Director::getInstance()->replaceScene(Scenes);
	}
	count++;

	//行数を見て背景画像を変える処理
	//今の行数に応じて、背景フラグをtrueに
	if (str2[_index].compare(0, 10, "\r\n@a2") == 0){
		back2 = true;
	}

	if (str3[_index].compare(0, 10, "\r\n@a3") == 0){
		back3 = true;
	}

	//背景フラグがtrueになったら、その背景を表示
	if (back2 == true){
		background2->setVisible(true);//背景を表示させるプログラム
	}

	if (back3 == true){
		background3->setVisible(true);//背景を表示させるプログラム
	}
}

//ラムダ式でもあったけど
//普通に使いたので関数作成しました。
// Vector型の入れ物を作成する。
/*
	@input:入れる元となる文字の一覧
	@delimiter:入れ替えるタイミングのchar型
例:
intputの中身：あいうえお、かきくけこ、さしすせそ
delimiterの中身:”、だった場合
[0]あいうえお
[1]かきくけこ
[2]さしすせそ
*/

std::vector<std::string> NovelScene::split2(const std::string& input, char delimiter){
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (std::getline(stream, field, delimiter))
	{
		result.push_back(field);
	}
	return result;
}