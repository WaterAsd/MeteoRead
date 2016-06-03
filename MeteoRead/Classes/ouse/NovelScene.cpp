#pragma execution_character_set("utf-8")
#include "ouse/NovelScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

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

	autoflg = false;
	autoframe = false;
	autocnt = false;
	autospeed = false;
	mojicnt = false;
	mojiframe = false;

	//画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//マルチレゾリューション
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto textField = ui::TextField::create("ンゴ", "", 45);
	textField->setPosition(Vec2(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.7 + origin.y));

	this->addChild(textField);

	//画像を表示
	auto sprite = Sprite::create("window2.png");
	////中央に表示されるように座標を設定
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	sprite->setScale(0.75);
	////画像を追加　第2引数は表示する順番（背景だから一番下つまり0）
	this->addChild(sprite, 0);

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

	int i = 0;
	int x = 0;
	int y = 0;

	auto fileText = FileUtils::getInstance()->getStringFromFile("title.csv");
	auto lines = split(fileText, '\n');

	for (const auto &line : lines){
		auto ls = split(line, ',');
		str[i] = StringUtils::format("%s", ls[0].c_str());  //本編
		i++;
	}

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
	label->setColor(Color3B::BLACK);
	//label->setHorizontalAlignment(TextHAlignment::LEFT);
	label->setPosition(525, 135);
	this->addChild(label,100);

	//文字に関する変数の初期化
	_index = 0;
	_chrcount = 0;
	_speed = 0;
	count = 0;

	//updateを使えるようにする
	this->scheduleUpdate();
	
	return true;
}

//更新処理
void NovelScene::update(float dt){
	if (count >= 50){
		count = 0;
		_chrcount++;
	}
	s = str[_index].substr(0,_chrcount).c_str();
	//現在の行の文字を表示させる
	label->setString(s);
	count += 1;
}

//ラムダ式でもあったけど
//普通に使いたので関数作成しました。
std::vector<std::string> NovelScene::split(const std::string& input, char delimiter){
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (std::getline(stream, field, delimiter))
	{
		result.push_back(field);
	}
	return result;
}