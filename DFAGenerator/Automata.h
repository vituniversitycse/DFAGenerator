#pragma once
#include <string>
#include <list>
#include "DFAState.h"

using std::list;
using std::string;

class Automata
{
public:
	Automata();
	~Automata();

	void TransitionState(string transitionToken);

	DFAState currentState;
	list<DFAState> states;
};

