#include "DFAStateFactory.h"
#include "Automata.h"

DFAStateFactory::DFAStateFactory()
{
}


DFAStateFactory::~DFAStateFactory()
{
}

list<DFAState*> DFAStateFactory::Create(	Automata *automaton,
										const set<tuple<string, string>> states,
										const set<tuple<string, string, string>> transitions)
{
	list<DFAState*> list;
	
	std::set<tuple<string, string>>::iterator stateIterator;
	for (stateIterator = states.begin(); stateIterator != states.end(); ++stateIterator)
	{
		string id = std::get<0>(*stateIterator);
		string classifier = std::get<1>(*stateIterator);

		// Set classifier
		Classification classification = START;
		if (classifier.compare("START") == 0) { classification = START; }
		else if (classifier.compare("FINAL") == 0) { classification = FINAL; }
		else if (classifier.compare("NO") == 0){ classification = NO; }
		else
		{
			// Throw error 
		}

		// Find all transitions matching this state id
		std::map<string, string> transitionTable;
		std::set<tuple<string, string, string>>::iterator transitionIterator;
		for (transitionIterator = transitions.begin(); transitionIterator != transitions.end(); ++transitionIterator)
		{
			if (std::get<0>(*transitionIterator) == id)
			{
				// Build map<key: token, value: destination> for state
				transitionTable[std::get<2>(*transitionIterator)] = std::get<1>(*transitionIterator);
			}
		}

		// Add new DFAState to list
		list.push_back(new DFAState(automaton, id, classification, transitionTable));
	}

	return list;
}
