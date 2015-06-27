/*
 * Proj_48.cpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Laurence
 *
 *      Problem: Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000, i.e.·n^n n = [1,1000]
 */

#include "Proj_48.hpp"

#include "BigInt.hpp"

void Prob48::solve(void)
{
	cout << "Solving Problem 48..." << endl;

	BigInt sum = 0, tmp;

	for (int i = 1; i <= 1000; i++)
	{
		sum = sum + BigInt::power(i,i);
	}

	cout << "Sum: " << sum << endl;
	cout << "Answer: " << sum.lastNDigitsAsString(10) << endl;

	return;
}
