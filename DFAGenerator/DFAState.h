#pragma once
#include <string>
#include <map>

class DFAState
{
public:
	DFAState();
	~DFAState();

protected:
	Classification	classification;
	std::string		stateID;
	//Transitions<Key: transitionToken, value: destinationID>
	std::map<std::string, std::string> transitions;
};

enum Classification
{
	START,
	FINAL,
	NO
};
