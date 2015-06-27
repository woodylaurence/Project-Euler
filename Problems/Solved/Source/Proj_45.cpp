/*
 * Proj_45.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <math.h>

using namespace std;

class Prob45
{
	int main(void)
	{
		int i=285, done=0, x = 0;
		double n_5, n_6;

		while(!done)
		{
			i++;
			x = 0.5*i*(i+1);
			n_5 = (sqrt((24*(double) x) + 1) + 1)/6.0;
			n_6 = 0.25*(sqrt((8*(double) x) + 1) + 1);
			if (fmod(n_5, 1.0) == 0 && fmod(n_6, 1.0) == 0) done=1;
		}

		cout << "Next triangluar, pentagonal and hexagonal number is " << x << endl;

		return 0;
	}
};
