/*
 * Proj_36.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Prob36
{
	int main(void)
	{
		int *decNumber, *binNumber, numDecDigits, numBinDigits, sum=0;

		for (int i = 1; i < 1000000; i++)
		{
			decNumber = intToDigits(i, 10, &numDecDigits);
			binNumber = intToDigits(i, 2, &numBinDigits);

			if (checkPalindrome(decNumber, numDecDigits) && checkPalindrome(binNumber, numBinDigits)) sum+= i;
		}

		cout << "Sum = " << sum << endl;

		return 0;
	}

	int* intToDigits(int number, int base, int *numDigits)
	{
		int *digits;
		int i=0;

		digits = (int*) malloc(sizeof(int));

		while (number > 0)
		{
			digits[i] = number % base;
			number /= base;
			i++;
			digits = (int*) realloc(digits, (i+1)*sizeof(int));
		}

		*numDigits = i;
		return digits;
	}

	int checkPalindrome(int *number, int numDigits)
	{
		int isPalindrome=1;

		for (int i = 0; i < numDigits / 2; i++)
		{
			if (number[i] != number[numDigits - i - 1])
			{
				isPalindrome = 0;
				break;
			}
		}

		return isPalindrome;
	}
};
