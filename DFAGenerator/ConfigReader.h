#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <list>
#include <tuple>

class IConfigReader
{

protected:
	IConfigReader(std::string filename)
	{
		try
		{
			config.open(filename);
		}
		catch (std::ifstream::failure e)
		{
			std::cerr << "An error occurred opening the file\n";
		}
	}

	~IConfigReader()
	{
		config.close();
	}

	std::ifstream config;

public:
	virtual std::set<std::string> LoadAlphabet() = 0;
	virtual std::set<std::tuple<std::string, std::string>> LoadStates() = 0;
	virtual std::set<std::tuple<std::string, std::string, std::string>> LoadTransitions() = 0;

};

class DefaultConfigReader : IConfigReader
{

public:
	DefaultConfigReader(std::string filename = "../DATA/config.ini") : IConfigReader(filename) {}

	std::set<std::string> LoadAlphabet();
	std::set<std::tuple<std::string, std::string>> LoadStates();
	std::set<std::tuple<std::string, std::string, std::string>> LoadTransitions();

};