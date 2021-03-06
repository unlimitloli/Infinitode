#pragma once
#include "commons.h"

class Monster;

class Bullet : public cocos2d::Sprite
{
public:
	static Bullet * create(int bullet_id = 0);
	bool init(int bullet_id);

	void setBulletId(int bullet_id = 0);
	void setTarget(Monster *target);
	bool isUsed() const;

	virtual void onHit();

	virtual void update(float dt) override;

	float getDamager() const;

protected:
	int m_bullet_id = 0;
	float m_speed = 100.0;
	float m_damage = 10.0f;
	bool m_is_used = false;

	Monster *m_target = nullptr;
};