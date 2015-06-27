/*
 * Proj_37.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 */

#include <iostream>
#include "Math.hpp"

using namespace std;

class Prob37
{
	int main(void)
	{
		int i = 11, numPrimesFound = 0, sum = 0;

		while (numPrimesFound < 11)
		{
			if (Math::isPrime(i) && checkPrimeRemoveDigits(i))
			{
				numPrimesFound++;
				cout << numPrimesFound << " -- " << i << endl;
				sum += i;
			}
			i+=2;
		}

		cout << "Sum of 11 truncatable primes: " << sum << endl;

		return 0;
	}

	int checkPrimeRemoveDigits(int number)
	{
		int allNumbersPrime = 1, numDigits, tmpNumber, divisor = 1;

		tmpNumber = number;

		numDigits = getNumDigits(number);

		for (int i = 1; i < numDigits; i++)
		{
			divisor *= 10;
		}

		for (int i = 1; i < numDigits; i++)
		{
			//cout << "got into here" << endl;
			removeRightDigit(&number);
			if (!Math::isPrime(number))
			{
				allNumbersPrime = 0;
				break;
			}
		}

		if (!Math::isPrime(number))
		{
			allNumbersPrime = 0;
		}

		for (int i = 1; i < numDigits && allNumbersPrime; i++)
		{
			removeLeftDigit(&tmpNumber, divisor);
			divisor /= 10;
			if (!Math::isPrime(tmpNumber))
			{
				allNumbersPrime = 0;
				break;
			}

		}

		return allNumbersPrime;
	}

	void removeLeftDigit(int *number, int divisor)
	{
		*number = *number % divisor;
		return;
	}

	void removeRightDigit(int *number)
	{
		*number /= 10;
		return;
	}

	int getNumDigits(int number)
	{
		int numDigits = 0;

		while (number > 0)
		{
			number /= 10;
			numDigits++;
		}

		return numDigits;
	}
};
