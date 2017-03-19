#include "MapCell.h"
#include "MenuLayer.h"

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
	auto size = sprite->getContentSize();
	setContentSize(size);
	sprite->setPosition(size.width / 2, size.height / 2);
	addChild(sprite);
	m_sprite = sprite;

	m_select_sprite = Sprite::create("images/icon/select.png");
	m_select_sprite->setPosition(size.width / 2, size.height / 2);
	addChild(m_select_sprite);
	m_select_sprite->setVisible(false);

	m_range_sprite = Sprite::create("images/icon/range.png");
	m_range_sprite->setPosition(size.width / 2, size.height / 2);
	addChild(m_range_sprite);
	m_range_sprite->setGlobalZOrder(100);
	m_range_sprite->setScale(100.0f / 64.0f, 100.0f / 64.0f);
	m_range_sprite->setVisible(false);

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
	if (m_type == 4)
		_game->getMenuLayer()->show(this);
	else
		_game->getMenuLayer()->hide();
}

void MapCell::buildTower(int tower_id)
{
	if (m_tower != nullptr)
		return;

	m_tower_id = tower_id;
	m_tower = Tower::createWithId(tower_id);
	m_tower->setPosition(getContentSize().width / 2, getContentSize().height / 2);
	addChild(m_tower);
}

void MapCell::removeTower()
{
	if (m_tower == nullptr)
		return;

	m_tower_id = 0;
	removeChild(m_tower, true);
	m_tower = nullptr;
}

void MapCell::setSelected(bool select)
{
	if (m_is_selected == select)
		return;
	m_is_selected = select;
	updateDraw();
}

void MapCell::updateDraw()
{
	m_select_sprite->setVisible(m_is_selected);
	m_range_sprite->setVisible(m_is_selected);
	if (m_tower != nullptr)
	{
		m_tower->setSelected(m_is_selected);
	}
}

bool MapCell::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	auto pos = touch->getLocation();
	pos = getParent()->convertToNodeSpace(pos);

	if (getBoundingBox().containsPoint(pos))
		return true;
	return false;
}
