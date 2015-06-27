/*
 * Proj_9.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define NUM_PRIMES 10001

class Prob9
{
	int main(void)
	{
		int n, answer;
		double m = 0.0;

		for (n = 1; n <= 22; n++)
		{
			m = -0.5*(double)n + 0.5*sqrt((double)n*n + 2000);
			cout << "m = " << m << ", n = " << n << endl;
			if (fmod(m,1.0) == 0) break;
		}

		answer = (m*m*m*m - n*n*n*n)*(2*m*n);

		cout << "abc = " << answer << endl;
		return 0;
	}
};
