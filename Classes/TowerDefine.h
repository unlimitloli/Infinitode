#pragma once

enum class AttackType
{
	Normal,			// ��ͨ
	Range,			// ��Χ
	Snipe,			// �ѻ�
};

enum class DebuffType
{
	Forzen,			// ����
};

enum class BuffType
{

};

enum class AttrType
{
	Damage = 0,		// �˺�

	AtkSpeed = 100,		// �����ٶ�
	RoateSpeed,		// ��ת�ٶ�
	BulletSpeed,	// �ӵ��ٶ�
	
	FreezingRate = 200,	// �䶳��

	FreezTime = 300,		// �䶳ʱ��
	UnFreezTime,	// �ⶳʱ��
	AimSpeed,		// ��׼ʱ��
};

enum class TowerState
{
	Ready = 0,		// ׼��״̬�����Կ���
	CoolDown = 1,	// ��ȴ��
};

