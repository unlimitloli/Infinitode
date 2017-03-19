#pragma once
#include "TowerDefine.h"
#include <string>

class TowerAttribute
{
public:
	TowerAttribute(AttrType _type = AttrType::Damage, float _value = 0.0f);

	AttrType type = AttrType::Damage;
	float value = 0.0f;

	std::string typeToString();
	std::string valueToString();
};