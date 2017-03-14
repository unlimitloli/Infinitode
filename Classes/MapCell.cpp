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

	_process->setProcess(sprite, Process::GRAY);
	m_sprite = sprite;

	setContentSize(sprite->getContentSize());
	setAnchorPoint(Vec2::ZERO);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(MapCell::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(MapCell::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite);

	return true;
}

void MapCell::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	_game->openMenu();
	_process->setProcess(m_sprite, Process::RECOVERY);
}

bool MapCell::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	auto pos = touch->getLocation();
	pos = getParent()->convertToNodeSpace(pos);

	if (getBoundingBox().containsPoint(pos))
		return true;
	return false;
}
