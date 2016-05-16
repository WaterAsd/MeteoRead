#include "ouse/NovelScene.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"

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

	mojicnt = false;
	mojiframe = false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�摜��\��
	auto sprite = Sprite::create("HelloWorld.png");
	background = Sprite::create("window2.png");
	////�����ɕ\�������悤�ɍ��W��ݒ�
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	background->setScale(0.75);
	////�摜��ǉ��@��2�����͕\�����鏇�ԁi�w�i�������ԉ��܂�0�j
	this->addChild(background, 3);

	//�\���ʒu
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//���C���[�ɒǉ�
	this->addChild(sprite, 0);

	return true;
}