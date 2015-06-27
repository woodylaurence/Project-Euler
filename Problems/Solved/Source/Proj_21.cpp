/*
 * Proj_21.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 */

#include <iostream>

using namespace std;

class Prob21
{
	int solve(void)
	{
		int sumAmicablePairs = 0, tmp;

		for (int i = 1; i < 10000; i++)
		{
			tmp = getSumDivisors(i);
			if ((i == getSumDivisors(tmp)) && i != tmp)
			{
				sumAmicablePairs += i;				/* Sum only i since the other number in pair will also be summed when it is reached in the loop. */
			}
		}

		cout << "Sum of all amicable numbers less than 10,000: " << sumAmicablePairs << endl;

		return 0;
	}

	int getSumDivisors(int number)
	{
		int sumDivisors = 0;

		for (int i = 1; i < number; i++)
		{
			if (number % i == 0)
			{
				sumDivisors += i;
			}
		}

		return sumDivisors;
	}
};
