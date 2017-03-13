#pragma once
#include "commons.h"

class MenuLayer;

class GameLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init() override;

protected:
	cocos2d::ui::Widget *m_root = nullptr;;

	MenuLayer *m_menu_layer = nullptr;
};