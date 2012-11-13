#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Permutation{

	Permutation(){}

	void load(string filename, int numShingles, int & numHashFuncs)
	{

		ifstream inF(filename.c_str(), ios::in);


		inF >> numHashFuncs; 

		PT.resize(numHashFuncs, vector<int>(numShingles, -1));

		for(int i = 0; i < numHashFuncs; i++){
			for(int x = 0; x < numShingles; x++){
				inF >> PT[i][x];
			}
		}
	}
	
	vector< vector<int> > PT;

	int hash(int i, int x)
	{
		return PT[i][x];
	}

};
