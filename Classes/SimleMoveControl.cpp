#include "SimpleMoveControl.h"

USING_NS_CC;

void SimpleMoveControl::move(float dt)
{
	if (m_is_end)
		return;

	float offset = dt * m_speed;
	auto current_pos = m_node->getPosition();
	Vec2 end_pos = m_path.at(m_pos + 1);
	if (m_transform != nullptr)
		end_pos = m_transform(end_pos);

	Vec2 new_pos = current_pos;
	bool is_end = false;
	switch (m_direction)
	{
	case 0:
		new_pos.y += offset;
		if (new_pos.y > end_pos.y)
		{
			new_pos.y = end_pos.y;
			is_end = true;
		}
		break;
	case 1:
		new_pos.x += offset;
		if (new_pos.x > end_pos.x)
		{
			new_pos.x = end_pos.x;
			is_end = true;
		}
		break;
	case 2:
		new_pos.y -= offset;
		if (new_pos.y < end_pos.y)
		{
			new_pos.y = end_pos.y;
			is_end = true;
		}
		break;
	case 3:
		new_pos.x -= offset;
		if (new_pos.x < end_pos.x)
		{
			new_pos.x = end_pos.x;
			is_end = true;
		}
		break;
	default:
		break;
	}

	m_node->setPosition(new_pos);
	if (is_end)
	{
		++m_pos;
		if (m_pos + 1 == m_path.size())
		{
			
			m_is_end = true;
		}
		else
		{
			int current_dir = m_direction;
			transformDirection();
			if (current_dir != m_direction)
			{
				m_node->runAction(RotateTo::create(0.2f, 90 * m_direction));
			}
		}
		
	}
}

