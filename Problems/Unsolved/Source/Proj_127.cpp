/*
 * Proj_127.cpp
 *
 *  Created on: Apr 15, 2013
 *      Author: Laurence
 */

// This works, but takes a long time!

#include <iostream>
#include "Math.hpp"

using namespace std;

class Prob127
{
int solve(void)
{
	int sum = 0;

	for (int a = 1; a < 1000; a++)
	{
		for (int b = a+1, c = a+b; c < 1000; b++, c++)
		{
			/*if (b % 10000 == 0)
			{
				cout << b << endl;
			}*/
			if (noGCD(a, b, c))
			{
				if (findRadical(a*b*c) < c)
				{
					sum += c;
				}
			}
		}
		/*if (a % 10000 == 0)
		{
			cout << " -------- " << a << " -------- " << endl;
		}*/
	}

	cout << "Sum of abc-hits where c < 12000: " << sum << endl;

	return 0;
}

int findGCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return findGCD(b, a % b);
	}
}

bool noGCD(int a, int b, int c)
{
	if (findGCD(a, b) == 1 && findGCD(b, c) == 1 && findGCD(a, c) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int findRadical(int num)
{
	int radical = 1;
	//vector<int> primeFactors = getPrimeFactors(num);
	vector<int> primeFactors;

	for (vector<int>::iterator iter = primeFactors.begin(); iter != primeFactors.end(); iter++)
	{
		radical *= *iter;
	}

	return radical;
}
};
