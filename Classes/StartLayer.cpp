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
	m_root = csb_node->getChildByName("root");

	return true;
}

