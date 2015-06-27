/*
 * Prob41.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Laurence
 *
 *      Problem: Find the largest n-digit pandigital prime that exists
 *
 *      n-pandigital means number contains 1..n once and only once
 */

#include "Prob41.hpp"
#include "Math.hpp"

#include <iostream>
#include <algorithm>

void Prob41 :: solve()
{
	cout << "Answer: " << getLargestPandigitalPrime() << endl;
}

string Prob41 :: getProblemName()
{
    return "Problem 41";
}

long Prob41 :: getNumFromDigits(vector<int> digits)
{
	long num = 0;
	long multipler = 1;

	for(vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++)
	{
		num += (*iter) * multipler;
		multipler *= 10;
	}

	return num;
}

long Prob41 :: getLargestPandigitalPrime()
{
	for (int i = 9; i > 2; i--)
	{
		vector<int> digits = vector<int>();
		for (int j = i; j > 0; j--)
		{
			digits.push_back(j);
		}

		do
		{
			if (Math::isPrime(getNumFromDigits(digits))) return getNumFromDigits(digits);
		} while (std::prev_permutation(digits.begin(), digits.end()));
	}

	return 0;
}
