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
	virtual bool IsState(string id) = 0;

protected:
	string	stateID;
	Classification	classification;
	//Transitions<Key: transitionToken, value: destinationID>
	map<string, string>	transitions;
};

class DFAState : State
{
public:
	DFAState(Automata &a, string id, Classification classifier, map<string, string> transitionTable);
	~DFAState();
	void Transition(string transitionToken);
	bool IsState(string id) { return id == stateID; }

private:
	Automata *automata;
};
