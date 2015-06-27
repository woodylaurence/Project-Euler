/*
 * Proj_6.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define UPPER_LIMIT 100

class Prob6
{
	int main(void)
	{
		long int sumSquare=0, squareSum, diff;

		squareSum = 0.5*((double)UPPER_LIMIT)*((double)UPPER_LIMIT+ 1);
		squareSum *= squareSum;

		for (int i = 1; i <= (int) UPPER_LIMIT; i++)
		{
			sumSquare += i*i;
		}

		cout << "squareSum = " << squareSum << endl;
		cout << "sumSquare = " << sumSquare << endl;

		diff = squareSum - sumSquare;

		cout << "Difference is " << diff << endl;
		return 0;
	}
};
