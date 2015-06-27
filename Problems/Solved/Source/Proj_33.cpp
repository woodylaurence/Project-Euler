/*
 * Proj_33.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <list>

using namespace std;

class Prob33
{
	int main(void)
	{
		int c, d, productNumerator = 1, productDenominator = 1;

		for (int a = 10; a < 100; a++)
		{
			for (int b = a+1 ; b < 100; b++)
			{
				c = a;
				d = b;
				if (removeCommonDigits(&c, &d) && ((double)c / (double) d == (double)a / (double)b))
				{
					productNumerator *= c;
					productDenominator *= d;
				}
			}
		}

		reduceFraction(&productNumerator, &productDenominator);

		cout << "Reduced product fraction denominator: " << productDenominator << endl;
		return 0;
	}

	int removeCommonDigits(int *numerator, int *denominator)
	{
		int foundCommonDigit = 0;

		if (*numerator / 10 == *denominator / 10 && *numerator / 10 != 0)
		{
			*numerator = *numerator % 10;
			*denominator = *denominator % 10;
			foundCommonDigit = 1;
		}

		else if (*numerator / 10 == *denominator % 10 && *numerator / 10 != 0)
		{
			*numerator = *numerator % 10;
			*denominator /= 10;
			foundCommonDigit = 1;
		}

		else if (*numerator % 10 == *denominator / 10 && *numerator % 10 != 0)
		{
			*numerator /= 10;
			*denominator = *denominator % 10;
			foundCommonDigit = 1;
		}

		else if (*numerator % 10 == *denominator % 10 && *numerator % 10 != 0)
		{
			*numerator /= 10;
			*denominator /= 10;
			foundCommonDigit = 1;
		}

		return foundCommonDigit;
	}

	void reduceFraction(int *numerator, int *denominator)
	{
		int hcf = 1;
		list<int> numeratorFactors, denominatorFactors;

		while (hcf)
		{
			numeratorFactors = getFactors(*numerator);
			denominatorFactors = getFactors(*denominator);
			hcf = shareFactors(numeratorFactors, denominatorFactors);
			if (hcf != 0)
			{
				*numerator /= hcf;
				*denominator /= hcf;
			}
		}

		return;
	}

	list<int> getFactors(int number)
	{
		list<int> factors;

		for (int i = 2; i <= number; i++)
		{
			if (number % i == 0)
			{
				factors.push_back(i);
			}
		}

		return factors;
	}

	int shareFactors(list<int> numeratorFactors, list<int> denominatorFactors)
	{
		int hcf = 0;
		list<int>::iterator jter;

		numeratorFactors.merge(denominatorFactors);

		for (list<int>::iterator iter = numeratorFactors.begin(); iter != numeratorFactors.end(); iter++)
		{
			jter = iter;
			jter++;
			if (*iter == *jter)
			{
				hcf = *(iter);
			}
		}

		return hcf;
	}
};
