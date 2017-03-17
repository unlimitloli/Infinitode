#include "MenuLayer.h"
#include "MapCell.h"
#include "TowerCell.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

bool MenuLayer::init()
{
	if (!Layer::init())
		return false;

	_game->setMenuLayer(this);

	auto csb_node = CSLoader::createNode(csb_config.menu_layer);
	addChild(csb_node);
	m_root = dynamic_cast<Widget *>(csb_node->getChildByName("root"));

	m_actions = CSLoader::createTimeline(csb_config.menu_layer);
	runAction(m_actions);

	updateTowerCell();

	auto back = Helper::seekWidgetByName(m_root, "Button_back");

	_win->addTouch(back, [&](cocos2d::Ref *sender, int param) {
		hide();
	});

	return true;
}

void MenuLayer::show(MapCell *cell)
{
	if (m_is_show == false)
	{
		m_is_show = true;
		m_actions->play("show", false);
	}
	if (cell != m_map_cell)
	{
		m_map_cell = cell;
		showMenu();
	}
}

void MenuLayer::hide()
{
	if (m_is_show == true)
	{
		m_is_show = false;
		m_actions->play("hide", false);
	}
}

void MenuLayer::selectTower(int tower_id)
{
	for (auto tower : m_towers)
	{
		if (tower->getTowerId() == tower_id)
			tower->setSelected(true);
		else
			tower->setSelected(false);
	}
}

void MenuLayer::showMenu()
{
	if ((m_map_cell == nullptr) || (m_map_cell->getState() == 0))
	{
		showNewMenu();
	}
	else
	{
		showUpMenu();
	}
}

void MenuLayer::showNewMenu()
{
	m_menu_type = 0;
	auto Panel_new = Helper::seekWidgetByName(m_root, "Panel_new");
	auto Panel_select = Helper::seekWidgetByName(m_root, "Panel_select");
	auto Panel_up = Helper::seekWidgetByName(m_root, "Panel_up");
	auto Panel_tower = Helper::seekWidgetByName(m_root, "Panel_tower");

	Panel_new->setVisible(true);
	Panel_select->setVisible(false);
	Panel_up->setVisible(false);
	Panel_tower->setVisible(true);
}

void MenuLayer::showSelectMenu()
{
	m_menu_type = 1;
	auto Panel_new = Helper::seekWidgetByName(m_root, "Panel_new");
	auto Panel_select = Helper::seekWidgetByName(m_root, "Panel_select");
	auto Panel_up = Helper::seekWidgetByName(m_root, "Panel_up");
	auto Panel_tower = Helper::seekWidgetByName(m_root, "Panel_tower");

	Panel_new->setVisible(false);
	Panel_select->setVisible(true);
	Panel_up->setVisible(false);
	Panel_tower->setVisible(true);
}

void MenuLayer::showUpMenu()
{
	m_menu_type = 2;
	auto Panel_new = Helper::seekWidgetByName(m_root, "Panel_new");
	auto Panel_select = Helper::seekWidgetByName(m_root, "Panel_select");
	auto Panel_up = Helper::seekWidgetByName(m_root, "Panel_up");
	auto Panel_tower = Helper::seekWidgetByName(m_root, "Panel_tower");

	Panel_new->setVisible(false);
	Panel_select->setVisible(false);
	Panel_up->setVisible(true);
	Panel_tower->setVisible(false);
}

void MenuLayer::updateTowerCell()
{
	auto Panel_tower = dynamic_cast<Layout *>(Helper::seekWidgetByName(m_root, "Panel_tower"));
	Panel_tower->removeAllChildren();
	auto size = Panel_tower->getContentSize();
	for (int i = 0; i < 12; ++i)
	{
		auto cell = TowerCell::createWithId(i + 1);
		int row = 3- i / 4;
		int col = i % 4;
		cell->setPosition(col * size.width / 4, row * size.height / 3);
		Panel_tower->addChild(cell);
		m_towers.pushBack(cell);
	}
}
