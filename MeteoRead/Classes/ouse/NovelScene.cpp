#include "NovelScene.h"
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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�摜��\��
	auto sprite = Sprite::create("HelloWorld.png");

	//�\���ʒu
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//���C���[�ɒǉ�
	this->addChild(sprite, 0);

	return true;
}