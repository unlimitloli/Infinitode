#include "ConfigParse.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "string_utils.h"

using namespace std;
using namespace sun;

ParseData::_MapType ConfigParse::parseFile(const char * filename)
{
	ParseData::_MapType data;

	string file = replace(filename, "/", "\\");

	ifstream input_file(file);
	if (!input_file)
	{
		cout << "open file " << filename << " filed!" << endl;
	}

	while (!input_file.eof())
	{
		string line;
		getline(input_file, line);
		vector<string> line_vec = split(line, " \t\n,");
		data.push_back(line_vec);
	}

	return data;
}


