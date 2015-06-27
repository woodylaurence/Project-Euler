/*
 * Utilities.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Laurence
 */

#include "Utilities.hpp"

#include <iostream>
#include <algorithm>

vector<int> Utilities :: getDigits(int num)
{
	return getDigits((long long)num);
}

vector<int> Utilities :: getDigits(long long num)
{
	vector<int> digits;

	while (num > 0)
	{
		digits.push_back(num % 10);
		num = num /= 10;
	}
	std::reverse(digits.begin(), digits.end());
	return digits;
}

int Utilities :: getSumDigits(int num)
{
	int sum = 0;
	vector<int> digits = getDigits(num);

	for (vector<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
	{
		sum += *iter;
	}

	return sum;
}

int Utilities :: getNumDigits(int num)
{
	return int(getDigits(num).size());
}

void Utilities :: printVectorAsNumber(vector<int> digits)
{
	for (vector<int>::iterator iter = digits.begin(); iter != digits.end(); iter++)
	{
		cout << *iter;
	}
}

int Utilities :: digitsToInt(vector<int> digits)
{
	int number = 0, exponent = 1;

	//Put check here to ensure can convert digits to int

	for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++)
	{
		number += (*iter)*exponent;
		exponent *= 10;
	}

	return number;
}

long long Utilities :: digitsToLongLong(vector<int> digits)
{
	long long number = 0;
	long long exponent = 1;

	//Put check here to ensure can convert digits to long

	for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++)
	{
		number += (long long)(*iter)*exponent;
		exponent *= 10;
	}

	return number;
}

bool Utilities :: isPanditigalNumber(int n, int num, bool includeZero)
{
	return isPanditigalNumber(n, getDigits(num), false);
}

bool Utilities :: isPanditigalNumber(int n, long long num, bool includeZero)
{
	return isPanditigalNumber(n, getDigits(num), false);
}

bool Utilities :: isPanditigalNumber(int n, vector<int> digits, bool includeZero)
{
	if (digits.size() != n) return false;

	if (n > 9) cout << "Currently cannot do this" << endl;

	sort(digits.begin(), digits.end());

	vector<int> pandigitalVector;
	if (includeZero) pandigitalVector.push_back(0);
	for (int i = 1; i <= n; i++) pandigitalVector.push_back(i);

	for (vector<int>::iterator iter = pandigitalVector.begin(), jter = digits.begin(); iter != pandigitalVector.end(); iter++, jter++)
	{
		if (*iter != *jter) return false;
	}

	return true;
}
