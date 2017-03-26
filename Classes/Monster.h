#pragma once
#include "commons.h"
#include "MoveControlProtocol.h"

class Bullet;

class Monster : public cocos2d::Node
{
public:
	static Monster * createWithId(int monster_id = 0);
	bool initWithId(int monster_id);
	void updateDraw();
	void updateHp();

	void reload(int monster_id);
	void unload();
	void clearUI();

	void runWithPath(const std::vector<cocos2d::Vec2> &path, MoveControlProtocol::TRANSFORM_FUNC tranform = nullptr);
	void moveToNext(float dt);
	void arrivedEnd();

	bool isAlive() const;
	bool checkHit(const cocos2d::Vec2 &pos);

	void rotateToAngle(float angle, float dt = 0.0f);
	void beHited(Bullet *bullet);

protected:
	int m_monster_id = 0;
	cocos2d::ui::Widget *m_root = nullptr;

	MoveControlProtocol *m_move_control = nullptr;

	bool m_is_alive = false;
	std::vector<cocos2d::Vec2> m_path;

	float m_max_hp = 100.0f;
	float m_hp = 100.0f;

protected:
	virtual void onBeHited() {};
	virtual void onDead();
};