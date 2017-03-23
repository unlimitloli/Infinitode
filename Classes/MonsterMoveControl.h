#pragma once
#include "SimpleMoveControl.h"

class MonsterMoveControl : public SimpleMoveControl
{
public:
	using SimpleMoveControl::SimpleMoveControl;

protected:
	virtual void onTransDirection(float dt = 0.0f) override;
};