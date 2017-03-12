#pragma once
#include "commons.h"

class MenuLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(MenuLayer);
	virtual bool init() override;

	void show();
	void hide();

protected:
	cocos2d::ui::Widget *m_root;
	cocostudio::timeline::ActionTimeline * m_actions;
};