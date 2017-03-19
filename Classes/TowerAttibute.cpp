#include "TowerAttibute.h"

using namespace std;

const int MAX_BUFFER_SIZE = 1024;

const char *normal_attr_str[] = {
	"伤害",
};

const char *speed_attr_str[] =
{
	"攻击速度",
	"旋转速度",
	"弹丸速度",
};

const char *rate_attr_str[] =
{
	"冷冻率",
};

const char *time_attr_str[] =
{
	"瞄准时间",
	"冻结时间",
	"解冻时间",
};

TowerAttribute::TowerAttribute(AttrType _type, float _value) :
	type(_type), value(_value)
{
}

std::string TowerAttribute::typeToString()
{
	int attr_type = (int)type;
	if (attr_type < 100)
		return normal_attr_str[attr_type];
	else if (attr_type < 200)
		return speed_attr_str[attr_type - 100];
	else if (attr_type < 300)
		return rate_attr_str[attr_type - 200];
	else if (attr_type < 400)
		return rate_attr_str[attr_type - 300];
	return "";
}

std::string TowerAttribute::valueToString()
{
	int attr_type = (int)type;
	char buf[MAX_BUFFER_SIZE];
	if (attr_type < 100)
		sprintf_s(buf, MAX_BUFFER_SIZE, "%.2f", value);
	else if (attr_type < 200)
		sprintf_s(buf, MAX_BUFFER_SIZE, "%.2f/s", value);
	else if (attr_type < 300)
		sprintf_s(buf, MAX_BUFFER_SIZE, "%.2f%%", value * 100);
	else if (attr_type < 400)
		sprintf_s(buf, MAX_BUFFER_SIZE, "%.2fs", value);

	string ret = buf;
	return ret;
}
