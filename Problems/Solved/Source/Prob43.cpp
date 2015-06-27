/*
 * Proj_43.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Laurence
 */

#include "Prob43.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#include "Utilities.hpp"

void Prob43 :: solve()
{
	cout << "Solving Problem 43..." << endl << endl;

	long long sum = 0;
	vector<int> pandigitalNumber;
	vector<long long> pandigitalNumbersWithProperty;

	pandigitalNumber.push_back(0);
	pandigitalNumber.push_back(1);
	pandigitalNumber.push_back(2);
	pandigitalNumber.push_back(3);
	pandigitalNumber.push_back(4);
	pandigitalNumber.push_back(5);
	pandigitalNumber.push_back(6);
	pandigitalNumber.push_back(7);
	pandigitalNumber.push_back(8);
	pandigitalNumber.push_back(9);

	while(next_permutation(pandigitalNumber.begin(), pandigitalNumber.end()))
	{
		if ((convertSubDigitsToNumber(2, pandigitalNumber) % 2) == 0
			&& (convertSubDigitsToNumber(3, pandigitalNumber) % 3) == 0
			&& (convertSubDigitsToNumber(4, pandigitalNumber) % 5) == 0
			&& (convertSubDigitsToNumber(5, pandigitalNumber) % 7) == 0
			&& (convertSubDigitsToNumber(6, pandigitalNumber) % 11) == 0
			&& (convertSubDigitsToNumber(7, pandigitalNumber) % 13) == 0
			&& (convertSubDigitsToNumber(8, pandigitalNumber) % 17) == 0)
		{
			pandigitalNumbersWithProperty.push_back(Utilities::digitsToLongLong(pandigitalNumber));
		}
	}

	for (vector<long long>::iterator iter = pandigitalNumbersWithProperty.begin(); iter != pandigitalNumbersWithProperty.end(); iter++)
	{
		sum += *iter;
	}

	cout << "Answer: " << sum << endl;
}

int Prob43 :: convertSubDigitsToNumber(int firstDig, vector<int> number)
{
	return (100*number.at(firstDig - 1) + 10*number.at(firstDig) + number.at(firstDig + 1));
}
