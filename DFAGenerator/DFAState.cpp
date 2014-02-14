#include "DFAState.h"
#include "Automata.h"

DFAState::~DFAState()
{
	delete automata;
}

void DFAState::Transition(string token)
{
	/*
	Take in transition token
	Grab destination state id by token key
	Locate destination id within list of states in Automata
	Set current location to address of destination state
	*/

	string destination = TRANSITIONS[token];
	automata->ChangeState(destination);
	return;
}