#include <iostream>
#include "ConfigReader.h"
#include "Automata.h"

void PrintHelp();
string ReadInput();
bool ParseInput(string input);

int main(int argc, char* argv[]){
	/*
		Read in filename from command line arguments if it exists
		Load default config.ini if argument is missing
	*/
	std::cout << ">>>\n";
	std::cout << ">>> Welcome to the DFA Generator\n";
	std::cout << ">>>\n";
	DefaultConfigReader *configReader = new DefaultConfigReader();

	PrintHelp();

	if (argc > 1) { configReader->LoadConfig(argv[1]); }
	Automata *automata = new Automata(*configReader);
	while (true)
	{
		if (ParseInput(ReadInput()))
		{
			std::cout << ">>> Automata analysis....\n";
		}
	}

	/* Cleanup */
	delete configReader;
	delete automata;
}

void PrintHelp()
{
	std::cout << ">>>\n";
	std::cout << ">>> DFA Generator help system\n";
	std::cout << ">>> :h to bring up the help menu\n";
	std::cout << ">>> :l <FILE_PATH> to load a new machine\n";
	std::cout << ">>> :q to quit\n";
	std::cout << ">>>\n";
}

string ReadInput()
{
	string userInput;
	std::cout << ">>> ";
	std::cin >> userInput;

	return userInput;
}

/*
	Input: User input from console
	Output: Boolean	:	False for command input
						True for user input
*/
bool ParseInput(string input)
{
	if (input.compare(":q") == 0) { exit(0); return false; }
	else if (input.compare(":h") == 0) { PrintHelp(); return false; }
	else if (input.compare(":l") == 0) { return false; }
	return true;
}