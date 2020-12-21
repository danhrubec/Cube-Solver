//Dan Hrubec
//cs 474
//project 3




#include <vector>
#include <iostream>
#include <string>
#include "Cube.h"

using namespace std;

Cube::Cube()
{
	cubeLetters = {};
}

Cube::Cube(vector<char> newCube)
{
	cubeLetters = newCube;
}

vector<char> Cube::getCubeLetters()
{
	return cubeLetters;
}

void Cube::setCubeLetters(vector<char> newCube)
{
	cubeLetters = newCube;
}


void Cube::modifyPosition(int index, char newVal)
{
	cubeLetters[index] = newVal;
}

void Cube::printLetters()
{
	for (unsigned int i = 0; i < cubeLetters.size(); i++)
	{
		cout << cubeLetters[i] << " ";
	}
	cout << endl;
}
