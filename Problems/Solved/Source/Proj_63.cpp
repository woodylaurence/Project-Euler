/*
 * Proj_63.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Laurence
 *
 *      Problem: Find how many numbers a^n contain n-digits (Note, 9^22 only has 21 digits, thus n <= 21)
 */

#include <iostream>
#include "BigInt.hpp"

class Prob63
{
	int main(void)
	{
		int numNDigitNumbers = 0;
		BigInt a;

		for (int i = 1; i < 22; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				a = BigInt::power(j, i);

				if (a.getNumDigits() == i)
				{
					numNDigitNumbers++;
				}
			}
		}

		std::cout << "Answer: " << numNDigitNumbers << std::endl;

		return 0;
	}
};
