#pragma once
#include "commons.h"

class StartLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(StartLayer);
	static cocos2d::Scene * createScene();
	virtual bool init() override;

protected:
	cocos2d::Node *m_root;
};