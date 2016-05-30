#pragma execution_character_set("utf-8")//���{�ꂪ�g����悤�ɂȂ閂�@�̌��t
#include "ouse/NovelScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* NovelScene::createScene()
{
	// scene ���������I�u�W�F�N�g
	auto scene = Scene::create();
	// layer ���������I�u�W�F�N�g
	auto layer = NovelScene::create();
	// layer scene�̎q�Ƃ��Ēǉ�
	scene->addChild(layer);
	// scene �̒l��Ԃ�
	return scene;
}

// ���������\�b�h
bool NovelScene::init()
{
	// �e�ł���Layer�N���X�̏�����
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

	//��ʃT�C�Y�擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//�}���`���]�����[�V����
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto textField = ui::TextField::create("���S", "", 45);
	textField->setPosition(Vec2(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.7 + origin.y));

	this->addChild(textField);

	//�摜��\��
	auto sprite = Sprite::create("window2.png");
	////�����ɕ\�������悤�ɍ��W��ݒ�
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	sprite->setScale(0.75);
	////�摜��ǉ��@��2�����͕\�����鏇�ԁi�w�i�������ԉ��܂�0�j
	this->addChild(sprite, 3);

	// txt�t�@�C������ǂݍ���
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

	//	str[i] = StringUtils::format("%s", ls[5].c_str());  //�{��
	//	str2[i] = StringUtils::format("%s", ls[0].c_str());  //����
	//	str3[i] = StringUtils::format("%s", ls[1].c_str());  //����
	//	str4[i] = StringUtils::format("%s", ls[2].c_str());  //����
	//	str5[i] = StringUtils::format("%s", ls[3].c_str());  //����
	//	str6[i] = StringUtils::format("%s", ls[4].c_str());  //����
	//	i++;
	//}

	label = Label::createWithSystemFont("", "fonts/HGRPP1.TTC", 25);
	label->setWidth(650);
	label->setOpacity(255);
	label->setColor(Color3B::WHITE);
	//label->setHorizontalAlignment(TextHAlignment::LEFT);

	//���W���w��
	label->setPosition(525, 135);
	//������������Label�ɐݒ�

	return true;
}