#pragma once
#include "MoveControlProtocol.h"

class SimpleMoveControl : public MoveControlProtocol
{
public:
	using MoveControlProtocol::MoveControlProtocol;

	virtual void move(float dt) override;
	virtual void onStart() override;
};