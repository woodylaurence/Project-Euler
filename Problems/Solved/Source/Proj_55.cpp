/*
 * Proj_55.cpp
 *
 *  Created on: Aug 18, 2012
 *      Author: Laurence
 *
 *      Problem: How many Lychrel numbers are there below 10,000?
 */

#include "BigInt.hpp"

class Prob55
{
	int main(void)
	{
		int numLychrelNumbers = 0, j;
		BigInt tmpNumber, a;

		for (int i = 1; i <= 10000; i++)
		{
			tmpNumber = i;

			for (j = 1; j <= 50; j++)
			{
				if (checkIsPalindrome(&tmpNumber))
				{
					break;
				}

			}

			if (j == 51)
			{
				numLychrelNumbers++;
			}

		}

		cout << "Number of Lychrel numbers below 10,000: " << numLychrelNumbers << endl;

		return 0;
	}

	int checkIsPalindrome(BigInt *number)
	{
        throw "Needs reimplementing";
		/*int isPalindrome = 1;
		BigInt reversedNumber;

		reversedNumber = number->reverseDigits();
		*number = *number + reversedNumber;
		reversedNumber = number->reverseDigits();

		if (reversedNumber != *number)
		{
			isPalindrome = 0;
		}

		return isPalindrome;*/
	}
};
