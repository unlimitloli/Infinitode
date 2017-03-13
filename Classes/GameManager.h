#pragma once
#include "commons.h"

#define _game		GameManager::getInstance()

class GameManager : public cocos2d::Node
{
public:
	static GameManager * getInstance();

	void start();
	void end();

protected:
	virtual bool init() override;
};