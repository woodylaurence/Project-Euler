/*
 * Proj_57.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Laurence
 *
 *      Problem: Find how many times numerator has more digits than denominator in the continued fraction of sqrt(2) in the first 1000 iterations
 *
 *      NB. This is using the very useful formula that nth numerator, h_n = a_n*h_n-1 + h_n-2 and nth denominator k_n = a_n*k_n-1 + k_n-2 where a_n = 1 for n = 0 and a_n = 2 for n > 0
 */

#include <iostream>
#include "BigInt.hpp"

class Prob57
{
	int main(void)
	{
		BigInt h_n, h_n1 = 1, h_n2 = 1, k_n, k_n1 = 1, k_n2 = 0, a_n = 2;
		int numMoreDigits = 0;			// Start at h_1 since then a_n is always 2 and don't have to worry about a_0

		for (int i = 1; i <= 1000; i++)
		{

			h_n = a_n*h_n1 + h_n2;
			k_n = a_n*k_n1 + k_n2;

			h_n2 = h_n1;
			k_n2 = k_n1;
			h_n1 = h_n;
			k_n1 = k_n;

			if (h_n.getNumDigits() > k_n.getNumDigits())
			{
				numMoreDigits++;
			}
		}

		std::cout << "Answer: " << numMoreDigits << std::endl;

		return 0;
	}
};
