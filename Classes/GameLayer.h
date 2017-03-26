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

	void onTouchStart(cocos2d::Ref *sender, cocos2d::ui::Widget::TouchEventType type);

protected:
	cocos2d::ui::Widget *m_root = nullptr;;

	MenuLayer *m_menu_layer = nullptr;
	GameMap *m_game_map = nullptr;
};