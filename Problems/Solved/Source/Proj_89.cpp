/*
 * Proj_89.cpp
 *
 *  Created on: Apr 8, 2013
 *      Author: Laurence
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Prob89
{
	int main(void)
	{
		vector< vector<char> > listOfNumbers;
		vector<char> tempRomanNumber;
		int lettersSaved = 0;

		listOfNumbers = readInNumbers();

		for (vector< vector<char> >::iterator iter = listOfNumbers.begin(); iter != listOfNumbers.end(); iter++)
		{
			tempRomanNumber = latinToRoman(romanToLatin(*iter));

			lettersSaved += (int)iter->size() - (int)tempRomanNumber.size();
		}

		cout << "Saved " << lettersSaved << " letters." << endl;

		return 0;
	}

	int romanToLatin(vector<char> romanNumeral)
	{
		char tmpNumeral;
		int latinNumber = 0, rNSize;
		vector<int> latinNumerals;

		romanNumeral.push_back('Z');

		rNSize = (int)romanNumeral.size();

		for (int i = 0; i < rNSize; i++)
		{
			tmpNumeral = romanNumeral.at(i);

			switch(tmpNumeral)
			{
				case 'M':
				{
					latinNumerals.push_back(1000);
				} break;
				case 'D':
				{
					latinNumerals.push_back(500);
				} break;
				case 'C':
				{
					latinNumerals.push_back(100);
				} break;
				case 'L':
				{
					latinNumerals.push_back(50);
				} break;
				case 'X':
				{
					latinNumerals.push_back(10);
				} break;
				case 'V':
				{
					latinNumerals.push_back(5);
				} break;
				case 'I':
				{
					latinNumerals.push_back(1);
				} break;
				case 'Z':
				{
					latinNumerals.push_back(0);
				} break;
				default:
				{
					cout << "Something went wrong there!" << endl;
					exit(EXIT_FAILURE);
				}
			}
		}

		for (int i = 0; i < rNSize - 1; i++)
		{
			if (latinNumerals.at(i) < latinNumerals.at(i+1))
			{
				latinNumber -= latinNumerals.at(i);
			}
			else
			{
				latinNumber += latinNumerals.at(i);
			}
		}

		return latinNumber;
	}

	vector<char> latinToRoman(int latinNumeral)
	{
		vector<char> romanNumeral;
		vector<int> romanDenominations;
		int tmpLatinNumeral = latinNumeral, i = 0, tmpRomanDivisor;


		// Breaks the Latin number into the base Roman denominations
		while (tmpLatinNumeral > 0)
		{
//			tmpRomanDivisor = romanDivisors.at(i);
			if (tmpLatinNumeral >= tmpRomanDivisor)
			{
				tmpLatinNumeral -= tmpRomanDivisor;
				romanDenominations.push_back(tmpRomanDivisor);
			}
			else
			{
				i++;
			}
		}

		/*for (vector<int>::iterator iter = romanDenominations.begin(); iter != romanDenominations.end(); iter++)
		{
			cout << *iter << "\t";
		}
		cout << endl;*/

		for (vector<int>::iterator iter = romanDenominations.begin(); iter != romanDenominations.end(); iter++)
		{
			switch(*iter)
			{
				case 1000:
				{
					romanNumeral.push_back('M');
				} break;
				case 900:
				{
					romanNumeral.push_back('C');
					romanNumeral.push_back('M');
				} break;
				case 500:
				{
					romanNumeral.push_back('D');
				} break;
				case 400:
				{
					romanNumeral.push_back('C');
					romanNumeral.push_back('D');
				} break;
				case 100:
				{
					romanNumeral.push_back('C');
				} break;
				case 90:
				{
					romanNumeral.push_back('X');
					romanNumeral.push_back('C');
				} break;
				case 50:
				{
					romanNumeral.push_back('L');
				} break;
				case 40:
				{
					romanNumeral.push_back('X');
					romanNumeral.push_back('L');
				} break;
				case 10:
				{
					romanNumeral.push_back('X');
				} break;
				case 9:
				{
					romanNumeral.push_back('I');
					romanNumeral.push_back('X');
				} break;
				case 5:
				{
					romanNumeral.push_back('V');
				} break;
				case 4:
				{
					romanNumeral.push_back('I');
					romanNumeral.push_back('V');
				} break;
				case 1:
				{
					romanNumeral.push_back('I');
				} break;
				default:
				{
					cout << "Something went wrong there!" << endl;
					exit(EXIT_FAILURE);
				}
			}
		}

		return romanNumeral;
	}

	vector< vector<char> > readInNumbers()
	{
		vector< vector<char> > romanNumbers;
		ifstream inputFile;
		string buff;

		inputFile.open("roman.txt", ifstream::in);

		while (!inputFile.eof())
		{
			getline(inputFile, buff);
			vector<char> tmpRomanNumber(buff.begin(), buff.end());
			romanNumbers.push_back(tmpRomanNumber);
		}

		return romanNumbers;
	}
};
