//Dan Hrubec
//cs 474
//project 3




#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "Driver.h"

using namespace std;


Driver::Driver()
{
	currWord = "";
	maxCubes = 10;
	initialWordLength = 0;
	test = false;
}

void Driver::printCommands()
{
	cout << "r: Reset Problem" << endl;
	cout << "c: Enter New Cube" << endl;
	cout << "a: Show All Cubes" << endl;
	cout << "w: Enter new word" << endl;
	cout << "s: Solve Problem" << endl;
	cout << "q: Quit" << endl;
}

void Driver::resolveR()
{
	cout << "Clearing all cubes. Resetting word." << endl;
	currWord = "";
	cubes.clearCollection();
}

void Driver::resolveC()
{
	if (cubes.getCubeCollection().size() == maxCubes)
	{
		cout << "Max cubes reached. Please use R to reset them, or use current cubes." << endl;
		return;
	}
	cout << "Please enter 6 characters one at a time for create a new cube." << endl;
	//loop control
	int i = 0;
	//counter for the chars entered, makes it easier on the user to understand.
	int counter = 1;
	vector<char> newCube;

	for (i = 0; i < 6; i++)
	{
		//prompt user to enter in a character
		cout << "Please enter character number " << counter << ": ";
		counter++;
		char charCheck;
		cin >> charCheck;
		//checking if the character is alphabetical and not symbols. Exits if we encounter a character we cannot enter.
		if (isalpha(charCheck) == false)
		{
			cout << "Invalid character entered. Returning." << endl;
			return;
		}
		else
		{
			//make everything capital for sake of simplicity.
			charCheck = toupper(charCheck);
			newCube.push_back(charCheck);
		}
	}



	//if it reaches here then all letters have been entered in correctly.
	//we just gotta add it to our collection

	Cube newCubeObj(newCube);
	cubes.addToCollection(newCubeObj);

}

void Driver::resolveA()
{
	//cout << "Printing all cubes" << endl;

	//goes through every cube we have in the collection
	for (unsigned int i = 0; i < cubes.getCubeCollection().size(); i++)
	{
		//gets the individual cube's letters
		Cube c = cubes.getCubeCollection()[i];
		cout << "{";
		//prints them out in a comma separated list
		for (unsigned int j = 0; j < 6; j++)
		{
			cout << c.getCubeLetters()[j];
			if (j != 5)
			{
				cout << ", ";
			}
		}
		cout << "}" << endl;
	}

	//we reached the end and have printed out all of the cubes.
	//cout  << "All Cubes Printed" << endl;
}

void Driver::resolveW()
{
	cout << "Please enter in a new word: ";
	string newWord;
	string buffer;
	vector<char> upperCaseWord;
	getline(cin, buffer);
	getline(cin, newWord);

	cout << "Testing validity of new word." << endl;
	//goes through each character of the string to make sure that each of them are alphabetic. Once done, we make the word uppercase.
	for (unsigned int i = 0; i < newWord.length(); i++)
	{
		if (isalpha(newWord[i]) == false || newWord[i] == ' ')
		{
			cout << "Character at position " << i + 1 << " is not valid. Rejecting string." << endl;
			return;
		}
		else
		{
			char temp = newWord[i];
			temp = toupper(temp);
			upperCaseWord.push_back(temp);
		}

	}

	cout << "New word is OK." << endl;
	cout << "Old word: " << currWord << endl;
	//now convert the entered string to all uppercase
	string test(upperCaseWord.begin(), upperCaseWord.end());
	currWord = test;
	initialWordLength = currWord.length();
	cout << "New word: " << currWord << endl;
}



void Driver::resolveS()
{
	int wordLength = currWord.length();

	//First testing out the simple if the word is too long for the number of cubes we have.
	if (wordLength > cubes.getCubeCollection().size())
	{
		cout << "Cannot create word with current cubes. Word is too long for the number of cubes." << endl;
		return;
	}

	//If we did not change the word, if it was reset recently, or no word has been entered
	if (currWord == "" || currWord.empty() == true)
	{
		cout << "Current word is empty. Use 'w' commoand to set a word." << endl;
		return;
	}


	string wordCopy = currWord;
	CubeCollection cubesCopy = cubes;
	WordSolver ws(wordCopy, cubesCopy, wordCopy.length());

	bool result = ws.recursiveSolution(currWord, cubesCopy);
	solution = ws.getSolution();

	if (result == true)
	{
		cout << currWord << " is able to be created." << endl;
		std::reverse(solution.begin(), solution.end());
		for (unsigned int i = 0; i < solution.size(); i++)
		{
			int index = 0;
			cout << "Letters: ";
			solution[i].printLetters();

			cout << "\t";
			for (int j = 0; j < solution[i].getCubeLetters().size(); j++)
			{
				if (wordCopy[i] == solution[i].getCubeLetters()[j])
				{
					index = j + 1;
					j = 5;
				}
			}
			cout << "Position: " << index << endl;

		}

	}
	else
	{
		cout << currWord << " was NOT able to be created." << endl;
	}

	//resetting some variables
	cFlag = false;
	solution.clear();

}

void Driver::beginExecution()
{
	char inputKey;
	printCommands();
	cout << "Please enter a command: ";
	cin >> inputKey;
	while (inputKey != 'q')
	{
		switch (inputKey)
		{
		case 'r':
			resolveR();
			break;
		case 'c':
			resolveC();
			break;
		case 'a':
			resolveA();
			break;
		case 'w':
			resolveW();
			break;
		case 's':
			resolveS();
			break;
		case 'q':
			exit(1);
			break;
		default:
			cout << "Unknown char entered. Try again." << endl;

		}
		cout << endl;
		printCommands();
		cout << "Please enter a command: ";
		cin >> inputKey;
	};


}
