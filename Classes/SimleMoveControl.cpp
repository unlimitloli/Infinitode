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
			onEnd();
		}
		else
		{
			int current_dir = m_direction;
			transformDirection();
			if (current_dir != m_direction)
			{
				onTransDirection(0.2f);
			}
		}
		
	}
}

void SimpleMoveControl::onStart()
{
	MoveControlProtocol::onStart();

	auto start_pos = m_path.at(0);
	if (m_transform != nullptr)
		start_pos = m_transform(start_pos);
	m_node->setPosition(start_pos.x, start_pos.y);
	transformDirection();
	onTransDirection();
}

void SimpleMoveControl::transformDirection()
{
	if (m_pos + 1 < m_path.size())
	{
		auto current_pos = m_path.at(m_pos);
		auto next_pos = m_path.at(m_pos + 1);
		if (m_transform != nullptr)
		{
			current_pos = m_transform(current_pos);
			next_pos = m_transform(next_pos);
		}

		if ((int)current_pos.y < (int)next_pos.y)
			m_direction = 0;
		else if ((int)current_pos.x < (int)next_pos.x)
			m_direction = 1;
		else if ((int)current_pos.y >(int)next_pos.y)
			m_direction = 2;
		else if ((int)current_pos.x >(int)next_pos.y)
			m_direction = 3;
	}
}

void SimpleMoveControl::onTransDirection(float dt)
{
	if (dt > 0)
		m_node->runAction(RotateTo::create(dt, 90 * m_direction));
	else
		m_node->setRotation(90 * m_direction);
}


