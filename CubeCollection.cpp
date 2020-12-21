//Dan Hrubec
//cs 474
//project 3


#include <vector>
#include <iostream>
#include <string>
#include "CubeCollection.h"

using namespace std;

CubeCollection::CubeCollection()
{
	cCollection = {};
}

CubeCollection::CubeCollection(vector<Cube> cbc)
{
	cCollection = cbc;
}

vector<Cube> CubeCollection::getCubeCollection()
{
	return cCollection;
}

void CubeCollection::setCubeCollection(vector<Cube> cbc)
{
	cCollection = cbc;
}

void CubeCollection::clearCollection()
{
	cCollection.clear();
}

void CubeCollection::addToCollection(Cube c)
{
	cCollection.push_back(c);
}

void CubeCollection::removeFromCollection(int index)
{
	cCollection.erase(cCollection.begin() + index);
}
