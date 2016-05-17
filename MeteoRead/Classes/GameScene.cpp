#include "GameScene.h"
#include "asada/Rocket.h"

USING_NS_CC;

//UiLayer
UILayer *GameScene::uiLayer;
Earth *GameScene::earth;

//Scene���g����悤�ɂ���
Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init(){
	//init�����݂��Ȃ��ꍇ�͏���
	if (!Layer::init()){
		return false;
	}

	//��ʃT�C�Y���l������
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�w�i�摜�̍쐬
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(Space);


	//�����o��������
	StarSet(visibleSize/2);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
	StarSet(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));

	//���P�b�g���o��������
	auto rocket = Rocket::create();
	rocket->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(rocket);
	_rocket = rocket;

	//���P�b�g�̃T�C�Y�𒲂ׂ�ׂ�Node�ɉ摜�𒣂�
	auto lc = LayerColor::create(Color4B(255, 0, 0, 255),rocket->getContentSize().width,rocket->getContentSize().height);
	lc->setPosition(Vec2(rocket->getContentSize().width / 2, rocket->getContentSize().height / 2));
	rocket->addChild(lc);

	//UiLayer��錾����B
	uiLayer = UILayer::create();
	this->addChild(uiLayer);

	//�}�C�t���[���X�V��Ƃ����s������
	this->scheduleUpdate();

	return true;
}

//�}�C�t���[���X�V�֐�
void GameScene::update(float delta){
	//float angle = ccpToAngle(ccpSub(_rocket->getPosition(),_))

	_rocket->setRocketPos(Vec2(_rocket->getPosition().x,_rocket->getPosition().y));
	//_rocket->setRocketRect(Rect(_rocket->getContentSize()));

}

//�����o��������
void GameScene::StarSet(Vec2 Pos){
	auto earth = Earth::create();
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//���̐����₷�B
	stars.pushBack(earth);//���̏���ۑ�����B
}