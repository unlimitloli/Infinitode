#include "GameLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

bool GameLayer::init()
{
	if (!Layer::init())
		return false;

	auto csb_node = CSLoader::createNode(csb_config.game_layer);
	addChild(csb_node);
	m_root = csb_node->getChildByName("root");

	auto scroll_view = dynamic_cast<ScrollView *>(m_root->getChildByName("ScrollView_map"));
	auto sprite = Sprite::create("01.png");
	sprite->setAnchorPoint(Vec2::ZERO);
	sprite->setPosition(Vec2::ZERO);
	scroll_view->addChild(sprite);
	scroll_view->setInnerContainerSize(sprite->getContentSize());

	return true;
}