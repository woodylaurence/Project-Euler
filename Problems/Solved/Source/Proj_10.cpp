/*
 * Proj_10.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include "Math.hpp"

using namespace std;

#define UPPER_LIMIT 2000000

class Prob10
{
	int solve(void)
	{
		int flag=0;
		long int number = 9, sumPrimes = 17, tmpPrime;

		while (!flag)
		{
			if (Math::isPrime(number))
			{
				tmpPrime = number;

				if (tmpPrime < UPPER_LIMIT)
				{
					sumPrimes += tmpPrime;
				}

				else flag = 1;
			}
			number+=2;
		}

		cout << "Sum of primes below " << UPPER_LIMIT << " : " << sumPrimes << endl;
		return 0;
	}
};
