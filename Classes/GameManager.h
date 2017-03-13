#pragma once
#include "commons.h"

class GameLayer;
class MenuLayer;

#define _game		GameManager::getInstance()

class GameManager : public cocos2d::Node
{
public:
	static GameManager * getInstance();

	void start();
	void end();

	void setGameLayer(GameLayer *layer);
	void setMenuLayer(MenuLayer *layer);

	GameLayer *getGameLayer();
	MenuLayer *getMenuLayer();

	void openMenu();

protected:
	virtual bool init() override;

protected:
	GameLayer * m_game_layer = nullptr;
	MenuLayer * m_menu_layer = nullptr;
};