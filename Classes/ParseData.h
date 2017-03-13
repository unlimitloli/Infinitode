#pragma once
#include <vector>
#include <string>
#include <map>

class ConfigParse;

class ElementData
{
public:
	typedef std::vector<std::string> _VectorType;
	ElementData(const _VectorType &vec);
	
	std::string getString(int col) const;
	int getInt(int row, int col) const;
	double getFloat(int row, int col) const;

protected:
	const _VectorType &m_data;
};

class ParseData
{
public:
	friend ConfigParse;

	typedef std::vector<std::vector<std::string>> _MapType;
	typedef std::vector<std::string> _VectorType;

	ParseData(const char * filename);
	ElementData getElement(int row) const;

	std::string getString(int row, int col) const;
	int getInt(int row, int col) const;
	double getFloat(int row, int col) const;

protected:
	_MapType m_data;

protected:
	void addLine(_VectorType & line);
	const char * m_filename;
};