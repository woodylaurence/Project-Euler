/*
 * Prob75.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: Laurence
 */

#include "Prob75.hpp"

#include <iostream>
#include <cmath>

using namespace std;

void Prob75 :: solve()
{
	cout << "Solving Problem 75..." << endl;

	int lengths[1500000] = {0};

	for (int i = 1; i < 375000; i++)
	{
		if (i % 500 == 0) cout << i << endl;
		for (int j = i; (i + j) <= 750000; j++)
		{
			double k = sqrt((double)(i*i + j*j));
			if (fmod(sqrt(k), 1.0) == 0 && i+j+k <= 1500000)
			{
				lengths[(int)(i+j+k - 1)]++;
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < 1500000; i++)
	{
		if (lengths[i] == 1) answer++;
	}

	cout << "Answer: " << answer << endl;
}
