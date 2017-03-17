#pragma once
#include "commons.h"

class MapCell : public cocos2d::Node
{
public:
	static MapCell * create(int type);
	bool init(int type);
	
	int getState() const { return m_state; }

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

protected:
	int m_type;
	int m_state = 0;			// 0���޷��������ɽ��죬1�����з�����
	cocos2d::Sprite *m_sprite;
};