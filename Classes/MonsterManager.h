#pragma once
#include "commons.h"
#include "MonsterPool.h"

class MonsterManager : public cocos2d::Node
{
public:
	CREATE_FUNC(MonsterManager);
	virtual bool init() override;
	void parseMap(const std::vector<int> maps, int width, int height);

	virtual void update(float dt) override;

	Monster *getMonster();

protected:
	MonsterPool m_pool;

	std::vector<int> m_maps;
	int m_width = 0;
	int m_height = 0;

	cocos2d::Vec2 m_start_pos;
	cocos2d::Vec2 m_end_pos;
	std::vector<cocos2d::Vec2> m_path;
	Monster *m_monster = nullptr;

	cocos2d::Vec2 transformPos(const cocos2d::Vec2 &pos);
protected:
	bool checkPos(int pos);
};