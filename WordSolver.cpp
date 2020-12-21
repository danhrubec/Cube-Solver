//Dan Hrubec
//cs 474
//project 3




#include <vector>
#include <string>
#include <iostream>

#include "WordSolver.h"

WordSolver::WordSolver()
{
	word = "";
	cFlag = false;
	initialWordLength = 0;
}

WordSolver::WordSolver(string s, CubeCollection cc_copy, int initWL)
{
	word = s;
	cc = cc_copy;
	initialWordLength = initWL;
}

bool WordSolver::recursiveSolution(string wd, CubeCollection cc)
{
	//cout << "current word: " << wd << endl;
	int wordlength = wd.length();
	//cout << "current word length: " << wordlength << endl;

	if (wd.empty() == true)
	{

		cFlag = true;

		return true;
	}

	char targetChar = wd[0];
	bool addedAlready = false;

	//goes through every cube we have in the collection
	for (unsigned int i = 0; i < cc.getCubeCollection().size(); i++)
	{
		//gets the individual cube's letters
		Cube c = cc.getCubeCollection()[i];
		//c.printLetters();

		for (unsigned int j = 0; j < 6; j++)
		{
			if (targetChar == c.getCubeLetters()[j])
			{
				//cout << "Target found." << endl;
				CubeCollection ccCopy = cc;
				string newWord = "";
				bool res = false;
				if (wordlength > 1)
				{
					newWord = wd.substr(1);
				}
				else
				{
					newWord = "";
				}
				ccCopy.removeFromCollection(i);

				j = 5;
				if (cFlag == false)
				{
					res = recursiveSolution(newWord, ccCopy);

				}

				if (res == true && solution.size() < initialWordLength)
				{
					solution.push_back(c);

					addedAlready = true;
				}






			}
		}

	}


	if (cFlag == true)
	{

		return true;
	}
	else
	{

		return false;
	}

}

vector<Cube> WordSolver::getSolution()
{
	return solution;
}

