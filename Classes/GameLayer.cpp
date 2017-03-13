#include "GameLayer.h"
#include "GameMap.h"
#include "MenuLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace std;

bool GameLayer::init()
{
	if (!Layer::init())
		return false;

	_game->start();
	_game->setGameLayer(this);

	_win->open(LayerType::MenuLayer, OrderType::menu);

	auto csb_node = CSLoader::createNode(csb_config.game_layer);
	addChild(csb_node);
	m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));

	auto scroll_view = dynamic_cast<ScrollView *>(m_root->getChildByName("ScrollView_map"));
	scroll_view->removeAllChildrenWithCleanup(true);
	scroll_view->setScrollBarEnabled(false);
	auto game_map = GameMap::create();
	scroll_view->addChild(game_map);

	auto map_size = game_map->getContentSize();
	auto scroll_size = scroll_view->getContentSize();
	Size size;
	size.width = max(map_size.width, scroll_size.width);
	size.height = max(map_size.height, scroll_size.height);

	game_map->setPosition(scroll_size.width / 2, scroll_size.height / 2);
	scroll_view->setInnerContainerSize(size);

	return true;
}