#include "ParseData.h"
#include <string>
#include "ConfigParse.h"

using namespace std;

ElementData::ElementData(const _VectorType & vec)
	:m_data(vec)
{
}

std::string ElementData::getString(int col) const
{
	return m_data.at(col);
}

int ElementData::getInt(int col) const
{
	string value = m_data.at(col);
	return atoi(value.c_str());
}

double ElementData::getFloat(int col) const
{
	string value = m_data.at(col);
	return atof(value.c_str());
}

ParseData::ParseData(const char * filename)
	:m_filename(filename)
{
	m_data = ConfigParse::parseFile(filename);
}

ElementData ParseData::getElement(int row) const
{
	return ElementData(m_data.at(row));
}

std::string ParseData::getString(int row, int col) const
{
	return m_data.at(row).at(col);
}

int ParseData::getInt(int row, int col) const
{
	string value = m_data.at(row).at(col);
	return atoi(value.c_str());
}

double ParseData::getFloat(int row, int col) const
{
	string value = m_data.at(row).at(col);
	return atof(value.c_str());
}

void ParseData::addLine(_VectorType & line)
{
	m_data.push_back(line);
}

