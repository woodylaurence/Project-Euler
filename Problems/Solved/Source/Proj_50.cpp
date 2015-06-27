/*
 * Proj_50.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <list>
#include "Math.hpp"

class Prob50
{
	int main(void)
	{
		int tmpSum, tmpNumConsecutivePrimes, maxNumConsecutivePrimes = 0, prime = 0;
		list<int> primes;
		list<int>::iterator endPrime;

		for (int i = 3; i < 1000000; i+=2)
		{
			if (Math::isPrime(i))
			{
				primes.push_back(i);
			}
		}

		endPrime = primes.end();
		endPrime--;

		for (list<int>::iterator iter = primes.begin(); iter != endPrime;)
		{
			tmpSum = *iter;
			tmpNumConsecutivePrimes = 1;
			iter++;												// This line increments iter, note it is not missing from the for loop initialisation
			for (list<int>::iterator jter = iter; (tmpSum + *jter) < 1000000; jter++)
			{
				tmpSum += *jter;
				tmpNumConsecutivePrimes++;
				if (Math::isPrime(tmpSum))
				{
					if (tmpNumConsecutivePrimes > maxNumConsecutivePrimes)
					{
						prime = tmpSum;
						maxNumConsecutivePrimes = tmpNumConsecutivePrimes;
					}
				}
			}
		}

		std::cout << "Answer: " << prime << " with " << maxNumConsecutivePrimes << " primes." << std::endl;

		return 0;
	}
};
