#include "Automata.h"
#include "DFAStateFactory.h"
#include "ConfigReader.h"

Automata::Automata(DefaultConfigReader &reader)
{
	DFAStateFactory factory;
	STATES = factory.Create(this, reader.LoadStates(), reader.LoadTransitions());
}

Automata::~Automata()
{
	delete currentState, STATES;
}

bool Automata::ChangeState(const string stateId)
{
	Predicate predicate(stateId);
	std::list<DFAState*>::iterator iter;
	iter = std::find_if(STATES.begin(), STATES.end(), predicate);

	if ((*iter)->IsState(stateId))
	{
		currentState = *iter;
		return true;
	}

	return false;
}
