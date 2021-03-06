#include "GameLayer.h"
#include "GameMap.h"
#include "MenuLayer.h"
#include "MonsterManager.h"

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

	auto startBtn = dynamic_cast<Button *>(Helper::seekWidgetByName(m_root, "Button_start"));
	startBtn->addTouchEventListener(CC_CALLBACK_2(GameLayer::onTouchStart, this));

	auto scroll_view = dynamic_cast<ScrollView *>(m_root->getChildByName("ScrollView_map"));
	scroll_view->removeAllChildrenWithCleanup(true);
	scroll_view->setScrollBarEnabled(false);
	m_game_map = GameMap::create();
	scroll_view->addChild(m_game_map);

	auto map_size = m_game_map->getContentSize();
	auto scroll_size = scroll_view->getContentSize();
	Size size;
	size.width = max(map_size.width, scroll_size.width);
	size.height = max(map_size.height, scroll_size.height);

	m_game_map->setPosition(scroll_size.width / 2, scroll_size.height / 2);
	scroll_view->setInnerContainerSize(size);

	return true;
}

GameMap * GameLayer::getGameMap()
{
	return m_game_map;
}

void GameLayer::onTouchStart(cocos2d::Ref * sender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == ui::Widget::TouchEventType::ENDED)
		_game->getMonsterManager()->createMonsters();
}
