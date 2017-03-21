#include "GameMap.h"
#include "MapCell.h"
#include "MonsterManager.h"

USING_NS_CC;

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

	m_map_cells.resize(m_width * m_height, nullptr);
	m_maps.resize(m_width * m_height, 0);

	for (int row = 0; row < m_height; ++row)
	{
		for (int col = 0; col < m_width; ++col)
		{
			int type = data.getInt(row + 1, col);
			if (type > 0)
			{
				auto cell = MapCell::create(type);
				cell->setPosition(col * CELL_WIDTH, (m_height - 1- row) * CELL_HEIGHT);
				addChild(cell);

				m_map_cells[row * m_width + col] = cell;
			}
			m_maps[row * m_width + col] = type;
		}
	}

	setAnchorPoint(Vec2(0.5f, 0.5f));
	setContentSize(Size(m_width * CELL_WIDTH, m_height * CELL_HEIGHT));

	MonsterManager *monster = MonsterManager::create();
	addChild(monster);

	monster->parseMap(m_maps, m_width, m_height);

	return true;
}
