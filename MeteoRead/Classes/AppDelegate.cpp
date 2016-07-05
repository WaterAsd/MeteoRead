#include "AppDelegate.h"
#include "GameScene.h"
#include "isiwaki\SelectScene.h"
#include "oohasi\Title.h"
#include "oohasi\TitleScene.h"


USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size OKsize = cocos2d::Size(960, 540);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate(){

}

AppDelegate::~AppDelegate(){
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching() {
    
	auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("MeteoRead", Rect(0, 0, OKsize.width, OKsize.height));
#else
        glview = GLViewImpl::create("MeteoRead");
#endif
        director->setOpenGLView(glview);
    }

    //director->setDisplayStats(true);

    //director->setAnimationInterval(1.0 / 60);

    //glview->setDesignResolutionSize(OKsize.width, OKsize.height, ResolutionPolicy::NO_BORDER);
    //
    //register_all_packages();

	//ˆê”ÔÅ‰‚Éo‚·ƒV[ƒ“
    auto scene = SelectScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

}