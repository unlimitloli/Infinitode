#include "MonsterManager.h"
#include <queue>

USING_NS_CC;
using namespace std;

bool MonsterManager::init()
{
	if (!Node::init())
		return false;

	m_pool.reset(20);

	auto monster = m_pool.createMonster(1);
	addChild(monster);

	return true;
}

void MonsterManager::parseMap(const std::vector<int> maps, int width, int height)
{
	m_maps = maps;
	m_width = width;
	m_height = height;

	// 寻找起始点和结束点
	int start_pos = 0;
	int end_pos = 0;
	for (size_t i = 0; i < maps.size(); ++i)
	{
		int row = i / width;
		int col = i % width;
		if (maps[i] == 1)
		{
			m_start_pos = Vec2(col, row);
			start_pos = i;
		}
		else if (maps[i] == 2)
		{
			m_end_pos = Vec2(col, row);
			end_pos = i;
		}
	}

	// 寻找最短路径,广度优先算法
	vector<int> edge_to(width * height, -1);
	queue<int> next_pos;
	vector<bool> pass_pos(width * height, false);
	next_pos.push(start_pos);

	while (!next_pos.empty())
	{
		int pos = next_pos.front();
		next_pos.pop();

		if (checkPos(pos + 1) && !pass_pos[pos + 1])
		{
			edge_to[pos + 1] = pos;
			pass_pos[pos + 1] = true;
			next_pos.push(pos + 1);
		}
		if (checkPos(pos - 1) && !pass_pos[pos - 1])
		{
			edge_to[pos - 1] = pos;
			pass_pos[pos - 1] = true;
			next_pos.push(pos - 1);
		}
		if (checkPos(pos + width) && !pass_pos[pos + width])
		{
			edge_to[pos + width] = pos;
			pass_pos[pos + width] = true;
			next_pos.push(pos + width);
		}
		if (checkPos(pos - width) && !pass_pos[pos - width])
		{
			edge_to[pos - width] = pos;
			pass_pos[pos - width] = true;
			next_pos.push(pos - width);
		}
	}
	
	vector<int> path;
	for (int pos = end_pos; pos != start_pos; pos = edge_to[pos])
	{
		path.push_back(pos);
	}
	path.push_back(start_pos);
	for_each(path.rbegin(), path.rend(), [&](int pos) {
		m_path.push_back(Vec2(pos / m_width, pos % m_width));
	});
}

bool MonsterManager::checkPos(int pos)
{
	int row = pos / m_width;
	int col = pos % m_width;
	if ((row < 0) || (row >= m_height) || (col < 0) || (col >= m_width))
		return false;
	if ((m_maps[pos] == 3) || (m_maps[pos] == 2))
		return true;
	return false;
}
