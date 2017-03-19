#pragma once
#include "commons.h"

class TowerCell : public cocos2d::Node
{
public:
	static TowerCell * createWithId(int tower_id);
	bool initWithId(int tower_id);

	void updateDraw();
	void setSelected(bool flag);
	int getTowerId() const { return m_tower_id; }

	void setLocked(bool lock);

protected:
	int m_tower_id = 0;
	bool m_is_lock = false;

	cocos2d::ui::Widget *m_root;
};