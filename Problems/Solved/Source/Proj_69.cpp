/*
 * Proj_69.cpp
 *
 *  Created on: Aug 19, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <vector>
#include <list>
#include "Math.hpp"

using namespace std;

class Prob_69
{
	int main(void)
	{
		int n = 0;
		double ratio = 0, phi;
		vector<int> tmpPrimeFactors, primeNumbers;

		setUpPrimes(&primeNumbers);

		for (int i = 2; i <= 100000; i++)
		{
			phi = 1;

			if (i % 10000 == 0)
			{
				cout << i << endl;
			}
			tmpPrimeFactors = getPrimeFactors(i);

			for (vector<int>::iterator iter = tmpPrimeFactors.begin(); iter != tmpPrimeFactors.end(); iter++)
			{
				phi *= 1.0 - 1.0/(double) *iter;
			}
			phi *= i;

			if (((double) i/phi) > ratio)
			{
				ratio = i/phi;
				n = i;
			}
		}

		cout << "Value of n which gives highest value of n / phi(n): " << n << endl;

		return 0;
	}

	void setUpPrimes(vector<int>* primeNumbers)
	{

	}

	/*vector<int> getPrimeFactors(int number, vector<int>* primeNumbers)
	{
		vector<int> primeFactors;
		vector<int>::iterator iter;
		list<int> lists;

		iter = primeNumbers->begin();

		while (number > 1)
		{
			//cout << "Beginning: number = " << number << ", iter = " << *iter << endl;
			if (number % *iter == 0)
			{
				number /= *iter;
				// Ensures no duplicates
				if (primeFactors == (vector<int>)NULL || primeFactors.back() != *iter)
				{
					primeFactors.push_back(*iter);
				}
			}

			else
			{
				cout << "*iter = " << *iter << endl;

				if (*iter == primeNumbers->back())
				{
					primeNumbers->push_back(getNextPrime(primeNumbers->back()));
				}

				cout << "Before: iter = " << *iter;
				iter++;
				cout << "\tAfter: iter = " << *iter << endl;
			}
		}

		return primeFactors;
	}*/

	vector<int> getPrimeFactors(int number)
	{
		int primeNumber = 2;
		vector<int> primeFactors;

		while (number > 1)
		{
			if (number % primeNumber == 0)
			{
				number /= primeNumber;
				if (primeFactors == (vector<int>)NULL || primeFactors.back() != primeNumber)
				{
					primeFactors.push_back(primeNumber);
				}
			}

			else
			{
				primeNumber = getNextPrime(primeNumber);
			}
		}

		return primeFactors;
	}

	int getNextPrime(int previousPrime)
	{
		if (previousPrime == 2)
		{
			return 3;
		}

		while(!Math::isPrime(previousPrime += 2));

		return previousPrime;
	}
};
