/*
 * Proj_47.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: Laurence
 *
 *      Problem: Find the first four consecutive numbers with four distinct primes
 *
 *      NB. This program is very slow, having to constantly check whether number is prime takes a lot of time
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "Math.hpp"

using namespace std;

class Prob47
{
	int main(void)
	{
		int number = 1;

		while (!getPrimeFactors(number))
		{
			number++;
			if (number % 10000 == 0)
			{
				cout << number << endl;
			}
		}

		cout << "Answer: " << number << endl;

		return 0;
	}

	bool getPrimeFactors(int tmpNum)
	{
		int primeNumber, tmp, numDistinct, tmpFactor = 0;
		bool distinct = true;

		for (int i = 0; i < 4; i++)
		{
			numDistinct = 0;
			tmp = tmpNum + i;
			primeNumber = 2;
			while(tmp > 2)
			{
				if (tmp % primeNumber == 0)
				{
					tmp /= primeNumber;
					if (primeNumber != tmpFactor)
					{
						tmpFactor = primeNumber;
						numDistinct++;
					}
				}

				else
				{
					primeNumber = getNextPrime(primeNumber);
				}
			}

			distinct = distinct && (numDistinct > 3);
			if (!distinct)
			{
				break;
			}
		}

		return distinct;
	}

	int getNextPrime(int primeNum)
	{
		if (primeNum == 2)
		{
			primeNum += 1;
		}

		else
		{
			primeNum += 2;
		}

		while(!Math::isPrime(primeNum))					/* This is using function from prime.cpp */
		{
			primeNum +=2;
		}

		return primeNum;
	}
};
