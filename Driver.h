//Dan Hrubec
//cs 474
//project 3




#include <vector>
#include <string>
#include <iostream>

#include "WordSolver.h"

using namespace std;

class Driver
{
private:
	string currWord;
	CubeCollection cubes;
	vector<Cube> solution;

	int maxCubes;
	int initialWordLength;
	bool cFlag;
	bool test;

public:
	Driver();
	void printCommands();
	void resolveR();
	void resolveC();
	void resolveA();
	void resolveW();
	void resolveS();
	void beginExecution();
};

