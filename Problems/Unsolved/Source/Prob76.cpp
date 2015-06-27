/*
 * Prob76.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#include "Prob76.hpp"

#include <iostream>

using namespace std;

void Prob76 :: solve()
{
	cout << "Solving Problem 31..." << endl << endl;

	denominations = new int[99];

	for(int i = 0; i < 100; i++)
	{
		denominations[i] = 99 - i;
	}

	cout << "Answer: " << numWaysToMakeAmount(100, 99) << endl;
}

long long Prob76 :: numWaysToMakeAmount(int amount, int largestDenominationToUse)
{
	int index = 0;
	long long numWays = 0;

	if (amount == 0 || amount == 1) return 1;
	if (amount < 0)  return 0;

	cout << "Attempting to make " << amount << " with a maximum of " << largestDenominationToUse << endl;
//	getchar();

	while (largestDenominationToUse < denominations[index]) index++;
	for (int i = index; i < 99; i++)
	{
		numWays += numWaysToMakeAmount(amount - denominations[i], denominations[index]);
	}

	return numWays;
}
