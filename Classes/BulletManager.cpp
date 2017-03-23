#include "BulletManager.h"

USING_NS_CC;
using namespace std;

bool BulletManager::init()
{
	if (!Node::init())
		return false;

	scheduleUpdate();

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
		bullet->setVisible(false);
		m_free.pushBack(bullet);
		m_used.eraseObject(bullet);
	}
}

void BulletManager::update(float dt)
{
	cocos2d::Vector<Bullet *> push_free;
	for (auto bullet : m_used)
	{
		bullet->update(dt);
		if (!bullet->isUsed())
			push_free.pushBack(bullet);
	}

	for (auto bullet : push_free)
	{
		freeBullet(bullet);
	}
	push_free.clear();
	
}
