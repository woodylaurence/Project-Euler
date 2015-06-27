/*
 * Prob94.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Laurence
 */

#include "Prob94.hpp"

#include "Math.hpp"
#include "BigInt.hpp"

using namespace std;

void Prob94 :: solve()
{
	BigInt sum = 0;
	BigInt x_0, y_0;

	Math::getPrimitiveSolutionForPellEquation(3, &x_0, &y_0);

	BigInt x = x_0, y = y_0;
	while (true)
	{
		Math::getNextSolutionForPellEquation(3, &x, &y, x_0, y_0);

		if (x > 500000000) break;

		int x_int = x.toInt();
		if ((x_int * 2 + 1) % 3 == 0) sum = sum + (2 * x_int + 2);
		else if((x_int * 2 - 1) % 3 == 0) sum = sum + (2 * x_int - 2);
	}

	cout << "Answer: " << sum << endl;
}

string Prob94 :: getProblemName()
{
    return "Problem 94";
}