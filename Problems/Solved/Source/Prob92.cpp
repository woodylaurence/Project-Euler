/*
 * Prob92.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Laurence
 *
 *      Problem: Taking a number and recursively squaring its digits we always end up at 89 or 1:
 *      		 85 -> 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89
 *      		 How many n for 1 ² n ² 10,000,000 end up at 89?
 */

#include "Prob92.hpp"

#include <iostream>
#include "Utilities.hpp"

using namespace std;

void Prob92 :: solve()
{
	cout << "Solving Problem 92..." << endl << endl;

	int numEndingIn89 = 0;

	for (int i = 2; i < 10000000; i++)
	{
		if (getSquareOfSumDigits(i) == 89) numEndingIn89++;
	}

	cout << "Answer: " << numEndingIn89 << endl;
}

int Prob92 :: getSquareOfSumDigits(int num)
{
	vector<int> digits = Utilities::getDigits(num);

	int squareSumDigits = 0;
	for (vector<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
	{
		squareSumDigits += (*iter) * (*iter);
	}

	if (squareSumDigits == 1 || squareSumDigits == 89) return squareSumDigits;

	return getSquareOfSumDigits(squareSumDigits);
}
