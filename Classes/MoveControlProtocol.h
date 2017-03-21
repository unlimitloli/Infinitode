#pragma once
#include "cocos2d.h"

// 移动控制器接口
class MoveControlProtocol
{
public:
	using TRANSFORM_FUNC = std::function<cocos2d::Vec2(const cocos2d::Vec2 &)>;
	MoveControlProtocol(cocos2d::Node *node);
	virtual void startWithPath(const std::vector<cocos2d::Vec2> &path, TRANSFORM_FUNC transform = nullptr);

	virtual void move(float dt) = 0;

	virtual ~MoveControlProtocol();

protected:
	cocos2d::Node *m_node = nullptr;
	std::vector<cocos2d::Vec2> m_path;

	int m_direction = 0;		//  运动方向，0：向上，1：向右，2：向下，3：向左
	int m_pos = 0;

	TRANSFORM_FUNC m_transform = nullptr;

protected:
	virtual void onStart() {};
};