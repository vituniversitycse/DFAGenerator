#pragma once
#include <list>
#include <set>
#include <tuple>
#include "DFAState.h"

using std::string;
using std::tuple;
using std::list;
using std::set;

class DFAStateFactory
{
public:
	DFAStateFactory();
	~DFAStateFactory();

	list<DFAState> Create(	set<tuple<string, string>> states,
							set<tuple<string, string, string>> transitions);
};

