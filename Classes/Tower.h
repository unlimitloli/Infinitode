#pragma once
#include "commons.h"

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
};