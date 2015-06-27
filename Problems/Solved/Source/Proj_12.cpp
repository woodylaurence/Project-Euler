/*
 * Proj_12.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define NUM_DIV 500

class Prob112
{
	int solve(void)
	{
		int flag=0, numDivisors, i=2;
		long int number=1;

		while (!flag)
		{
			numDivisors = 0;

			for (int i = 1; i < sqrt((double) number); i++)
			{
				if (number % i == 0 ) numDivisors++;
			}
			if (fmod(sqrt((double) number), 1.0) == 0) numDivisors = 2*numDivisors + 1;
			else numDivisors *= 2;

			if (numDivisors > NUM_DIV) flag = 1;
			else number += (long)i;
			i++;
		}

		cout << "First number with more than " << NUM_DIV << " divisors is " << number << endl;
		return 0;
	}
};
