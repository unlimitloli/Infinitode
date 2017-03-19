#include "MonsterPool.h"

USING_NS_CC;

MonsterPool::MonsterPool(int size)
{
	reset(size);
}

void MonsterPool::clearAll()
{
	m_free.clear();
	m_used.clear();
}

void MonsterPool::reset(int size)
{
	clearAll();
	for (int i = 0; i < size; ++i)
	{
		auto monster = Monster::createWithId();
		m_free.pushBack(monster);
	}
}

Monster * MonsterPool::createMonster(int monster_id)
{
	if (m_free.size() == 0)
	{
		extand();
	}
	auto monster = m_free.back();
	monster->reload(monster_id);

	m_used.pushBack(monster);
	m_free.popBack();
	return monster;
}

void MonsterPool::freeMonster(Monster * monster)
{
	monster->unload();

	if (!m_free.contains(monster))
	{
		m_free.pushBack(monster);
	}
	if (m_used.contains(monster))
	{
		m_used.eraseObject(monster);
	}

}

void MonsterPool::extand(int size)
{
	for (int i = 0; i < size; ++i)
	{
		auto monster = Monster::createWithId();
		m_free.pushBack(monster);
	}
}
