/*
 * Prob32.cpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#include "Prob32.hpp"
#include "Utilities.hpp"

#include <iostream>

void Prob32 :: solve()
{
	cout << "Solving Problem 32..." << endl;

	long long answer = 0;
	bool products[100000] = {0};

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10000; j++)
		{
			vector<int> digits = concatonateNumbers(i, j, i*j);
			if (Utilities::isPanditigalNumber(9, digits, false)) products[i*j] = true;
		}
	}

	for (int i = 10; i < 100; i++)
	{
		for (int j = 1; j < 1000; j++)
		{
			vector<int> digits = concatonateNumbers(i, j, i*j);
			if (Utilities::isPanditigalNumber(9, digits, false)) products[i*j] = true;
		}
	}

	for(int i = 0; i < 100000; i++)
	{
		if (products[i]) answer += i;
	}

	cout << "Answer: " << answer << endl;
}

vector<int> Prob32 :: concatonateNumbers(int multiplcand, int multipler, int product)
{
	vector<int> multiplicandDigits = Utilities::getDigits(multiplcand);
	vector<int> multiplierDigits = Utilities::getDigits(multipler);
	vector<int> productDigits = Utilities::getDigits(product);

	productDigits.insert(productDigits.end(), multiplicandDigits.begin(), multiplicandDigits.end());
	productDigits.insert(productDigits.end(), multiplierDigits.begin(), multiplierDigits.end());

	return productDigits;
}
