#include "string_utils.h"
#include <vector>

using namespace std;
using namespace sun;

std::vector<std::string> sun::split(const std::string & src, const std::string & sep)
{
	vector<string> result;
	size_t start_pos = 0;
	size_t last_pos = 0;
	while (start_pos != string::npos)
	{
		last_pos = src.find_first_of(sep, start_pos);
		string sub = src.substr(start_pos, last_pos - start_pos);
		result.push_back(sub);
		start_pos = src.find_first_not_of(sep, last_pos);
	}

	return result;
}

std::string sun::replace(const std::string & src, const std::string & old_str, const std::string & new_str)
{
	string result = src;
	size_t len = new_str.length();
	size_t pos = 0;

	while ((pos = result.find(old_str, pos)) != string::npos)
	{
		result.replace(pos, len, new_str);
		pos += len;
	}

	return result;
}
