#include "ConfigReader.h"

std::set<std::string> DefaultConfigReader::LoadAlphabet()
{
	std::set<std::string> AlphabetSet;
	AlphabetSet.insert("a");
	AlphabetSet.insert("b");
	return AlphabetSet;
}

std::set<std::tuple<std::string, std::string>> DefaultConfigReader::LoadStates()
{
	/*
		Clear EOF Flag and set file iterator to beginning of file
	*/
	config.clear();
	config.seekg(0, std::ios::beg);

	std::string stateName, classification;
	std::set<std::tuple<std::string, std::string>> stateSet;

	if (config.is_open())
	{
		/*
			Scan to STATES: and begin reading
		*/
		for (int i = 0; i < 2; i++)
			config.ignore(256, ':');

		while (config >> stateName >> classification)
		{
			if (stateName == "TRANSITIONS:") { break; }
			stateSet.insert(std::make_tuple(stateName, classification));
		}
	}

	return stateSet;
}

std::set<std::tuple<std::string, std::string, std::string>> DefaultConfigReader::LoadTransitions()
{
	config.clear();
	config.seekg(0, std::ios::beg);

	std::string startState, destinationState, transitionToken;
	std::set<std::tuple<std::string, std::string, std::string>> transitionSet;
	
	if (config.is_open())
	{
		for (int i = 0; i < 3; i++)
			config.ignore(256, ':');

		while (!config.eof())
		{
			config >> startState >> destinationState >> transitionToken;
			transitionSet.insert(std::make_tuple(startState, destinationState, transitionToken));
		}
	}
	
	return transitionSet;
}