#pragma once
#include "commons.h"

class Bullet : public cocos2d::Sprite
{
public:
	static Bullet * create(int bullet_id = 0);
	bool init(int bullet_id);

	void setBulletId(int bullet_id = 0);
	void setTarget(cocos2d::Node *target);

	virtual void update(float dt) override;

protected:
	int m_bullet_id = 0;
	float m_speed = 30.0f;

	cocos2d::Node *m_target = nullptr;
};