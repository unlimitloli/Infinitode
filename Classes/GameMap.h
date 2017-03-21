#pragma once
#include "commons.h"

class MapCell;
class MonsterManager;
class BulletManager;

class GameMap : public cocos2d::Node
{
public:
	static GameMap *create();
	bool init();

	MonsterManager *getMonsterManager();
	BulletManager *getBulletManager();

protected:
	int m_width;
	int m_height;

	std::vector<MapCell *> m_map_cells;
	std::vector<int> m_maps;

	MonsterManager *m_monster_manager = nullptr;
	BulletManager *m_bullet_manager = nullptr;
};