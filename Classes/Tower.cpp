#include "Tower.h"
#include "MonsterManager.h"
#include "BulletManager.h"
#include "MapCell.h"

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

	m_last_time = time(nullptr);
	scheduleUpdate();

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

void Tower::shoot()
{
	auto monsters = _game->getMonsterManager()->getMonsters();
	auto monster = seachTarget(monsters);
	if (monster != nullptr)
	{
		auto bullet = _game->getBulletManager()->createBullet(1);
		bullet->setTarget(monster);

		Vec2 pos = getPosition() + getParent()->getPosition();
		bullet->setPosition(pos);

		m_state = TowerState::CoolDown;
	}
}

void Tower::update(float dt)
{
	float cd_time = 2.0f;

	m_timer += dt;
	switch (m_state)
	{
	case TowerState::Ready:
		m_last_time = m_timer;
		shoot();
		break;
	case TowerState::CoolDown:
		if (m_timer - m_last_time >= cd_time)
		{
			m_state = TowerState::Ready;
		}
		break;
	default:
		break;
	}
}

Monster * Tower::seachTarget(const cocos2d::Vector<Monster*>& monsters)
{
	float range = 3;

	range = CELL_WIDTH * range;
	Vec2 pos = getPosition() + getParent()->getPosition();
	for (auto monster : monsters)
	{
		auto monster_pos = monster->getPosition();
		float dis = pos.distance(monster_pos);
		if (dis <= range)
			return monster;
	}
	return nullptr;
}
