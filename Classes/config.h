#pragma once

#include <string>
#include <map>
#include "ParseData.h"

#define		_config									Config::getInstance()
#define		_config_int(file, id, param)			Config::getInstance()->getData(file).getInt(id, (int)param)
#define		_config_string(file, id, param)			Config::getInstance()->getData(file).getString(id, (int)param)
#define		_config_float(file, id, param)			Config::getInstance()->getData(file).getFloat(id, (int)param)
#define		_config_count(file)						Config::getInstance()->getData(file).count()

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