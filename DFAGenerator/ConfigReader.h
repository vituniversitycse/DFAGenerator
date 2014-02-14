#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <list>
#include <tuple>

using std::string;
using std::set;
using std::tuple;
using std::list;

class IConfigReader
{
public:
	IConfigReader();
	~IConfigReader() { config.close(); };
	virtual bool LoadConfig(string filename) = 0;
	virtual set<string> LoadAlphabet() = 0;
	virtual set<tuple<string, string>> LoadStates() = 0;
	virtual set<tuple<string, string, string>> LoadTransitions() = 0;
protected:
	std::ifstream config;
};

class DefaultConfigReader : IConfigReader
{
public:
	DefaultConfigReader(string filename = "../DATA/config.ini");
	bool LoadConfig(string filename);
	set<string>							LoadAlphabet();
	set<tuple<string, string>>			LoadStates();
	set<tuple<string, string, string>>	LoadTransitions();
};