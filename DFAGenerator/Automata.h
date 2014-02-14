#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "DFAState.h"

class DefaultConfigReader;
using std::list;
using std::string;

class Automata
{
public:
	Automata(DefaultConfigReader &reader);
	~Automata();

	bool ChangeState(const string stateId);

private:
	DFAState *currentState;
	list<DFAState*> STATES;

	/*
	Predicate needed for find_if to locate DFA within the list<DFAState*>
	*/
	struct Predicate
	{
		Predicate(const string &id) : stateId(id) { ; }
		bool operator() (DFAState *dfa) { return dfa->IsState(stateId); };

	private:
		string stateId;
	};
};

