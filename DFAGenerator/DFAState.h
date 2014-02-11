#pragma once
#include <string>
#include <map>
#include "Automata.h"

using std::string;
using std::map;

enum Classification
{
	START,
	FINAL,
	NO
};



class State
{
public:
	State();
	~State();

	virtual void Transition(string transitionToken) = 0;

protected:
	Classification	classification;
	string		stateID;
	//Transitions<Key: transitionToken, value: destinationID>
	map<string, string> transitions;
};

class DFAState : State
{
public:
	DFAState(Automata &automata);

	void Transition(string transitionToken);

private:
	Automata automata;
};
