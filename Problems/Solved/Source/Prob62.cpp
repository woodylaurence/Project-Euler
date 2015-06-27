/*
 * Prob62.cpp
 *
 *  Created on: Sep 4, 2014
 *      Author: Laurence
 */

#include "Prob62.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <ctime>

using namespace std;

void Prob62 :: solve()
{
	cout << "Solving Problem 62..." << endl << endl;

	long long num = 1;
	long long answer = 0;
	map<string, vector<int> > dictionaryOfHashesAndCubeRoots;

	clock_t start = clock();
	while(answer == 0)
	{
		stringstream stringStream;

		vector<int> digits = Utilities::getDigits(num * num * num);
		sort(digits.begin(), digits.end());

		for(vector<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
		{
			stringStream << *iter;
		}
		string digitsAsString = stringStream.str();

		if (dictionaryOfHashesAndCubeRoots.find(digitsAsString) == dictionaryOfHashesAndCubeRoots.end())
		{
			dictionaryOfHashesAndCubeRoots.insert(pair<string, vector<int> >(digitsAsString, vector<int>()));
		}

		dictionaryOfHashesAndCubeRoots.at(digitsAsString).push_back((int)num);
		if (dictionaryOfHashesAndCubeRoots.at(digitsAsString).size() == 5) answer = dictionaryOfHashesAndCubeRoots.at(digitsAsString).front();

		num++;
	}
	clock_t end = clock();

	cout << "Answer: " << answer * answer * answer << endl;
	cout << "Took " << (double)(end - start)/(CLOCKS_PER_SEC) * 1000 << "ms" << endl;
}
