/*
 * Proj_3.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Laurence
 *
 *      Problem : "What is the largest prime factor of the number 600851475143 ?"
 */

#include <iostream>
#include <cmath>

using namespace std;

class Prob3
{
	int main(void)
	{
		double number, tmp = 0.0, i=2;
		int prime_int, sqrt_number;

		number = 600851475143;
		sqrt_number = int (sqrt(number));

		while (i <= number/2.0)
		{
			if (fmod(number, double(i)) == 0)
			{
				tmp = number / double (i);
				if (check_prime(tmp)) break;
			}
			i++;
		}

		prime_int = int (tmp);
		cout << "Highest Prime Factor = " << tmp << "\n";
		return 0;
	}

	int check_prime(double tmpNumber)
	{
		int prime=1;
		double i=2, sqrt_tmpNumber;

		sqrt_tmpNumber = sqrt(tmpNumber);

		while (i <= sqrt_tmpNumber && prime == 1)
		{
			if (fmod(tmpNumber, i) == 0) prime = 0;
			i += 1;
		}

		return prime;
	}
};
