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
	
	auto node = CSLoader::createNode(csb_config.start_layer);
	addChild(node);
	m_root = node->getChildByName("root");

	return true;
}

