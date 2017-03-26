#pragma once

enum class AttackType
{
	Normal,			// 普通
	Range,			// 范围
	Snipe,			// 狙击
};

enum class DebuffType
{
	Forzen,			// 冰冻
};

enum class BuffType
{

};

enum class AttrType
{
	Damage = 0,		// 伤害

	AtkSpeed = 100,		// 攻击速度
	RoateSpeed,		// 旋转速度
	BulletSpeed,	// 子弹速度
	
	FreezingRate = 200,	// 冷冻率

	FreezTime = 300,		// 冷冻时间
	UnFreezTime,	// 解冻时间
	AimSpeed,		// 瞄准时间
};

enum class TowerState
{
	Ready = 0,		// 准备状态，可以开火
	CoolDown = 1,	// 冷却中
};

