#pragma once
#include "commons.h"
#include "TowerCell.h"

class MapCell;

class MenuLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MenuLayer);
	virtual bool init() override;

	void show(MapCell *cell= nullptr);
	void hide();

	void selectTower(int tower_id);

protected:
	cocos2d::ui::Widget *m_root;
	cocostudio::timeline::ActionTimeline * m_actions;

	bool m_is_show = false;
	int m_menu_type = 0;

	MapCell *m_map_cell = nullptr;
	cocos2d::Vector<TowerCell *> m_towers;

protected:
	void showMenu();
	void showNewMenu();
	void showSelectMenu();
	void showUpMenu();

	void updateTowerCell();
};