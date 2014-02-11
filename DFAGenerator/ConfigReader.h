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
protected:
	IConfigReader(string filename)
	{
		try { config.open(filename); }
		catch (std::ifstream::failure e)
		{
			std::cerr << "An error occurred opening the file\n";
		}
	}
	~IConfigReader() { config.close(); }
	std::ifstream config;
public:
	virtual set<string>							LoadAlphabet()		= 0;
	virtual set<tuple<string, string>>			LoadStates()		= 0;
	virtual set<tuple<string, string, string>>	LoadTransitions()	= 0;
};

class DefaultConfigReader : IConfigReader
{
public:
	DefaultConfigReader(string filename = "../DATA/config.ini") : IConfigReader(filename) {}
	set<string>							LoadAlphabet();
	set<tuple<string, string>>			LoadStates();
	set<tuple<string, string, string>>	LoadTransitions();
};





void SomeFunction()
{

}