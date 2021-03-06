#pragma once
#include "Monster.h"

class MonsterPool
{
public:
	MonsterPool(int size = 0);
	void clearAll();
	void reset(int size);

	Monster * createMonster(int monster_id);
	void freeMonster(Monster *monster);

	cocos2d::Vector<Monster *>& getFreeMonster();
	cocos2d::Vector<Monster *>& getUsedMonster();

protected:
	cocos2d::Vector<Monster *> m_free;
	cocos2d::Vector<Monster *> m_used;

	void extand(int size = 10);
};