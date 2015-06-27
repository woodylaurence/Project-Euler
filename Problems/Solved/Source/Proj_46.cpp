/*
 * Proj_46.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <cmath>
#include "Math.hpp"

class Prob46
{
	int main(void)
	{
		int number = 9, limit = 0;
		bool foundAnswer = false;

		while (!foundAnswer)
		{
			limit = (int) sqrt((double)number/2.0);
			for (int i = 1; i <= limit; i++)
			{
				if (Math::isPrime(number - 2*i*i))
				{
					break;
				}

				else if (i == limit)
				{
					foundAnswer = true;
				}
			}


			if (!foundAnswer)
			{
				number += 2;
				while (Math::isPrime(number))
				{
					number += 2;
				}
			}
		}

		std::cout << "Answer: " << number << std::endl;

		return 0;
	}
};
