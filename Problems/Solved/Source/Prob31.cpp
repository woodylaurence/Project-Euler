/*
 * Prob31.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Laurence
 */

#include "Prob31.hpp"

#include <iostream>

void Prob31 :: solve()
{
	cout << "Answer: " << numWaysToMakeAmount(100, 99) << endl;
}

string Prob31 :: getProblemName()
{
    return "Problem 31";
}

long long Prob31 :: numWaysToMakeAmount(int amount, int largestDenominationToUse)
{
	int index = 0;
	long long numWays = 0;

	if (amount == 0 || amount == 1) return 1;

	cout << "Attempting to make " << amount << " with a maximum of " << largestDenominationToUse << endl;
	getchar();

	while (largestDenominationToUse < denominations[index]) index++;
	for (int i = index; i < 8; i++)
	{
		int tmp = (amount - denominations[i] < denominations[i]) ? denominations[i+1] : denominations[i];
		numWays += numWaysToMakeAmount(amount - denominations[i], tmp);
	}

	return numWays;
}
