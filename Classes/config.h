#pragma once

#include <string>
#include <map>
#include "ParseData.h"

#define		_config			Config::getInstance()

class Config
{
public:
	static Config *getInstance();
	
	void loadConfig();
	void clear();
	void reload();

	const ParseData& getData(const std::string & key) const;

protected:
	std::map<std::string, ParseData> m_config;

	void loadConfigFromFile(const std::string & filename);
};