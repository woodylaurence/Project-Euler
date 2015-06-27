/*
 * Proj_61.cpp
 *
 *  Created on: Aug 19, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <vector>
#include <algorithm>				// For next_permutation()

using namespace std;

class Prob61
{
	int main(void)
	{
		int sum = 0;
		vector< vector<int> > polygonalNumbers, permutations;
		vector<int> tmp;

		polygonalNumbers = generatePolygonalNumbers();

		/*tmp = cleanUpPolygonalNumbers(polygonalNumbers.at(2), getFirstLastDigits(polygonalNumbers.at(0).front(), false));

		cout << tmp.size() << endl;

		for (vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
		{
			cout << *iter / 100 << "\t" << *iter % 100 << endl;
		}*/


		permutations = getPermutations();
		sum = findNumbers(polygonalNumbers, permutations);

		cout << sum << endl;

		return 0;
	}

	vector< vector<int> > generatePolygonalNumbers()
	{
		vector< vector<int> > polygonalNumbers;
		vector<int> tmp;

		for (int i = 45; i <= 140; i++)				/* Generates all TRIANGLE numbers between 1000 and 9999. */
		{
			tmp.push_back(0.5*i*(i+1));
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		for (int i = 32; i <= 99; i++)				/* Generates all SQUARE numbers between 1000 and 9999. */
		{
			tmp.push_back(i*i);
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		for (int i = 26; i <= 81; i++)				/* Generates all PENTAGONAL numbers between 1000 and 9999. */
		{
			tmp.push_back(0.5*i*(3*i - 1));
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		for (int i = 23; i <= 70; i++)				/* Generates all HEXAGONAL numbers between 1000 and 9999. */
		{
			tmp.push_back(i*(2*i - 1));
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		for (int i = 21; i <= 63; i++)				/* Generates all HEPTAGONAL numbers between 1000 and 9999. */
		{
			tmp.push_back(0.5*i*(5*i - 3));
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		for (int i = 19; i <= 58; i++)				/* Generates all OCTAGONAL numbers between 1000 and 9999. */
		{
			tmp.push_back(i*(3*i - 2));
		}
		polygonalNumbers.push_back(tmp);
		tmp.clear();

		/*int i = 3;
		for (vector< vector<int> >::iterator iter = polygonalNumbers.begin(); iter != polygonalNumbers.end(); iter++)
		{
			cout << "i = " << i << endl;
			for (vector<int>::iterator jter = iter->begin(); jter != iter->end(); jter++)
			{
				cout << *jter / 100 << "\t" << *jter % 100 << endl;
			}
			cout << endl << endl;
			i++;
		}*/

		return polygonalNumbers;
	}

	vector< vector<int> > getPermutations()
	{
		vector< vector<int> > permutations;
		vector<int> numbers;

		for (int i = 0; i < 6; i++)
		{
			numbers.push_back(i);
		}

		permutations.push_back(numbers);

		while (next_permutation(numbers.begin(), numbers.end()))
		{
			permutations.push_back(numbers);
		}

		return permutations;
	}

	int findNumbers(vector< vector<int> > numbers, vector< vector<int> > permutations)
	{
		bool foundNumbers = false;
		int sum = 0;
		vector< vector<int> > vCleanedNumbers;
		vector<int> cleanedNumbers;

		cleanedNumbers.push_back(0);

		for (int i = 0; i < 5; i++)
		{
			vCleanedNumbers.push_back(cleanedNumbers);
		}

		for (vector< vector<int> >::iterator iter = permutations.begin(); iter != permutations.end() && !foundNumbers; iter++)
		{
			for (vector<int>::iterator jter = numbers.at(iter->at(0)).begin(); jter != numbers.at(iter->at(0)).end() && !foundNumbers; jter++)
			{
				cleanedNumbers = cleanUpPolygonalNumbers(numbers.at(iter->at(1)), getFirstLastDigits(*jter, false));
				vCleanedNumbers.at(0) = cleanedNumbers;
				for (vector<int>::iterator kter = vCleanedNumbers.at(0).begin(); kter != vCleanedNumbers.at(0).end() && !foundNumbers; kter++)
				{
					cleanedNumbers = cleanUpPolygonalNumbers(numbers.at(iter->at(2)), getFirstLastDigits(*kter, false));
					vCleanedNumbers.at(1) = cleanedNumbers;
					for (vector<int>::iterator lter = vCleanedNumbers.at(1).begin(); lter != vCleanedNumbers.at(1).end() && !foundNumbers; lter++)
					{
						cleanedNumbers = cleanUpPolygonalNumbers(numbers.at(iter->at(3)), getFirstLastDigits(*lter, false));
						vCleanedNumbers.at(2) = cleanedNumbers;
						for (vector<int>::iterator mter = vCleanedNumbers.at(2).begin(); mter != vCleanedNumbers.at(2).end() && !foundNumbers; mter++)
						{
							cleanedNumbers = cleanUpPolygonalNumbers(numbers.at(iter->at(4)), getFirstLastDigits(*mter, false));
							vCleanedNumbers.at(3) = cleanedNumbers;
							for (vector<int>::iterator nter = vCleanedNumbers.at(3).begin(); nter != vCleanedNumbers.at(3).end() && !foundNumbers; nter++)
							{
								cleanedNumbers = cleanUpPolygonalNumbers(numbers.at(iter->at(5)), getFirstLastDigits(*nter, false));
								vCleanedNumbers.at(4) = cleanedNumbers;
								for (vector<int>::iterator oter = vCleanedNumbers.at(4).begin(); oter != vCleanedNumbers.at(4).end() && !foundNumbers; oter++)
								{
									if (getFirstLastDigits(*oter, false) == getFirstLastDigits(*jter, true))
									{
										sum = *jter + *kter + *lter + *mter + *nter + *oter;
										foundNumbers = true;
									}
								}
							}
						}
					}
				}
			}
		}

		return sum;
	}

	// Returns the vector of numbers for specific polygon with only numbers which start with first two digits matching firstDigits
	vector<int> cleanUpPolygonalNumbers(vector<int> polygonalNumbers, int firstDigits)
	{
		vector<int> cleanedPolygonalNumbers;

		for (vector<int>::iterator iter = polygonalNumbers.begin(); iter != polygonalNumbers.end(); iter++)
		{
			if (getFirstLastDigits(*iter, true) == firstDigits)
			{
				cleanedPolygonalNumbers.push_back(*iter);
			}
		}

		return cleanedPolygonalNumbers;
	}

	// Returns first two digits of number if gettingFirst is true, else returns last two digits of number
	int getFirstLastDigits(int number, bool gettingFirst)
	{
		if (gettingFirst)
		{
			return (number / 100);
		}
		else
		{
			return (number % 100);
		}
	}
};
