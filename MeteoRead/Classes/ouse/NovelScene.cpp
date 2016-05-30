#pragma execution_character_set("utf-8")//日本語が使えるようになる魔法の言葉
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
	this->addChild(sprite, 3);

	// txtファイルから読み込み
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
	auto char1 = lines[0][1];



	//for (const auto& line : lines)
	//{
	//	auto ls = split(line, ',');

	//	str[i] = StringUtils::format("%s", ls[5].c_str());  //本編
	//	str2[i] = StringUtils::format("%s", ls[0].c_str());  //命令
	//	str3[i] = StringUtils::format("%s", ls[1].c_str());  //命令
	//	str4[i] = StringUtils::format("%s", ls[2].c_str());  //命令
	//	str5[i] = StringUtils::format("%s", ls[3].c_str());  //命令
	//	str6[i] = StringUtils::format("%s", ls[4].c_str());  //命令
	//	i++;
	//}

	label = Label::createWithSystemFont("", "fonts/HGRPP1.TTC", 25);
	label->setWidth(650);
	label->setOpacity(255);
	label->setColor(Color3B::WHITE);
	//label->setHorizontalAlignment(TextHAlignment::LEFT);

	//座標を指定
	label->setPosition(525, 135);
	//作った文字列をLabelに設定

	return true;
}