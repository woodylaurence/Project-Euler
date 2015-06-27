/*
 * Proj_66.cpp
 *
 *  Created on: Oct 24, 2012
 *      Author: Laurence
 *
 *      Problem: Consider x^2 - Dy^2 = 1, find value of D which gives largest minimal solution in x (for 1 < D <= 1000) Note, not positive integer solutions exist for D = q^2
 */

#include "Prob66.hpp"

#include <iostream>
#include <cmath>

#include "Math.hpp"
#include "BigInt.hpp"

using namespace std;

void Prob66 :: solve()
{
	BigInt maxX = 0;
	int maxD = 0;

	for (int D = 2; D <= 1000; D++)
	{
		if (fmod(sqrt(D), 1.0) == 0.0) continue;

		BigInt x, y;
		Math::getPrimitiveSolutionForPellEquation(D, &x, &y);

//		cout << "D = " << D << ",x = " << x << endl;

		if (x > maxX)
		{
			maxX = x;
			maxD = D;
		}
	}

	cout << "Answer: " << maxD << endl;
}

string Prob66 :: getProblemName()
{
    return "Problem 66";
}
