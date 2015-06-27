/*
 * Proj_30.cpp
 *
 *  Created on: Aug 17, 2012
 *      Author: Laurence
 *
 *      Problem: Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 *
 *      NOTE: Consider 7 digits, maximum number is 9,999,999, sum of these digits to 5th power = 7*9^5 = 413343 a six digit number, thus no 7 digit number can be
 *      	  represented as sum of its digits to 5th power. Consider 6 digits, 6*9^5 = 354294, thus upper limit need to go to is 354294 since any number larger than
 *      	  this cannot be represented as sum of digits to 5th power. Lower bound is 2 since 1 is ignored.
 */

#include <iostream>
#include <list>

using namespace std;

class Prob30
{
	int main(void)
	{
		int sum = 0;

		for (int i = 2; i < 354294; i++)
		{
			if (i == sumPowerDigits(i))
			{
				//cout << i << endl;
				sum += i;
			}
		}

		cout << "Sum of numbers: " << sum << endl;

		return 0;
	}

	int sumPowerDigits(int number)
	{
		int sum = 0;
		list<int> digits;

		digits = intToDigits(number);

		for (list<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
		{
			sum += (*iter)*(*iter)*(*iter)*(*iter)*(*iter);
		}

		return sum;
	}

	list<int> intToDigits(int number)
	{
		list<int> digits;

		while (number != 0)
		{
			digits.push_front(number % 10);
			number /= 10;
		}

		return digits;
	}
};
