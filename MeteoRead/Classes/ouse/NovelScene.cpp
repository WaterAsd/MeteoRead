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

	return true;
}