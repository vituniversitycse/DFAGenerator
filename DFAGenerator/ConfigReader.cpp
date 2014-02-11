#include "ConfigReader.h"

set<string> DefaultConfigReader::LoadAlphabet()
{
	set<string> AlphabetSet;
	AlphabetSet.insert("a");
	AlphabetSet.insert("b");
	return AlphabetSet;
}

set<tuple<string, string>> DefaultConfigReader::LoadStates()
{
	/* Clear EOF Flag and set file iterator to beginning of file */
	config.clear();
	config.seekg(0, std::ios::beg);
	set<tuple<string, string>> stateSet;
	string stateName, classification;

	if (config.is_open())
	{
		/* Scan to STATES: and begin reading */
		for (int i = 0; i < 2; i++)
			config.ignore(256, ':');

		while (config >> stateName >> classification)
		{
			if (stateName == "TRANSITIONS:") { break; }
			stateSet.insert(make_tuple(stateName, classification));
		}
	}
	return stateSet;
}

set<tuple<string, string, string>> DefaultConfigReader::LoadTransitions()
{
	config.clear();
	config.seekg(0, std::ios::beg);
	set<tuple<string, string, string>> transitionSet;
	string	startState, destinationState, transitionToken;

	if (config.is_open())
	{
		for (int i = 0; i < 3; i++)
			config.ignore(256, ':');

		while (!config.eof())
		{
			config >> startState >> destinationState >> transitionToken;
			transitionSet.insert(make_tuple(startState, destinationState, transitionToken));
		}
	}
	return transitionSet;
}