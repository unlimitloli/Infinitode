#pragma once
#include "commons.h"

class StartLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(StartLayer);
	static cocos2d::Scene * createScene();
	virtual bool init() override;

	void onTouchNewGame(cocos2d::Ref *sender, int param);

protected:
	cocos2d::ui::Widget *m_root;
};