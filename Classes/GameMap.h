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

	std::vector<MapCell *> m_map_cells;
	std::vector<int> m_maps;
};