#include "GameMap.h"
#include "MapCell.h"

USING_NS_CC;

const int cell_width = 32;
const int cell_height = 32;

GameMap * GameMap::create()
{
	auto layer = new GameMap();
	if (layer && layer->init())
	{
		layer->autorelease();
		return layer;
	}
	else
	{
		CC_SAFE_DELETE(layer);
		return nullptr;
	}
}

bool GameMap::init()
{
	if (!Node::init())
		return false;

	m_width = 10;
	m_height = 7;

	ParseData data = ParseData("config/map/map_1.txt");

	for (int i = 0; i < m_width; ++i)
	{
		for (int j = 0; j < m_height; ++j)
		{
			auto cell = MapCell::create(1);
			cell->setPosition(i * cell_width, j * cell_height);
			addChild(cell);
		}
	}

	setAnchorPoint(Vec2(0.5f, 0.5f));
	setContentSize(Size(m_width * cell_width, m_height * cell_height));

	return true;
}
