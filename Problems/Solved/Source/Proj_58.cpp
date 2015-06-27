/*
 * Proj_58.cpp
 *
 *  Created on: Oct 20, 2012
 *      Author: Laurence
 *
 *      Problem: Create spiral of numbers, compute ratio number of diagonals which are prime to total diagonals, see when this ratio first drops below 10%
 */

#include <iostream>
#include <vector>

#include "Math.hpp"

using namespace std;

class Prob58
{
	int main(void)
	{
		int previousPrime = 1, i = 1, tmpNumPrimes = 0, numDiagonals = 1;
		double ratio = 1;

		while (ratio > 0.1)
		{
			i+=2;
			tmpNumPrimes += spiral(i, &previousPrime);
			numDiagonals += 4;
			ratio = (double) tmpNumPrimes / (double) numDiagonals;
		}

		cout << "Number of diagonals required: " << i << endl;

		return 0;
	}

	int spiral (int spiralSide, int *previousNum)
	{
		int numPrimes = 0, tmp, tmp2;
		vector<int> diagonalNumbers;

		tmp = spiralSide - 1;
		tmp2 = *previousNum + 4*(spiralSide-2) - 2;
		*previousNum = tmp2;

		diagonalNumbers.push_back(tmp2);

		for (int i = 1; i <= 2; i++)				// Don't do all 3 since the last diagonal in any level is always a square number
		{
			diagonalNumbers.push_back(tmp2 + i*tmp);
		}

		for (vector<int>::iterator iter = diagonalNumbers.begin(); iter != diagonalNumbers.end(); iter++)
		{
			if (Math::isPrime(*iter))
			{
				numPrimes++;
			}
		}

		return numPrimes;
	}
};
