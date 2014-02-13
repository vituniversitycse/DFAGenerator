#include <iostream>
#include "ConfigReader.h"

int main(int argc, char* argv[]){
	DefaultConfigReader *configReader = new DefaultConfigReader(argv[1]);

	configReader->LoadStates();
	configReader->LoadTransitions();

	delete configReader;
}