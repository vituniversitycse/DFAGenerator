DFA Generator
=============
---
Author: 	Dustin Kerns 	<br />
Date: 		2/6/2014 		<br />
Modified: 	2/6/2014 		<br />
Class:		CST-229 Grammars<br />
Assignment:	Lab #1

Requirements
---
Write a program to simulate a machine known as the deterministic finite automata (dfa). Your program reads a description of a machine M (from an input file) which includes:

> - A list of states
> - A set of alphabet letters
> - A set of transition functions
> - A start state
> - A set of final states

It then reads in a set of input strings (interactively) and determines whether or not a particular string is acceptable by the machine.


> - You can design the format of your input file.  Please include in the ReadMe file what the format is.
> - Your program must be general enough to simulate ANY finite automata (not limiting to the three test cases).
> - Your program must check for error conditions and invalid inputs.
> - Your program will be graded on completeness and correctness.
> - The program must be properly documented according the [Code Style guide](http://oit.edu/faculty/sherry.yang/cst229/OIT_CodeStd_v2.0.doc) posted on my [webpage](http://oit.edu/faculty/sherry.yang/cst229/).

Config.ini Format
---
The Config.ini can be found under the DATA directory in the solution.

The alphabet for the DFA is defined as a set in the form { a, b }. Begin the definition of these transitions after the ```ALPHABET:``` header. 
Example
```
ALPHABET:
{ a, b }
```

States are represented as a tuple of the schema (State_Id, Classification) separated by newlines. Begin the definition of these transitions after the ```STATES:``` header. The classification is one of three conditions START, FINAL, or NO states. This set of states can only contain a single state with a START classifier.

Example
```
STATES:
(0, START)
(1, FINAL)
(2, NO)
```

Transitions are represented with a tuple of the schema (Start_State_Id, Final_State_Id, Transition_Token) separated by newlines. Begin the definition of these transitions after the ```TRANSITIONS:``` header. Any states defined in the config.ini must have transitions defined for all tokens of the alphabet. A single state cannot have an ambiguous or duplicate transition.

Example
```
TRANSITIONS:
(0, 1, a)
(0, 2, b)
(1, 1, a)
(1, 2, b)
(2, 2, a)
(2, 2, b)
```

Program Instructions
---
The program will automatically load the config.ini and attempt to parse the declared grammar. The user will then be prompted for an input containing tokens from the declared alphabet separated by spaces. To exit the application enter ```EXIT!``` as the input or close the terminal.

Example
```
Config.ini loaded successfully!
Input: a b b
Output: INVALID
Input: a a a
Output: VALID
Input: EXIT!
```