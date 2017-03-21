#pragma once
#include "MoveControlProtocol.h"

class SimpleMoveControl : public MoveControlProtocol
{
public:
	using MoveControlProtocol::MoveControlProtocol;

	virtual void move(float dt) override;
	
protected:
	virtual void onStart() override;
	virtual void transformDirection();

	virtual void onTransDirection();
};