/*
 * Proj_44.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Laurence
 *
 *      Bit of a hacky solution, just so happened that the answer was found in first 5000 pentagonal numbers
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define NUM_NUMBERS_TO_GENERATE 5000

class Prob44
{
	int main(void)
	{
		vector<int> pentagonalNumbers;
		int D, minD = 2147483640;

		pentagonalNumbers = generatePentagonalNumbers(NUM_NUMBERS_TO_GENERATE);

		for (vector<int>::iterator iter = pentagonalNumbers.begin(); iter != pentagonalNumbers.end(); iter++)
		{
			for (vector<int>::iterator jter = iter+1; jter != pentagonalNumbers.end(); jter++)
			{
				D = *jter - *iter;
				if (testSumDiff(*iter, *jter) && D < minD)
				{
					minD = D;
				}
			}
		}

		cout << "Answer: " << minD << endl;

		return 0;
	}

	vector<int> generatePentagonalNumbers(int numPentagonalNumbers)
	{
		vector<int> numbers;

		for (int i = 1; i <= numPentagonalNumbers; i++)
		{
			numbers.push_back(i*(3*i - 1)*0.5);
		}

		return numbers;
	}

	bool isPentagonal(int number)
	{
		double tmp;

		tmp = sqrt(1 + 24*number);

		return (fmod(tmp, 6.0) == 5.0);
	}

	bool testSumDiff(int num1, int num2)
	{
		return (isPentagonal(num2 - num1) && isPentagonal(num2 + num1));
	}
};
