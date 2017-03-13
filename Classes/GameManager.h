#pragma once
#include "commons.h"

class GameManager : public cocos2d::Node
{
public:
	static GameManager * getInstance();

	void close();

protected:
	virtual bool init() override;
};