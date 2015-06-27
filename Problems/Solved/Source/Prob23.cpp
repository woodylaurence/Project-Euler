/*
 * Proj_23.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Laurence
 */

#include "Prob23.hpp"

#include <iostream>
#include "Math.hpp"

void Prob23 :: solve(void)
{
	vector<bool> canBeWrittenAsAbundent = vector<bool>(28123, false);
	vector<int> abundentNumbers = getAbundantNumbers();

	int numAbundantNumbers = (int)abundentNumbers.size();
	for(int i = 0; i < numAbundantNumbers; i++)
	{
		for (int j = i; j < numAbundantNumbers; j++)
		{
			int num1 = abundentNumbers.at(i);
			int num2 = abundentNumbers.at(j);
			if (num1 + num2 <= 28123) canBeWrittenAsAbundent.at(num1 + num2 - 1) = true;
			else break;
		}
	}

	int sum = 0;
	for (int i = 0; i < 28123; i++)
	{
		sum += (canBeWrittenAsAbundent.at(i) == false) ? (i + 1) : 0;
	}

	cout << "Answer: " << sum << endl;
}

string Prob23 :: getProblemName()
{
    return "Problem 23";
}

vector<int> Prob23 :: getAbundantNumbers()
{
	vector<int> abundantNumbers;
	for (int i = 1; i <= 28123; i++)
	{
		if (Math::getSumOfFactorsExcludingNum(i) > i) abundantNumbers.push_back(i);
	}

	return abundantNumbers;
}

