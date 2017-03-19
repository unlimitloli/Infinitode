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
	int pic = _config_int("tower_config", m_tower_id, tower_config::pic);
	m_tower_sprite = Sprite::create(StringUtils::format("images/tower/tower_%d.png", pic));
	auto size = m_tower_sprite->getContentSize();
	setAnchorPoint(Vec2(0.5f, 0.5f));
	setContentSize(m_tower_sprite->getContentSize());
	m_tower_sprite->setPosition(size.width / 2, size.height / 2);
	addChild(m_tower_sprite);

	return true;
}

void Tower::setSelected(bool select)
{
	if (m_is_selected == select)
		return;
	m_is_selected = select;
}

void Tower::updateDraw()
{

}
