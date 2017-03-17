#pragma once
#include "commons.h"

class TowerCell : public cocos2d::Node
{
public:
	static TowerCell * createWithId(int tower_id);
	bool initWithId(int tower_id);

	void updateDraw();

protected:
	int m_tower_id = 0;
	bool m_is_lock = false;

	cocos2d::ui::Widget *m_root;
};