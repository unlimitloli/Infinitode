#pragma once
#include "commons.h"

class Monster : public cocos2d::Node
{
public:
	static Monster * createWithId(int monster_id = 0);
	bool initWithId(int monster_id);
	void updateDraw();

	void reload(int monster_id);
	void unload();
	void clearUI();

protected:
	int m_monster_id = 0;
	cocos2d::ui::Widget *m_root = nullptr;
};