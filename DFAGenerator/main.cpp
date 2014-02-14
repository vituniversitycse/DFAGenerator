#include <iostream>
#include "ConfigReader.h"
#include "Automata.h"

int main(int argc, char* argv[]){
	/*
		Read in filename from command line arguments if it exists
		Load default config.ini if argument is missing
	*/
	DefaultConfigReader *configReader = (argc > 1) ? new DefaultConfigReader(argv[1]) : new DefaultConfigReader();
	Automata *automata = new Automata(*configReader);

	delete configReader;
	delete automata;
	
}