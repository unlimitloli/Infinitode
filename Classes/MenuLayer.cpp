#include "MenuLayer.h"

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
	//m_root->setSwallowTouches(false);

	//auto panel = Helper::seekWidgetByName(m_root, "Panel_menu");
	//panel->setSwallowTouches(true);

	m_actions = CSLoader::createTimeline(csb_config.menu_layer);
	runAction(m_actions);

	auto back = Helper::seekWidgetByName(m_root, "Button_back");

	_win->addTouch(back, [&](cocos2d::Ref *sender, int param) {
		hide();
	});

	return true;
}

void MenuLayer::show()
{
	if (m_is_show == false)
	{
		m_is_show = true;
		m_actions->play("show", false);
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
