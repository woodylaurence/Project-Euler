/*
 * Proj_4.cpp
 *
 *  Created on: Mar 25, 2012
 *      Author: Laurence
 *
 *      Problem : "Find the largest palindrome made from the product of two 3-digit numbers. "
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class Prob4
{
	int main(void)
	{
		int number=1, k, tmp_i = 0, tmp_j = 0;

		for (int i = 999; i >= 1; i--)
		{
			for (int j = 999; j >= 1; j--)
			{
				k = i*j;
				if (checkPalindrome(k) && k >= number)
				{
					number = k;
					tmp_i = i;
					tmp_j = j;
				}
			}
		}

		cout << "Biggest palindrome formed by product of two 3-digit numbers is " << tmp_i << " x " << tmp_j << " = " << number << endl;
		return 0;
	}

	int* intToDigits(int number, int *numDigits)
	{
		int *digits;
		int i=0;

		digits = (int*) malloc(sizeof(int));

		while (number > 0)
		{
			digits[i] = number % 10;
			number /= 10;
			i++;
			digits = (int*) realloc(digits, (i+1)*sizeof(int));
		}

		*numDigits = i;
		return digits;
	}

	int checkPalindrome(int number)
	{
		int isPalindrome=1, numDigits;
		int *digits;

		digits = intToDigits(number, &numDigits);

		for (int i = 0; i < numDigits / 2; i++)
		{
			if (digits[i] != digits[numDigits - i - 1])
			{
				isPalindrome = 0;
				break;
			}
		}

		return isPalindrome;
	}
};
