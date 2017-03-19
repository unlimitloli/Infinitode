#include "TowerAttibute.h"
#include "I18N.h"

using namespace std;

static const int MAX_BUFFER_SIZE = 1024;

static int attr_normal = -1;
static int attr_speed = -1;
static int attr_rate = -1;
static int attr_time = -1;

static const char * ATTR_NORMAL = "ATTR_NORMAL";
static const char * ATTR_SPEED = "ATTR_SPEED";
static const char * ATTR_RATE = "ATTR_RATE";
static const char * ATTR_TIME = "ATTR_TIME";

void getStringIndex()
{
	attr_normal = _i18n_id("string_tips", ATTR_NORMAL);
	attr_speed = _i18n_id("string_tips", ATTR_SPEED);
	attr_rate = _i18n_id("string_tips", ATTR_RATE);
	attr_time = _i18n_id("string_tips", ATTR_TIME);
}

TowerAttribute::TowerAttribute(AttrType _type, float _value) :
	type(_type), value(_value)
{
}

std::string TowerAttribute::typeToString()
{
	if (attr_normal < 0)
		getStringIndex();

	int attr_type = (int)type;
	if (attr_type < 100)
		return _i18n("string_tips", attr_normal + attr_type);
	else if (attr_type < 200)
		return _i18n("string_tips", attr_speed + attr_type - 100);
	else if (attr_type < 300)
		return _i18n("string_tips", attr_rate + attr_type - 200);
	else if (attr_type < 400)
		return _i18n("string_tips", attr_time + attr_type - 300);
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
