/*
 * Proj_51.cpp
 *
 *  Created on: Apr 24, 2013
 *      Author: Laurence
 *
 *      Problem: Find the smallest prime number such that replacing some number of its digits with the same number yields a family of 8 other prime numbers
 *      		 e.g. 56**3: 56003, 56113, 56333, 56443, 56663, 56773 and 56993 are all prime numbers.
 */

#include <iostream>
#include <vector>

#include "Math.hpp"

using namespace std;

class Prob51
{
	int solve(void)
	{
		bool foundAnswer = false;
		int primeNumber = 13, numDigits, numPrimesFound;

		while(!foundAnswer)
		{
			numPrimesFound = 0;
			numDigits = getNumDigits(primeNumber);

			//No point in checking whether replacing all the digits produces primes since we only have 9 digits (not counting the trivial 000000 etc) to choose from and
			//4 of them will be even! so no way we can have 8 primes from this.
			for (int i = 1; i < numDigits - 1; i++)
			{

			}

			primeNumber = Math::getNextPrime(primeNumber);
		}

		//cout << "Answer: " << primeNumber << endl;

		return 0;
	}

	vector<int> convertToDigits(int number)
	{
		vector<int> digitsR, digits;

		while (number > 0)			//This creates vector of digits which are backwards
		{
			digitsR.push_back(number%10);
			number /= 10;
		}

		for (vector<int>::reverse_iterator iter = digitsR.rbegin(); iter != digitsR.rend(); iter++)			//This reverse the above vector to get digits in right order
		{
			digits.push_back(*iter);
		}

		return digits;
	}

	int convertToNumber(vector<int> digits)
	{
		int multiplier = 1, number = 0;

		for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); iter++)
		{
			number += (*iter)*multiplier;
			multiplier *= 10;
		}

		return number;
	}

	int getNumDigits(int number)
	{
        //maybe need to do a check that number of digits isn't too large for int
		return (int)convertToDigits(number).size();
	}

	vector< vector<int> > getDigitsToReplace(int numDigits, int numDigitsToReplace)
	{
		vector< vector<int> > digits;
		vector<int> tmpDigits;

		getDigitsToReplace(numDigits-1, numDigitsToReplace-1);

		return digits;
	}

	bool replaceDigits(int *number, vector<int> digitsToReplace, int numToReplaceWith)
	{
		bool numberIsSame = true;
		vector<int> digits;

		digits = convertToDigits(*number);

		for (vector<int>::iterator iter = digitsToReplace.begin(); iter != digitsToReplace.end(); iter++)
		{
			numberIsSame &= (digits.at(*iter) == numToReplaceWith);
			digits.at(*iter) = numToReplaceWith;
		}

		if (numberIsSame)
		{
			return false;
		}
		else
		{
			*number = convertToNumber(digits);
			return true;
		}
	}
};
