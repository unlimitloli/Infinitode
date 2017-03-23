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

	virtual void onHit();

	virtual void update(float dt) override;

protected:
	int m_bullet_id = 0;
	float m_speed = 30.0f;

	Monster *m_target = nullptr;
};