#pragma once
#include "commons.h"

class MapCell : public cocos2d::Node
{
public:
	static MapCell * create(int type);
	bool init(int type);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

protected:
	int m_type;
};