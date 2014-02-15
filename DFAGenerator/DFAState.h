#pragma once
#include <string>
#include <map>

class Automata;
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
	State(	const string id,
			const Classification classifier,
			const map<string, string> transitionTable) :	STATE_ID(id),
															CLASSIFICATION(classifier),
															TRANSITIONS(transitionTable) { };

	virtual void Transition(const string token) = 0;
	virtual bool IsState(const string id) = 0;

protected:
	const string		STATE_ID;
	Classification		CLASSIFICATION;
	map<string, string>	TRANSITIONS;	// Transitions<Key: transitionToken, value: destinationID>
};	

class DFAState : State
{
public:
	DFAState(Automata *automaton,
		const string id,
		const Classification classifier,
		const map<string, string> transitionTable) : State(id, classifier, transitionTable),
													automata(automaton) { };

	~DFAState();
	void Transition(const string transitionToken);
	bool IsState(const string id) { return id == STATE_ID; };

private:
	Automata *automata;
};
