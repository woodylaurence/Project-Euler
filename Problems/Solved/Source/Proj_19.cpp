/*
 * Proj_19.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <math.h>

using namespace std;

class Prob19
{
	int solve(void)
	{
		int year=1900, month, i = 10, numSundays=0, k, j;

		for (year = 1900; year <= 2000; year++)
		{
			do
			{
				month = (i % 12) + 3;
				i++;
				k = year % 100;
				j = year / 100;
				if ( (1 + (13*(month+1)/5) + k + k/4 + j/4 + 5*j) % 7 == 1) numSundays++;
			}
			while (month != 14);
		}

		cout << "Number of Sundays on first day of month in 20th Century = " << numSundays << endl;
		return 0;
	}
};
