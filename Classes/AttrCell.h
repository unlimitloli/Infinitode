#pragma once
#include "commons.h"
#include "TowerAttibute.h"

class AttrCell : public cocos2d::ui::Widget
{
public:
	static AttrCell * create(TowerAttribute attr);
	bool init(TowerAttribute attr);

	void updateDraw();

protected:
	TowerAttribute m_attr;
	cocos2d::ui::Widget *m_root;
};