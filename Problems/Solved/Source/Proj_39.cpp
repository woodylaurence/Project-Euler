/*
 * Proj_39.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <math.h>

using namespace std;

class Prob39
{
	int main(void)
	{
		int p, c, *num, maxP;

		num = (int*) malloc(1000*sizeof(int));

		for (int a = 1; a < 1000; a++)
		{
			for (int b = 1; b < 1000; b++)
			{
				c = checkValidTriangle(a, b);
				if (c)
				{
					p = a + b + c;
					if (p <= 1000)
					{
						num[p-1]++;
					}
				}
			}
		}

		maxP = findMostRearrangements(num);

		cout << "Most rearrangements for p value of: " << maxP << endl;

		return 0;
	}

	int checkValidTriangle(int a, int b)
	{
		int isValid = 0;
		double d_a, d_b, c;

		d_a = (double)a;
		d_b = (double)b;

		c = sqrt(d_a*d_a + d_b*d_b);

		if (fmod(c, 1.0) == 0)
		{
			isValid = (int)c;
		}

		return isValid;
	}

	int findMostRearrangements(int *array)
	{
		int maxP = 0, tmpMaxNum = 0;

		for (int i = 0; i < 1000; i++)
		{
			if  (array[i] > tmpMaxNum)
			{
				tmpMaxNum = array[i];
				maxP = i;
			}
		}

		return (maxP + 1);			//plus 1 because value in array[0] = 1
	}
};
