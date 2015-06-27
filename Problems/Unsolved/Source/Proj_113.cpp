/*
 * Proj_113.cpp
 *
 *  Created on: Oct 24, 2012
 *      Author: Laurence
 *
 *      Problem: How many numbers below 10^100 are bouncy?
 *
 *      Note: Requires BigInt.cpp to run
 *
 *      NB. At the moment, this will take > 10^91 years to run
 */

#include <iostream>
#include "BigInt.hpp"

using namespace std;

class Prob113
{
int solve(void)
{
	BigInt google;

	google = BigInt::power(10, 100);

    throw "Needs reimplementing";
	/*for (BigInt i = 1; i < google; ++i)
	{
		j++;
		cout << j << endl;
		if (isBouncy(&i))
		{
			numBouncyNumbers++;
		}
	}

	return 0;*/
}

bool isBouncy(BigInt *num)
{
    throw "Needs reimplementing";
	/*bool numIsBouncy = false, increasing = true, decreasing = true;
	list<int> digits;
	list<int>::iterator jter, kter;

	digits = num->getValue();
	jter = digits.end();
	jter--;

	for (list<int>::iterator iter = digits.begin(); iter != jter && !numIsBouncy; iter++)
	{
		kter = iter;
		kter++;

		increasing = increasing && (*iter <= *kter);
		decreasing = decreasing && (*iter >= *kter);

		numIsBouncy = !(increasing || decreasing);
	}


	return numIsBouncy;*/
}
};

