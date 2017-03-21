#include "SimpleMoveControl.h"

USING_NS_CC;

void SimpleMoveControl::move(float dt)
{
}

void SimpleMoveControl::onStart()
{
	auto start_pos = m_path.at(0);
	if (m_transform != nullptr)
		start_pos = m_transform(start_pos);
	m_node->setPosition(start_pos.x, start_pos.y);
}
