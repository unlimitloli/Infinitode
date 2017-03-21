#pragma once
#include "commons.h"
#include "MoveControlProtocol.h"

class Monster : public cocos2d::Node
{
public:
	static Monster * createWithId(int monster_id = 0);
	bool initWithId(int monster_id);
	void updateDraw();

	void reload(int monster_id);
	void unload();
	void clearUI();

	void runWithPath(const std::vector<cocos2d::Vec2> &path, MoveControlProtocol::TRANSFORM_FUNC tranform = nullptr);
	void moveToNext(float dt);

protected:
	int m_monster_id = 0;
	cocos2d::ui::Widget *m_root = nullptr;

	MoveControlProtocol *m_move_control = nullptr;

	bool m_is_run = false;
	std::vector<cocos2d::Vec2> m_path;
};