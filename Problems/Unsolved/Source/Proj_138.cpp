/*
 * Proj_138.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: Laurence
 *
 *      h = sqrt((b/2)^2 + (b ± 1)^2) = sqrt(5/4(b^2) ± 2b + 1)
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct triangle
{
	int L, b, h, area;
};

bool operator < (triangle tri1, triangle tri2)
{
	return (tri1.L < tri2.L);
}
class Prob138
{
int solve(void)
{
	int sumL = 0;
	double b = 2, L;
	triangle tmp;
	vector<triangle> triangles;

	while (triangles.size() < 24)
	{
		L = sqrt(5*b*b/4 + 2*b + 1);
		if (fmod(L, 1.0) == 0)
		{
			cout << "b = " << b << ", L = " << L << endl;
			tmp.L = (int)L;
			tmp.b = b;
			tmp.h = b + 1;
			tmp.area = (b*b + b)/2;
			triangles.push_back(tmp);
		}
		L = sqrt(5*b*b/4 - 2*b + 1);
		if (fmod(L, 1.0) == 0)
		{
			cout << "b = " << b << ", L = " << L << endl;
			tmp.L = (int)L;
			tmp.b = b;
			tmp.h = b - 1;
			tmp.area = (b*b - b)/2;
			triangles.push_back(tmp);
		}
		b += 2;
	}

	sort(triangles.begin(), triangles.end());
	for (int i = 0; i < 12; i++)
	{
		sumL += triangles.at(i).L;
	}

	cout << "SumL = " << sumL << endl;

	return 0;
}
};
