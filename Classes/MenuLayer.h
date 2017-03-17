#pragma once
#include "commons.h"

class MapCell;

class MenuLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MenuLayer);
	virtual bool init() override;

	void show(MapCell *cell= nullptr);
	void hide();

protected:
	cocos2d::ui::Widget *m_root;
	cocostudio::timeline::ActionTimeline * m_actions;

	bool m_is_show = false;
	int m_menu_type = 0;

	MapCell *m_map_cell = nullptr;

protected:
	void showMenu();
	void showNewMenu();
	void showSelectMenu();
	void showUpMenu();
};