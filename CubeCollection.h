//Dan Hrubec
//cs 474
//project 3




#include <vector>
#include <string>
#include <iostream>
#include "Cube.h"

using namespace std;

class CubeCollection
{
private:
	vector<Cube> cCollection;

public:
	CubeCollection();
	CubeCollection(vector<Cube> cbc);
	vector<Cube> getCubeCollection();
	void setCubeCollection(vector<Cube> cbc);
	void clearCollection();
	void addToCollection(Cube c);
	void removeFromCollection(int index);
};
