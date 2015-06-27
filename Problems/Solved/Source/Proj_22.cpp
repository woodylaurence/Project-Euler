/*
 * Proj_22.cpp
 *
 *  Created on: Aug 17, 2012
 *      Author: Laurence
 *
 *      Problem: "What is the total of all the name scores in the file of first names?"
 */

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class Prob22
{
	int main(void)
	{
		int i = 0, sumValue = 0;
		list<string> namesList, orderedNamesList;

		namesList = readInFile();
		orderedNamesList = alphabetize(namesList);

		for (list<string>::iterator iter = orderedNamesList.begin(); iter != orderedNamesList.end(); iter++)
		{
			i++;
			sumValue += (i*stringToValue(*iter));
		}

		cout << "Total value: " << sumValue << endl;
		return 0;
	}

	list<string> alphabetize(list<string> namesList)
	{
		int listSize;
		string tmpName;
		list<string> orderedNamesList;
		list<string>::iterator tmpIter;

		listSize = (int)namesList.size();

		for (int i = 0; i < listSize; i++)
		{
			tmpName = "ZZZZZ";
			for (list<string>::iterator iter = namesList.begin(); iter != namesList.end(); iter++)
			{
				if (*iter <= tmpName)
				{
					tmpName = *iter;
					tmpIter = iter;
				}
			}

			orderedNamesList.push_back(tmpName);
			namesList.erase(tmpIter);
		}

		return orderedNamesList;
	}

	list<string> readInFile()
	{
		list<string> namesList;
		ifstream inputFile;
		string tmpStr, buf;

		inputFile.open("namesList.txt");

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
};
