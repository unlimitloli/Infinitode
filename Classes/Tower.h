#pragma once
#include "commons.h"
#include "TowerDefine.h"

class Monster;

class Tower : public cocos2d::Node
{
public:
	static Tower * createWithId(int tower_id);
	bool initWithId(int tower_id);

	void setSelected(bool select);
	void updateDraw();
	void shoot();

	virtual void update(float dt) override;

protected:
	int m_tower_id = 0;
	bool m_is_selected = false;
	cocos2d::Sprite *m_tower_sprite = nullptr;

	float m_last_time = 0.0f;
	float m_timer = 0.0f;
	TowerState m_state = TowerState::Ready;

protected:
	virtual Monster * seachTarget(const cocos2d::Vector<Monster *> &monsters);
};