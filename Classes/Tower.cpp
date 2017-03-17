#include "Tower.h"

USING_NS_CC;

Tower * Tower::createWithId(int tower_id)
{
	auto tower = new Tower();
	if (tower && tower->initWithId(tower_id))
	{
		tower->autorelease();
		return tower;
	}
	else
	{
		CC_SAFE_DELETE(tower);
		return nullptr;
	}
	return nullptr;
}

bool Tower::initWithId(int tower_id)
{
	if (!Node::init())
		return false;

	m_tower_id = tower_id;
	auto sprite = Sprite::create(StringUtils::format("images/tower/tower_%d.png", tower_id));
	addChild(sprite);
	setContentSize(sprite->getContentSize());
	setAnchorPoint(Vec2(0.5f, 0.5f));

	return true;
}
