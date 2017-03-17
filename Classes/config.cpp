#include "config.h"
#include "string_utils.h"

using namespace std;
using namespace sun;

Config *config = nullptr;

Config * Config::getInstance()
{
	if (config == nullptr)
	{
		config = new Config();
	}
	return config;
}

void Config::loadConfig()
{
	loadConfigFromFile("config/tower_config.txt");
}

void Config::clear()
{
}

void Config::reload()
{
}

const ParseData & Config::getData(const std::string & key) const
{
	return m_config.at(key);
}

void Config::loadConfigFromFile(const string & filename)
{
	size_t start_pos = filename.find_last_of("/");
	size_t end_pos = filename.find_first_of(".");
	string key = filename.substr(start_pos + 1, end_pos - start_pos - 1);
	ParseData data = ParseData(filename.c_str());
	m_config[key] = data;
}
