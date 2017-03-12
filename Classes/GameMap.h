#pragma once
#include "commons.h"

class MapCell;

class GameMap : public cocos2d::Node
{
public:
	static GameMap *create();
	bool init();

protected:
	int m_width;
	int m_height;

	cocos2d::Vector<MapCell *> m_cells;
};