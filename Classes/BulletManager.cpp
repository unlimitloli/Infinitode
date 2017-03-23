#include "BulletManager.h"

USING_NS_CC;
using namespace std;

bool BulletManager::init()
{
	if (!Node::init())
		return false;

	return true;
}

Bullet * BulletManager::createBullet(int bullet_id)
{
	if (m_free.size() == 0)
	{
		auto bullet = Bullet::create(bullet_id);
		addChild(bullet);
		bullet->setVisible(false);
		m_free.pushBack(bullet);
	}
	auto bullet = m_free.back();
	bullet->setBulletId(bullet_id);
	bullet->setVisible(true);
	m_used.pushBack(bullet);
	m_free.popBack();
	return bullet;
}

void BulletManager::freeBullet(Bullet * bullet)
{
	if (m_used.contains(bullet))
	{
		//bullet->setVisible(false);
		m_free.pushBack(bullet);
		m_used.eraseObject(bullet);
	}
}
