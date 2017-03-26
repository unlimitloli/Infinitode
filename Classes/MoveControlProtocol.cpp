#include "MoveControlProtocol.h"

MoveControlProtocol::MoveControlProtocol(cocos2d::Node * node) :
	m_node(node)
{
}

void MoveControlProtocol::startWithPath(const std::vector<cocos2d::Vec2> &path, TRANSFORM_FUNC transform, END_FUNC end_call)
{
	CC_ASSERT(path.size() > 0);
	m_path = path;
	m_transform = transform;
	m_end_call = end_call;

	onStart();
}

void MoveControlProtocol::setSpeed(float speed)
{
	m_speed = speed;
}

void MoveControlProtocol::setEndCallback(std::function<void()> end_call)
{
	m_end_call = end_call;
}

MoveControlProtocol::~MoveControlProtocol()
{
}

void MoveControlProtocol::onEnd()
{
	if (m_end_call != nullptr)
		m_end_call();
}
