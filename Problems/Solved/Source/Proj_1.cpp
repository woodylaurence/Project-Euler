/*
 * Proj_1.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Laurence Woodward
 *
 *      Problem : "Find the sum of all the multiples of 3 or 5 below 1000."
 */

#include <iostream>
#include "Proj_1.hpp"

using namespace std;

#define UPPER_LIMIT 1000
#define FACTOR_1 3
#define FACTOR_2 5

void Prob1::solve()
{
	int total = 0;

	total += triangle(UPPER_LIMIT, FACTOR_1);
	total += triangle(UPPER_LIMIT, FACTOR_2);
	total -= triangle(UPPER_LIMIT, int(FACTOR_1)*int(FACTOR_2));

	cout << "Sum = " << total << "\n";
}

int Prob1::triangle(int limit, int delta)
{
	int sum=0;

	for (int i = delta; i < limit; i+=delta)
	{
		sum += i;
	}

	return sum;
}

IProblem::~IProblem() {}
