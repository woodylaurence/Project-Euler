/*
 * Proj_14.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Prob14
{
	int solve(void)
	{
		long int number = 0, numberSteps=1, tmpNumber = 2;
		long int *checkedNumbers;
		int tmpNumSteps;

		checkedNumbers = (long int*) malloc(sizeof(long int));

		for (int i = 1; i <= 1000000; i++)
		{
			tmpNumber = i;
			tmpNumSteps = 0;
			while (tmpNumber != 1)
			{
				if (tmpNumber % 2 == 0) tmpNumber /=2;
				else tmpNumber = 3*tmpNumber + 1;
				tmpNumSteps++;
			}
			if (tmpNumSteps >= numberSteps)
			{
				numberSteps = tmpNumSteps;
				number = i;
			}
		}

		cout << number << endl;

		return 0;
	}
};
