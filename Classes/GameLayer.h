#pragma once
#include "commons.h"

class GameLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init() override;

protected:
	cocos2d::Node *m_root;
};