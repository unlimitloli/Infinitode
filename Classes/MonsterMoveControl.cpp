#include "MonsterMoveControl.h"
#include "Monster.h"

void MonsterMoveControl::onTransDirection(float dt)
{
	auto monster = dynamic_cast<Monster *>(m_node);
	monster->rotateToAngle(90 * m_direction, dt);
}
