/*
 * Proj_5.cpp
 *
 *  Created on: Jun 17, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Prob5
{
	int main(void)
	{
		int number, i, flag=0;

		number = 2*3*5*7*11*13*17*19;

		while (!flag)
		{
			for (i = 3; i <= 20; i++)
			{
				if (number % i != 0)
				{
					break;
				}
			}

			if (i == 21) flag = 1;
			else number+=2;
		}

		cout << "LCM is: " << number << endl;
		return 0;
	}
};
