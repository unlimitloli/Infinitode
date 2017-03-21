#include "Bullet.h"

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
		string pic_path = StringUtils::format("images/bullet/bullet_%d.png");
		setTexture(pic_path);
	}
}
