//Dan Hrubec
//cs 474
//project 3



#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Cube
{
private:
	vector<char> cubeLetters;
public:
	Cube();
	Cube(vector<char> newCube);
	vector<char> getCubeLetters();
	void setCubeLetters(vector<char> newCube);
	void modifyPosition(int index, char newVal);
	void printLetters();

};
