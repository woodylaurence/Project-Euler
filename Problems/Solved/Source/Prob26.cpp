/*
 * Prob26.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#include "Prob26.hpp"

#include <iostream>
#include <vector>

using namespace std;

void Prob26 :: solve()
{
	int answer = 1;
	int longestRepeat = 0;

	for (int i = 1; i <= 1000; i++)
	{
		vector<int> remainders = vector<int>();
		int remainder = 1;

		do
		{
			remainders.push_back(remainder);
			remainder = remainder * 10 % i;
		} while(find(remainders.begin(), remainders.end(), remainder) == remainders.end());

		if (remainders.size() >= longestRepeat)
		{
			longestRepeat = (int)remainders.size();
			answer = i;
		}
	}
	cout << "Answer: " << answer << endl;
}

string Prob26 :: getProblemName()
{
    return "Problem 26";
}
