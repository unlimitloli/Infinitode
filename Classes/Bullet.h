#pragma once
#include "commons.h"

class Bullet : public cocos2d::Sprite
{
public:
	static Bullet * create(int bullet_id = 0);
	bool init(int bullet_id);

	void setBulletId(int bullet_id = 0);

protected:
	int m_bullet_id = 0;
};