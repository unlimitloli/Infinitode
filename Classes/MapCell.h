#pragma once
#include "commons.h"

class MapCell : public cocos2d::Node
{
public:
	static MapCell * create(int type);
	bool init(int type);

protected:
	int m_type;
};