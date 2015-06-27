/*
 * Proj_99.cpp
 *
 *  Created on: Apr 15, 2013
 *      Author: Laurence
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Prob99
{
	int main(void)
	{
		cout << "Greatest base/exponent pair is on line " << readInFileAndFindGreatestLine() << endl;

		return 0;
	}

	int readInFileAndFindGreatestLine()
	{
		int lineNumber = 0, greatestLineNumber = 1, tmpGreatestExp = 0;
		double tmpBase, tmpExp;
		ifstream input;
		string str_base, str_exp;

		input.open("base_exp.txt", ifstream::in);

		if (input.is_open())
		{
			while (!input.eof())
			{
				lineNumber++;
				getline(input, str_base, ',');
				getline(input, str_exp);
				tmpBase = (double)atoi(str_base.c_str());
				tmpExp = (double)atoi(str_exp.c_str());
				tmpExp *= log10(tmpBase);
				if (tmpExp >= tmpGreatestExp)
				{
					greatestLineNumber = lineNumber;
					tmpGreatestExp = tmpExp;
				}
			}
		}

		return greatestLineNumber;
	}
};
