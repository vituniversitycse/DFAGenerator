#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "DFAState.h"

using std::list;
using std::string;

class Automata
{
public:
	Automata();
	~Automata();

	void TransitionState(string transitionToken);
	DFAState* FindState(string stateId);

	DFAState *currentState;
	list<DFAState*> states;

private:
	/*
	Predicate needed for find_if to locate DFA within the list<DFAState *>
	*/
	struct Predicate
	{
		Predicate(const string &id) : stateId(id) {}

		bool operator() (DFAState *dfa)
		{
			return dfa->IsState(stateId);
		}

	private:
		string stateId;
	};
};

