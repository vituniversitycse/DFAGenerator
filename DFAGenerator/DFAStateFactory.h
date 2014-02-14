#pragma once
#include <list>
#include <set>
#include <tuple>

class Automata;
class DFAState;
using std::string;
using std::tuple;
using std::list;
using std::set;

class DFAStateFactory
{
public:
	DFAStateFactory();
	~DFAStateFactory();

	list<DFAState*> Create(	Automata *automaton,
							const set<tuple<string, string>> states,
							const set<tuple<string, string, string>> transitions);
};

