/*
 * Proj_101.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Laurence
 */

#include <iostream>
#include "Proj_101.hpp"

void Prob101 :: solve()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << i << ": ";
		vector<long long> series = findBOP(i);
		for (vector<long long>::iterator iter = series.begin(); iter != series.end(); iter++)
		{
			cout << *iter << ", ";
		}
		cout << endl;
	}
}

long long Prob101::myPow(int base, int exponent)
{
	long long answer = (long long)base;

	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i < exponent; i++)
		{
			answer *= (long long)base;
		}
	}

	return answer;
}

long long Prob101::u_n(int n)
{
	long long answer = 0;

	for (int i = 0; i <= 10; i++)
	{
		answer += myPow(-1, i)*myPow(n, i);
	}

	return answer;
}

vector<long long > Prob101::findBOP(int k)
{
	vector<long long> firstKTerms;

	for (int i = 1; i <= k; i++)
	{
		firstKTerms.push_back(u_n(i));
	}

	return firstKTerms;
}
