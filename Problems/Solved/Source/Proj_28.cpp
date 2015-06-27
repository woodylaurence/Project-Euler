/*
 * Proj_28.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Prob28
{
	int main(void)
	{
		int number = 1;

		for (int i = 3; i<= 1001; i+=2)
		{
			number += 2*(2*i*i - 3*i + 3);
		}

		cout << number << endl;

		return 0;
	}
};
