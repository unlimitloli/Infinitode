#pragma once
#include "commons.h"
#include "Tower.h"

class MapCell : public cocos2d::Node
{
public:
	static MapCell * create(int type);
	bool init(int type);
	
	int getTowerId() const { return m_tower_id; }

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	void buildTower(int tower_id);
	void removeTower();

	void setSelected(bool select);
	void updateDraw();

protected:
	int m_type;
	cocos2d::Sprite *m_sprite = nullptr;
	cocos2d::Sprite *m_select_sprite = nullptr;

	int m_tower_id = 0;
	bool m_is_selected = false;
	Tower *m_tower = nullptr;
};