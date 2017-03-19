#include "GameMap.h"
#include "MapCell.h"
#include "Monster.h"

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

	ParseData data = ParseData("config/map/map_1.txt");
	m_width = data.getInt(0, 0);
	m_height = data.getInt(0, 1);

	for (int row = 0; row < m_height; ++row)
	{
		for (int col = 0; col < m_width; ++col)
		{
			int type = data.getInt(row + 1, col);
			if (type > 0)
			{
				auto cell = MapCell::create(type);
				cell->setPosition(col * cell_width, (m_height - 1- row) * cell_height);
				addChild(cell);
			}
		}
	}

	setAnchorPoint(Vec2(0.5f, 0.5f));
	setContentSize(Size(m_width * cell_width, m_height * cell_height));

	Monster *monster = Monster::createWithId(1);
	addChild(monster);

	return true;
}
