/*
 * Proj_25.cpp
 *
 *  Created on: Aug 17, 2012
 *      Author: Laurence
 *
 *      Problem: What is the first term in the Fibonacci sequence to contain 1000 digits?
 *
 *      NOTE: REQUIRES 'bigInt.cpp' TO RUN
 *
 *      NOTE : FIBONACCI TERM F_N, THE ANSWER IS N NOT F_N.
 */

#include "BigInt.hpp"

using namespace std;

class Prob25
{
	int main(void)
	{
		BigInt f_n, f_n1, f_n2, tmp1, tmp2;
		int n = 1;


		f_n = 1;
		f_n1 = 0;
		f_n2 = 0;

		while (f_n.getNumDigits() < 1000)
		{
			n++;
			tmp1 = f_n;
			tmp2 = f_n1;

			f_n1 = tmp1;
			f_n2 = tmp2;
			f_n = f_n1 + f_n2;
		}

		cout << "First Fibonnaci number to reach 1000 digits is F_" << n << endl;
		return 0;
	}
};
