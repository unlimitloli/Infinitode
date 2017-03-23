#pragma once
#include "commons.h"
#include "Bullet.h"

class BulletManager : public cocos2d::Node
{
public:
	CREATE_FUNC(BulletManager);
	virtual bool init() override;

	Bullet * createBullet(int bullet_id);
	void freeBullet(Bullet *bullet);

	virtual void update(float dt) override;

protected:
	cocos2d::Vector<Bullet *> m_free;
	cocos2d::Vector<Bullet *> m_used;
};