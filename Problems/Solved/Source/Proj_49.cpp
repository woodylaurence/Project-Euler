/*
 * Proj_49.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include "Math.hpp"

using namespace std;

class Prob49
{
	int main(void)
	{
		int *numbers, **digits, *cDigits;
		int i;

		numbers = (int*) malloc(3*sizeof(int));

		for (i = 1001; i <= 3339; i+=2)
		{
			numbers[0] = i;
			numbers[1] = numbers[0] + 3330;
			numbers[2] = numbers[1] + 3330;

			if (Math::isPrime(numbers[0]) &&
				Math::isPrime(numbers[1]) &&
				Math::isPrime(numbers[2]) &&
				checkPermutation(numbers))
			{
				digits = getDigits(numbers);
				cDigits = concatenateDigits(digits);
				cout << "Found permutable prime triplet: " << numbers[0] << ", " << numbers[1] << " and " << numbers[2] << ". Concatenated number: ";
				for (int i = 0; i < 12; i++)
				{
					cout << cDigits[i];
				}
				cout << endl;
			}
		}

		return 0;
	}

	int **getDigits(int *numbers)
	{
		int **digits, *tmpNumbers;

		digits = (int**) malloc(3*sizeof(int*));
		tmpNumbers = (int*) malloc(3*sizeof(int));

		for (int i = 0; i < 3; i++)
		{
			digits[i] = (int*) malloc(4*sizeof(int));
		}

		for (int i = 0; i < 3; i++)
		{
			tmpNumbers[i] = numbers[i];
			for (int j = 0; j < 4; j++)
			{
				digits[i][j] = tmpNumbers[i] % 10;
				tmpNumbers[i] /= 10;
			}
		}

		return digits;
	}

	int *concatenateDigits(int **digits)
	{
		int *concatenatedDigits;

		concatenatedDigits = (int*) malloc(12*sizeof(int));

		for (int i = 0; i < 4; i++)
		{
			concatenatedDigits[i] = digits[0][3-i];
			concatenatedDigits[i+4] = digits[1][3-i];
			concatenatedDigits[i+8] = digits[2][3-i];
		}

		return concatenatedDigits;
	}

	int checkPermutation(int *numbers)
	{
		int isPermutation=1, tmp;
		int *tmpNumbers, **digits;

		tmpNumbers = (int*) malloc(3*sizeof(int));

		digits = getDigits(numbers);

		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int m = k + 1; m < 4; m++)
				{
					if (digits[i][m] <= digits[i][k])				/* Order digits */
					{
						tmp = digits[i][m];
						digits[i][m] = digits[i][k];
						digits[i][k] = tmp;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ( (digits[1][i] != digits[0][i]) || (digits[2][i] != digits[0][i]))
			{
				isPermutation = 0;
				break;
			}
		}

		return isPermutation;
	}
};
