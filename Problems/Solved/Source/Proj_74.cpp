/*
 * Proj_74.cpp
 *
 *  Created on: Oct 23, 2012
 *      Author: Laurence
 *
 *      Problem:
 */

#include <iostream>
#include <vector>

using namespace std;

#define MAX 60;

class Prob74
{
	int main(void)
	{
		bool repeated;
		int numChains = 0, number;
		vector<int> previousValues;
		vector<int>::iterator iter;

		for (int i = 1; i < 1000000; i++)
		{
			repeated = false;
			previousValues.clear();
			number = i;
			while(!repeated)
			{
				previousValues.push_back(number);
				number = factorialDigits(number);

				for (iter = previousValues.begin(); iter != previousValues.end(); iter++)
				{
					if (number == *iter)
					{
						repeated = true;
						break;
					}
				}
			}

			if ((int)previousValues.size() == 60)
			{
				numChains++;
			}
		}

		cout << "Answer:" << numChains << endl;

		return 0;
	}

	int factorial(int n)
	{
		if (n > 1)
		{
			return n*factorial(n-1);
		}
		else return 1;
	}

	int factorialDigits(int num)
	{
		int factorialOfDigits = 0;

		while (num > 0)
		{
			factorialOfDigits += factorial(num % 10);
			num /= 10;
		}

		return factorialOfDigits;
	}
};
