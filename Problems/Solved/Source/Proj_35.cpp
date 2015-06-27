/*
 * Proj_35.cpp
 *
 *  Created on: Aug 17, 2012
 *      Author: Laurence
 *
 *      Problem: How many circular primes are there below one million?
 */

#include <iostream>
#include <list>
#include "Math.hpp"

using namespace std;

class Prob35
{
	int main(void)	/* Set numCircularPrimes at 1 one beacuse we start looking for primes at 3, this removes  */
	{				/* the case of 2 where digit is even which would mess with the checkNoEvenDigits routine. */
		int numCyclicPrimes = 1, cyclicNumbersArePrime, *cyclicNumbers;
		list<int> digits;

		for (int i = 3; i < 1000000; i+=2)
		{
			if (checkNoEvenDigits(i, &digits))
			{
				if (Math::isPrime(i))
				{
					cyclicNumbersArePrime = 1;

					if (i > 10)				/* Remove issue ot cyclying numbers with only one digit. */
					{
						cyclicNumbers = cycleDigits(digits);

						for (int j = 1; j < (int)digits.size(); j++)
						{
							if (!Math::isPrime(cyclicNumbers[j-1]))
							{
								cyclicNumbersArePrime = 0;
								break;
							}
						}
					}

					if (cyclicNumbersArePrime)
					{
						numCyclicPrimes++;
					}
				}
			}
		}

		cout << "Number of cyclic primes below 1,000,000 : " << numCyclicPrimes << endl;

		return 0;
	}

	int checkNoEvenDigits(int number, list<int> *digits)
	{
		int noEvenDigits = 1;

		digits->clear();

		while (number != 0)
		{
			digits->push_front(number % 10);
			number /= 10;
		}

		for (list<int>::iterator iter = digits->begin(); iter != digits->end(); iter ++)
		{
			if (*iter % 2 == 0)
			{
				noEvenDigits = 0;
				break;
			}
		}

		return noEvenDigits;
	}

	int* cycleDigits(list<int> digits)
	{
		int *cyclicNumbers, tmp, numCycles;

		numCycles = (int)digits.size() - 1;
		cyclicNumbers = (int*) malloc(numCycles*sizeof(int));			/* size - 1 since we have already checked one permutation of the number. */

		for (int i = 0; i < numCycles; i++)
		{
			tmp = digits.front();
			digits.pop_front();
			digits.push_back(tmp);
			cyclicNumbers[i] = digitsToNumber(digits);
		}

		return cyclicNumbers;
	}

	int digitsToNumber(list<int> digits)
	{
		int number = 0, factor = 1;

		for (list<int>::reverse_iterator i = digits.rbegin(); i != digits.rend(); i++)
		{
			number += (*i)*factor;
			factor *= 10;
		}

		return number;
	}
};
