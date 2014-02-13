#include "DFAState.h"

DFAState::DFAState(Automata &a, string id, Classification classifier, map<string, string> transition)
{
	*automata = a;
}


DFAState::~DFAState()
{
}

void DFAState::Transition(string transitionToken)
{
	/*
	Take in transition token
	Grab destination state id by token key
	Locate destination id within list of states in Automata
	Set current location to address of destination state
	*/

	string destination = transitions[transitionToken];
}