/*
 * Proj_65.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: Laurence
 *
 *      Problem: Find sum of digits of numerator for 100th convergent of continued fraction for e
 */

#include <iostream>
#include "BigInt.hpp"

class Prob65
{
	int main(void)
	{
        throw "Needs reimplementing";
		/*BigInt h_n, h_n1 = 2, h_n2 = 1;
		int sumDigits, *a_n;

		a_n = new int [3];
		a_n[0] = 1;
		a_n[2] = 1;

		for (int i = 0; i < 99; i++)				// Goes to 99 because h_0 = 2 is the first convergent, so need 99 more.
		{
			a_n[1] = 2*(i/3 + 1);

			h_n = h_n1 * a_n[i%3] + h_n2;
			h_n2 = h_n1;
			h_n1 = h_n;
			std::cout << "h_n = "; h_n.printValue(); std::cout << std::endl;
		}

		std::cout << "Sum of 100th convergent digits: " << h_n.sumDigits() << std::endl;

		return 0;*/
	}
};
