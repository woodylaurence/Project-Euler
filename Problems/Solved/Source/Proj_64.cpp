/*
 * Proj_64.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: Laurence
 *
 *      Problem: Find number of square roots (ÃN) for N ² 10,000 with an odd period in it's continued fraction form
 *
 *      Theory: ÃN = a_0 + 1/(a_1 + 1/(a_2 + 1/(a_3 + ...)))
 *      		a_0 = floor[ÃN]
 *      		m_0 = 0
 *      		d_0 = 1
 *      		m_(n+1) = d_n * a_n - m_n
 *      		d_(n+1) = (S - m_(n+1)^2)/d_n
 *      		a_(n+1) = floor[(a_0 +m_(n+1))/d_(n+1)]
 *
 *      		Found link to Alexandra Ioana Gliga paper, proves that the repating pattern a_1, a_2,...,a_n, 2a_0
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Prob64
{
	int main(void)
	{
		int numOddPeriod = 0, a_0, a_n, m_n, d_n;
		double sqrtNum;
		vector<int> a_vector;

		for (int N = 1; N < 10000; N++)
		{
			sqrtNum = sqrt(N);

			if (fmod(sqrtNum, 1.0) != 0)
			{
				a_vector.clear();

				// Define starting constants
				a_0 = (int)sqrtNum;
				m_n = 0;
				d_n = 1;
				a_n = a_0;
				do
				{
					m_n = d_n * a_n - m_n;
					d_n = (int)((double)(N - m_n*m_n)/(double)d_n);
					a_n = (int)((double)(a_0 + m_n)/(double)d_n);
					a_vector.push_back(a_n);

				} while ((a_n != 2*a_0));

				if (a_vector.size() % 2 == 1)
				{
					numOddPeriod++;
				}
			}
		}

		cout << "Number with odd periods: " << numOddPeriod << endl;

		return 0;
	}
};
