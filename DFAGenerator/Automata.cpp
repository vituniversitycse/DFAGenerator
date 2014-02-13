#include "Automata.h"


Automata::Automata()
{
}


Automata::~Automata()
{
}

DFAState* Automata::FindState(string stateId)
{
	Predicate predicate(stateId);
	std::list<DFAState*>::iterator iter;
	iter = std::find_if(states.begin, states.end, predicate);
	return *iter;
}
