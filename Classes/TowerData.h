#pragma once
#include "commons.h"
#include "TowerDefine.h"
#include <map>

class TowerData
{
public:

protected:
	// ͨ������
	CC_SYNTHESIZE(int, m_tower_id, TowerId);			// id
	CC_SYNTHESIZE(int, m_level, Level);					// level
	CC_SYNTHESIZE(int, m_exp, Experice);				//
	CC_SYNTHESIZE(double, m_range, Range);				// range
	CC_SYNTHESIZE(int, m_priority, Priority);

	CC_SYNTHESIZE(int, m_atk_type, AtkType);			// ��������

	// �ɳ�����

	// ��������
};