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

MoveControlProtocol::~MoveControlProtocol()
{
}

