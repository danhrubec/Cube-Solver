//Dan Hrubec
//cs 474
//project 3


#include <vector>
#include <string>
#include <iostream>

#include "CubeCollection.h"


class WordSolver
{
private:
	string word;
	CubeCollection cc;
	vector<Cube> solution;
	bool cFlag;
	int initialWordLength;
public:
	WordSolver();
	WordSolver(string s, CubeCollection cc_copy, int initWL);
	bool recursiveSolution(string wd, CubeCollection cc);
	vector<Cube> getSolution();

};
