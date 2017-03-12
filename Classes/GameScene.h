#pragma once
#include "commons.h"

class GameLayer;

class GameScene : public cocos2d::Scene
{
public:
	CREATE_FUNC(GameScene);
	virtual bool init() override;

protected:
	GameLayer *m_game_layer;
};