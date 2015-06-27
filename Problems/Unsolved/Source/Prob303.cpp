/*
 * Prob303.cpp
 *
 *  Created on: May 9, 2014
 *      Author: Laurence
 */

#include "Prob303.hpp"

#include <iostream>
#include "Utilities.hpp"

using namespace std;

void Prob303 :: solve(void)
{
	cout << "Solving Problem 23..." << endl << endl;

	long long sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (i % 100 == 0) cout << i/100 << "%" << endl;
		sum += getLowestMultiplier(i);
	}

	cout << "Answer : " << sum << endl;
}

int Prob303 :: getLowestMultiplier(int n)
{
	int i = 1;
	while(true)
	{
		vector<int> digits = Utilities::getDigits((long long)n * (long long)i);
		std::sort(digits.begin(), digits.end());
		if (digits.back() <= 2) break;
		i++;
	}

	return i;
}
