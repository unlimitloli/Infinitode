#pragma once
#include "ParseData.h"

class ConfigParse
{
public:
	static ParseData::_MapType parseFile(const char * filename);
};