#include "MapCell.h"

USING_NS_CC;

MapCell * MapCell::create(int type)
{
	auto cell = new MapCell();
	if (cell && cell->init(type))
	{
		cell->autorelease();
		return cell;
	}
	else
	{
		CC_SAFE_DELETE(cell);
		return nullptr;
	}
}

bool MapCell::init(int type)
{
	if (!Node::init())
		return false;

	m_type = type;

	auto sprite = Sprite::create(StringUtils::format("images/map/map_%d.png", m_type));
	sprite->setAnchorPoint(Vec2::ZERO);
	sprite->setPosition(Vec2::ZERO);
	addChild(sprite);

	setContentSize(sprite->getContentSize());
	setAnchorPoint(Vec2::ZERO);

	return true;
}
