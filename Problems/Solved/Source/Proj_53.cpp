/*
 * Proj_53.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Laurence
 *
 *      Problem: How many values of n_C_r exceed 1 million, for 1 <= n <= 100
 *
 *      NB
 */

#include <iostream>
#include <vector>

using namespace std;

class Prob53
{
	int main(void)
	{
		int numValuesAboveMil = 0;
		vector<short int> numbers;

		for (int i = 0; i < 100; i++)
		{
			numbers.push_back(i+1);
		}

		/*int n = 100, r = 3;
		fractionIsOverOneMillion(n, r, n-r, numbers);*/

		for (int n = 1; n <= 100; n++)
		{
			for (int r = 1; r <= n; r++)
			{
				if (fractionIsOverOneMillion(n, r, n-r, numbers))
				{
					numValuesAboveMil++;
				}
			}
		}

		cout << "Number of values above 1 million: " << numValuesAboveMil << endl;

		return 0;
	}

	bool fractionIsOverOneMillion(int n, int r, int diff, vector<short int> numbers)
	{
		int bigger, smaller;
		double tmpNumber = 1;

		// Ternary operators, find the bigger and smaller of r and n-r
		smaller = r > diff ? diff : r;
		bigger = r > diff ? r : diff;

		for (int i = 2; i <= smaller; i++)
		{
			tmpNumber /= i;
		}

		for (int i = bigger; i < n; i++)
		{
			tmpNumber *= (double)numbers.at(i);
			if (tmpNumber > 1000000.0)
			{
				return true;
			}
		}

		//cout << tmpNumber << endl;

		return false;
	}
};
