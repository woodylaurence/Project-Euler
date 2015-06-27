/*
 * Prob72.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#include "Prob72.hpp"
#include "Math.hpp"

#include <iostream>
#include <algorithm>

void Prob72 :: solve()
{
	cout << "Solving Problem 72..." << endl;

	int answer = 0;

	vector< vector<int> > factors = vector< vector<int> >();

	factors.push_back(vector<int>());
	for(int i = 1; i <= 1000000; i++)
	{
		if (i % 10000 == 0) cout << i << endl;
		factors.push_back(Math::getPrimeFactors(i));
	}

	for(int i = 1; i <= 1000000; i++)
	{
		cout << i << endl;
		for (int j = 1; j < i; j++)
		{
			vector<int> num1PrimeFactors = factors.at(j);
			vector<int> num2PrimeFactors = factors.at(i);
			for(vector<int>::iterator iter = num1PrimeFactors.begin(); iter != num1PrimeFactors.end(); iter++)
			{
					if (find(num2PrimeFactors.begin(), num2PrimeFactors.end(), *iter) == num2PrimeFactors.end()) answer++;
			}
		}
	}

	cout << "Answer: " << answer << endl;
}

string Prob72 :: getProblemName()
{
    return "Problem 72";
}

bool Prob72 :: mutuallyPrime(int num1, int num2)
{
	vector<int> num1PrimeFactors = Math::getPrimeFactors(num1);
	vector<int> num2PrimeFactors = Math::getPrimeFactors(num2);

	for(vector<int>::iterator iter = num1PrimeFactors.begin(); iter != num1PrimeFactors.end(); iter++)
	{
		if (find(num2PrimeFactors.begin(), num2PrimeFactors.end(), *iter) != num2PrimeFactors.end()) return false;
	}

	return true;
}
