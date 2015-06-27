/*
 * Prob38.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Laurence
 */

#include "Prob38.hpp"
#include <iostream>
#include <algorithm>
#include "Utilities.hpp"

void Prob38 :: solve()
{
	long long num, largestNum = 0;
	vector<int> number;
	for (int i = 9999; i > 4999; i--)
	{
		number.clear();
		number.push_back(i);
		number.push_back(i * 2);

		num = Utilities::digitsToLongLong(convertMultiDigitsToSingleDigitVector(number));
		if (Utilities::isPanditigalNumber(9, num, false) && num > largestNum)
		{
			largestNum = num;
		}
	}

	cout << "Answer: " << largestNum << endl;
}

string Prob38 :: getProblemName()
{
    return "Problem 38";
}

vector<int> Prob38 :: convertMultiDigitsToSingleDigitVector(vector<int> digits)
{
	vector<int> singleDigitVector;

	for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++)
	{
		vector<int> tmpDigits = Utilities::getDigits(*iter);
		for (vector<int>::reverse_iterator jter = tmpDigits.rbegin(); jter != tmpDigits.rend(); jter++)
		{
			singleDigitVector.push_back(*jter);
		}
	}

	reverse(singleDigitVector.begin(), singleDigitVector.end());
	return singleDigitVector;
}

