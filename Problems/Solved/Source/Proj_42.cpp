/*
 * Proj_42.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <math.h>

using namespace std;

class Prob42
{
	int main(void)
	{
		int numTriangleWords = 0, stringValue;
		list<string> wordsList;

		wordsList = readInFile();

		for (list<string>::iterator iter = wordsList.begin(); iter != wordsList.end(); iter++)
		{
			stringValue = stringToValue(*iter);
			if (checkTriangleNumber(stringValue))
			{
				numTriangleWords++;
			}
		}

		cout << "Number of triangle words: " << numTriangleWords << endl;
		return 0;
	}

	list<string> readInFile()
	{
		list<string> namesList;
		ifstream inputFile;
		string tmpStr, buf;

		inputFile.open("wordsList.txt");

		if (inputFile.is_open())
		{
			while(!inputFile.eof())
			{
				getline(inputFile, buf, '"');
				getline(inputFile, tmpStr, '"');
				getline(inputFile, buf, ',');
				namesList.push_back(tmpStr);
			}
		}

		else
		{
			cout << "Error, could not open file." << endl;
		}

		return namesList;
	}

	int stringToValue(string tmpString)
	{
		int value = 0 , numChars;
		char *name;

		numChars = (int)tmpString.size();
		name = (char*) malloc(numChars*sizeof(char));
		strcpy(name, tmpString.c_str());

		for (int i = 0; i < numChars; i++)
		{
			value += ((int)name[i] - 64); 				/* 64 is because 'A' has ASCII value of 65 */
		}

		return value;
	}

	int checkTriangleNumber(int number)					/* T_n = 0.5*n*(n+1) --> n^2 + n - 2*T_n -- > -1 + sqrt(1 + 8*T_n)*/
	{
		int isTriangleNumber = 1;
		double tmpNumber;

		tmpNumber = (double)number;

		if (fmod(0.5*(-1 + sqrt(1 + 8*tmpNumber)), 1.0) != 0)
		{
			isTriangleNumber = 0;
		}

		return isTriangleNumber;
	}
};
