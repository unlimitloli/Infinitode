#pragma once
#include <string>
#include <vector>

namespace sun
{
	std::vector<std::string> split(const std::string &src, const std::string &sep);
	std::string replace(const std::string &src, const std::string &old_str, const std::string &new_str);
}