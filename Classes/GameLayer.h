#pragma once
#include "commons.h"

class MenuLayer;
class GameMap;

class GameLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init() override;

	GameMap * getGameMap();

protected:
	cocos2d::ui::Widget *m_root = nullptr;;

	MenuLayer *m_menu_layer = nullptr;
	GameMap *m_game_map = nullptr;
};