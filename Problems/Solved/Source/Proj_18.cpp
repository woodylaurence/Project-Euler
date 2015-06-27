/*
 * Proj_18.cpp
 *
 *  Created on: Oct 28, 2012
 *      Author: Laurence
 *
 *      Problem: Find maximal sum by traveling from top of triangle to base
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#define NUM_LINES 15

using namespace std;				// This might not be the best idea since if any variable is named the same thing as a function included in std, it will not be used.

class Prob18
{
	int solve(void)
	{
		int tmpMaxNumber = 0;
		vector<int> *triangle, cumulTotal;

		triangle = new vector<int> [NUM_LINES];

		readInTriangle(triangle);

		cumulTotal.push_back(triangle[0].front());

		for (int i = 1; i < NUM_LINES; i++)
		{
			getTotalNextLine(&cumulTotal, triangle[i]);
		}

		for (int i = 0; i < NUM_LINES; i++)
		{
			if (cumulTotal.at(i) > tmpMaxNumber)
			{
				tmpMaxNumber = cumulTotal.at(i);
			}
		}

		cout << "Maximum Sum: " << tmpMaxNumber << endl;

		return 0;
	}

	void readInTriangle(vector<int> *tmpTriangle)
	{
		int tmp;
		ifstream *input;
		string buffer;
		stringstream sstream;

		input = new ifstream("triangle_15.txt");
		if (input->is_open())
		{
			for (int i = 0; i < NUM_LINES; i++)
			{
				getline(*input, buffer);
				sstream.clear();
				sstream.str(buffer);

				while(sstream >> tmp)
				{
					tmpTriangle[i].push_back(tmp);
				}
			}
		}

		else
		{
			cout << "Sorry, the file could not be opened." << endl << "Exiting..." << endl;
		}

		return;
	}

	void getTotalNextLine(vector<int> *tmpCumulTotal, vector<int> tmpLine)
	{
		int lineLength, tmpLastElement, tmp1, tmp2;
		vector<int> previousLine;

		for (vector<int>::iterator iter = tmpCumulTotal->begin(); iter != tmpCumulTotal->end(); iter++)
		{
			previousLine.push_back(*iter);
		}

		lineLength = (int) tmpLine.size();
		tmpLastElement = tmpCumulTotal->back();					// Have used this since I'm not sure that tmpCumulTotal->push_back(tmpCumulTotal->back() + tmpLine.back()) will work, since push_back will probably create an empty element first (becoming the new back element)

		tmpCumulTotal->front() += tmpLine.front();
		tmpCumulTotal->push_back(tmpLastElement + tmpLine.back());

		for (int i = 1; i < lineLength - 1; i++)
		{
			tmp1 = previousLine.at(i - 1) + tmpLine.at(i);
			tmp2 = previousLine.at(i) + tmpLine.at(i);

			if (tmp1 >= tmp2)
			{
				tmpCumulTotal->at(i) = tmp1;
			}

			else
			{
				tmpCumulTotal->at(i) = tmp2;
			}
		}

		return;
	}

	/*void printLine(vector<int> tmpLine)
	{
		for (vector<int>::iterator iter = tmpLine.begin(); iter != tmpLine.end(); iter++)
		{
			cout << *iter << "\t";
		}

		cout << endl;

		return;
	}*/
};
