#include "Bullet.h"
#include "Monster.h"
#include "BulletManager.h"

USING_NS_CC;
using namespace std;

Bullet * Bullet::create(int bullet_id)
{
	auto bullet = new Bullet();
	if (bullet && bullet->init(bullet_id))
	{
		bullet->autorelease();
		return bullet;
	}
	else
	{
		CC_SAFE_DELETE(bullet);
		return nullptr;
	}
	return nullptr;
}

bool Bullet::init(int bullet_id)
{
	if (!Sprite::init())
		return false;

	setBulletId(bullet_id);

	return true;
}

void Bullet::setBulletId(int bullet_id)
{
	if (m_bullet_id == bullet_id)
		return;
	m_bullet_id = bullet_id;

	if (bullet_id > 0)
	{
		string pic_path = StringUtils::format("images/bullet/bullet_%d.png", bullet_id);
		setTexture(pic_path);
	}
}

void Bullet::setTarget(Monster * target)
{
	m_target = target;
	m_is_used = true;
}

bool Bullet::isUsed() const
{
	return m_is_used;
}

void Bullet::onHit()
{
	m_target = nullptr;
	m_is_used = false;
}

void Bullet::update(float dt)
{
	if (m_target == nullptr)
		return;

	float offset = dt * m_speed;

	auto current_pos = getPosition();
	auto end_pos = m_target->getPosition();

	float angle = atan2f(end_pos.y - current_pos.y, end_pos.x - current_pos.x);
	float offset_x = offset * cos(angle);
	float offset_y = offset * sin(angle);
	if (fabs(offset_x) < FLT_EPSILON)
		offset_x = 0.0f;
	if (fabs(offset_y) < FLT_EPSILON)
		offset_y = 0.0f;

	auto new_pos = Vec2(current_pos.x + offset_x, current_pos.y + offset_y);
	setPosition(new_pos);

	if (m_target->checkHit(new_pos))
	{
		m_target->beHited(this);
		onHit();
	}
}

float Bullet::getDamager() const
{
	return m_damage;
}
