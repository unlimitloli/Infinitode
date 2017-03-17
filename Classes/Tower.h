#pragma once
#include "commons.h"

class Tower : public cocos2d::Node
{
public:
	static Tower * createWithId(int tower_id);
	bool initWithId(int tower_id);

protected:
	int m_tower_id = 0;

};