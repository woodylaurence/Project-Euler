/*
 * Proj_7.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: Laurence
 */

#include <iostream>
#include "Math.hpp"

using namespace std;

#define NUM_PRIMES 10001

class Prob7
{
	int main(void)
	{
		int numPrimesFound = 4;		/* Start at 9 having found 2, 3, 5 and 7 to avoid issue of starting prime check at 3 conflicting with sqrt(tmpNumber)*/
		long int number=9;

		while (numPrimesFound != NUM_PRIMES)
		{
			if (Math::isPrime(number))
			{
				numPrimesFound++;
			}
			number+=2;
		}

		cout << "Prime # " << NUM_PRIMES << " : " << number-2 << endl;
		return 0;
	}
};
