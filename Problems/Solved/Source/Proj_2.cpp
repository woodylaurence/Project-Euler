/*
 * Proj_2.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Laurence
 *
 *      Problem : "By considering the terms in the Fibonacci sequence whose values
 *      do not exceed four million, find the sum of the even-valued terms."
 */

#include <iostream>

using namespace std;

class Prob2
{
	int solve(void)
	{
		int fib_num1, fib_num2, fib_num3, total;

		fib_num3 = total = 0;
		fib_num1 = fib_num2 = 1;

		do
		{
			fib_num3 = fib_num1 + fib_num2;
			if ((fib_num3 % 2) == 0) total += fib_num3;
			fib_num1 = fib_num2;
			fib_num2 = fib_num3;
		} while (fib_num3 <= 4000000);

		cout << "Sum = " << total << "\n";

		return 0;
	}
};
