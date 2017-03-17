#include "MenuLayer.h"
#include "MapCell.h"

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
}

void MenuLayer::showSelectMenu()
{
	m_menu_type = 1;
}

void MenuLayer::showUpMenu()
{
	m_menu_type = 2;
}
