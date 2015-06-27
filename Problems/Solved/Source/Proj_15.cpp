/*
 * Proj_15.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Laurence
 */

#include <iostream>
#include <vector>

using namespace std;

int SQUARE_SIZE = 20;

class Prob15
{
	int solve(void)
	{
		vector<long long> diagonal;

		diagonal.push_back(1);

		for (int i = 0; i < 2*SQUARE_SIZE + 1; i++)
		{
			cout << "Line: ";
			for (vector<long long>::iterator iter = diagonal.begin(); iter != diagonal.end(); iter++)
			{
				cout << *iter << " " << " ";
			}
			cout << endl;
			getTotalDiagonal(&diagonal, (i < SQUARE_SIZE) ? true : false);
		}

		if (diagonal.size() == 1)
		{
			cout << "Number of paths: " << diagonal.front() << endl;
		}

		return 0;
	}

	void getTotalDiagonal(vector<long long>* cumulDiagonal, bool lineSizeIncreasing)
	{
		int lineLength = 0;
		vector<long long> previousLine;

		for (vector<long long>::iterator iter = cumulDiagonal->begin(); iter != cumulDiagonal->end(); iter++)
		{
			previousLine.push_back(*iter);
		}

		cumulDiagonal->clear();

		if (lineSizeIncreasing)
		{
			lineLength = (int)previousLine.size();

			cumulDiagonal->push_back(1);

			for (int i = 1; i < lineLength; i++)
			{
				cumulDiagonal->push_back(previousLine.at(i - 1) + previousLine.at(i));
			}

			cumulDiagonal->push_back(1);
		}
		else
		{
			lineLength = (int)previousLine.size() - 1;

			for (int i = 0; i < lineLength; i++)
			{
				cumulDiagonal->push_back(previousLine.at(i) + previousLine.at(i + 1));
			}
		}

		return;
	}
};
