/*
 * Proj_34.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 *
 *      Problem: Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 */

#include <iostream>
#include <list>

using namespace std;

class Prob34
{
	int main(void)
	{
		int sum = 0;

		for (int i = 3; i < 2540160; i++)
		{
			if (i == getSumFactorialDigits(i))
			{
				sum += i;
				//cout << i << endl;
			}
		}

		cout << "Sum of all numbers equal to sum of digit factorials: " << sum << endl;
		return 0;
	}

	int getSumFactorialDigits(int number)
	{
		int sumFactorialDigits = 0;
		list<int> digits;

		while (number != 0)
		{
			digits.push_front(number % 10);
			number /= 10;
		}

		for (list<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
		{
			sumFactorialDigits += factorial(*iter);
		}

		return sumFactorialDigits;

	}

	int factorial(int number)
	{
        if (number < 0) throw "Number cannot be below 0";
        return (number <= 1) ? 1 : number * factorial(number - 1);
	}
};
