/*
 * Proj_112.cpp
 *
 *  Created on: Oct 24, 2012
 *      Author: Laurence
 *
 *      Problem:
 *
 *      Note, requires bigInt.cpp to run
 */

#include <iostream>
#include "BigInt.hpp"

using namespace std;

class Prob112
{
	int solve(void)
	{
        throw "Needs reimplementing";
		/*int i = 0, numBouncyNumbers = 0;
		double ratio = 0;
		BigInt *number;

		number = new BigInt(0);

		while(ratio != 0.99)
		{
			++(*number);
			i++;
			if (isBouncy(number))
			{
				numBouncyNumbers++;
			}
			ratio = (double) numBouncyNumbers / (double) i;
		}

		cout << "Answer:" << i << endl;

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
