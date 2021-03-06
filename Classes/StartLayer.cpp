#include "StartLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene * StartLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = StartLayer::create();
	scene->addChild(layer);
	return scene;
}

bool StartLayer::init()
{
	if (!Layer::init())
		return false;
	
	auto csb_node = CSLoader::createNode(csb_config.start_layer);
	addChild(csb_node);
	m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));

	auto start = Helper::seekWidgetByName(m_root, "Panel_Menu_Start");
	auto new_game = Helper::seekWidgetByName(m_root, "Panel_Menu_New");

	_win->addTouch(start, CC_CALLBACK_2(StartLayer::onTouchNewGame, this), 1);
	_win->addTouch(new_game, CC_CALLBACK_2(StartLayer::onTouchNewGame, this), 2);

	return true;
}

void StartLayer::onTouchNewGame(cocos2d::Ref * sender, int param)
{
	switch (param)
	{
	case 1:
		break;
	case 2:
		_win->close(this);
		_win->open(LayerType::GameLayer);
		break;
	default:
		break;
	}
}

