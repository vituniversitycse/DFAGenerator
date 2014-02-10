#include <iostream>
#include "ConfigReader.h"

int main(){
	DefaultConfigReader configReader;

	configReader.LoadStates();
	configReader.LoadTransitions();
}