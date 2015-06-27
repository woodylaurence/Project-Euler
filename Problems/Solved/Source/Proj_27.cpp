/*
 * Proj_27.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 */

#include <iostream>
#include "Math.hpp"

using namespace std;

class Prob27
{
	int main(void)
	{
		int maxNumConsecutivePrimes = 0, tmpNumConsecutivePrimes, number, n, abProduct = 0, bestA = 0, bestB = 0;

		for (int a = -9999; a < 10000; a++)
		{
			for (int b = -9999; b < 10000; b++)
			{
				n = 0;
				tmpNumConsecutivePrimes = 0;
				while(1)
				{
					number = n*n + a*n + b;

					if (number < 0) break;

					if (Math::isPrime(number))
					{
						tmpNumConsecutivePrimes++;
						n++;
					}

					else
					{
						break;
					}
				}
				if (tmpNumConsecutivePrimes > maxNumConsecutivePrimes)
				{
					maxNumConsecutivePrimes = tmpNumConsecutivePrimes;
					abProduct = a*b;
					bestA = a;
					bestB = b;
				}
			}
		}

		cout << "n^2 + (" << bestA << ") + (" << bestB << ") yields " << maxNumConsecutivePrimes << " consecutive primes. ab = " << abProduct << endl;

		return 0;
	}
};
