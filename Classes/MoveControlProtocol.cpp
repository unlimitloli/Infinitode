#include "MoveControlProtocol.h"

MoveControlProtocol::MoveControlProtocol(cocos2d::Node * node) :
	m_node(node)
{
}

void MoveControlProtocol::startWithPath(const std::vector<cocos2d::Vec2> &path, TRANSFORM_FUNC transform)
{
	CC_ASSERT(path.size() > 0);
	m_path = path;
	m_transform = transform;

	onStart();
}

void MoveControlProtocol::setSpeed(float speed)
{
	m_speed = speed;
}

MoveControlProtocol::~MoveControlProtocol()
{
}

void MoveControlProtocol::onStart()
{
	auto start_pos = m_path.at(0);
	if (m_transform != nullptr)
		start_pos = m_transform(start_pos);
	m_node->setPosition(start_pos.x, start_pos.y);
	transformDirection();
	m_node->setRotation(90 * m_direction);
}

void MoveControlProtocol::transformDirection()
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
		else if ((int)current_pos.y > (int)next_pos.y)
			m_direction = 2;
		else if ((int)current_pos.x > (int)next_pos.y)
			m_direction = 3;
	}
}

