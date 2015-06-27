#include <cmath>
#include <iostream>
#include "Math.hpp"

bool Math::isPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2 || num == 3) return true;

	int sqrtNum = int(sqrt(num));
	for (int i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

bool Math::isPrime(long num)
{
	if (num < 2) return false;
	else if (num == 2 || num == 3) return true;

	long sqrtNum = long(sqrt(num));
	for (long i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

bool Math::isPrime(long long num)
{
	if (num < 2) return false;
	else if (num == 2 || num == 3) return true;

	long long sqrtNum = (long long)sqrt(num);
	for (long long i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}

vector<int> Math::getPrimeFactors(int num)
{
	int factor = 2;
	vector<int> primeFactors;

	while (num > 1)
	{
		if (num % factor == 0)
		{
			num /= factor;
			if (primeFactors == (vector<int>)NULL || primeFactors.back() != factor)
			{
				primeFactors.push_back(factor);
			}
		}

		//Don't only have to check prime numbers, if we have divided by 2 as many times as we can, then when we come to divide by 4, it won't work
		else factor++;
	}

	return primeFactors;
}

vector<PrimeFactor> Math::getPrimeFactorsWithPowers(int num)
{
	int factor = 2;
	vector<PrimeFactor> primeFactors;

	while (num > 1)
	{
		if (num % factor == 0)
		{
			num /= factor;
			if (primeFactors.size() == 0 || primeFactors.back().factor != factor)
			{
				PrimeFactor primeFactor = {factor, 1};
				primeFactors.push_back(primeFactor);
			}
			else primeFactors.back().power++;
		}

		//Don't only have to check prime numbers, if we have divided by 2 as many times as we can, then when we come to divide by 4, it won't work
		else factor++;
	}

	return primeFactors;
}

int Math::getNextPrime(int previousPrime)
{
	if (previousPrime == 2)
	{
		return 3;
	}

	while(!Math::isPrime(previousPrime += 2));
	return previousPrime;
}

vector<int> Math :: calculateRepeatingContinuedFractionAValuesForSquareRoot(int root)
{
	double sqrtNum = sqrt(root);
	if (fmod(sqrtNum, 1.0) == 0)
	{
		cout << "Can't find continued fraction of square number. Exiting..." << endl;
		return vector<int>();
	}

	vector<int> a_vector;
	int a_0 = (int)sqrtNum;
	int m_n = 0;
	int d_n = 1;
	int a_n = a_0;
	a_vector.push_back(a_0);
	do
	{
		m_n = d_n * a_n - m_n;
		d_n = (int)((double)(root - m_n*m_n)/(double)d_n);
		a_n = (int)((double)(a_0 + m_n)/(double)d_n);
		a_vector.push_back(a_n);

	} while ((a_n != 2*a_0));

	return a_vector;
}

ExactFraction Math :: getNextConvergentForContinuedFraction(int a, ExactFraction previousConvergent_1, ExactFraction previousConvergent_2)
{
	ExactFraction nextConvergent;

	nextConvergent.numerator = ((previousConvergent_1.numerator) * a) + previousConvergent_2.numerator;
	nextConvergent.denominator = ((previousConvergent_1.denominator) * a) + previousConvergent_2.denominator;

	return nextConvergent;
}

void Math :: getPrimitiveSolutionForPellEquation(int n, BigInt* x_1, BigInt* y_1)
{
	vector<int> a_values = Math::calculateRepeatingContinuedFractionAValuesForSquareRoot(n);
	int a_period = (int)(a_values.size() - 1);

	ExactFraction convergent, previousConvergent_1, previousConvergent_2;

	previousConvergent_2.numerator = 1;
	previousConvergent_1.numerator = a_values.front();
	previousConvergent_2.denominator = 0;
	previousConvergent_1.denominator = 1;

	(*x_1) = 0;
	(*y_1) = 0;

	int i = 1;
	while ((*x_1)*(*x_1) != ((*y_1)*(*y_1) * n + 1))				//This needs '-' operator to be implemented to work properly
	{
		int index = (i-1) % a_period + 1;
		convergent = Math::getNextConvergentForContinuedFraction(a_values.at(index), previousConvergent_1, previousConvergent_2);
		(*x_1) = convergent.numerator;
		(*y_1) = convergent.denominator;

		previousConvergent_2 = previousConvergent_1;
		previousConvergent_1 = convergent;

		i++;
	}
}

void Math :: getNextSolutionForPellEquation(int n, BigInt* x, BigInt* y, BigInt x_0, BigInt y_0)
{
	BigInt x_original = *x;
	*x = (x_0 * (*x)) + (y_0 * (*y) * n);
	*y = (x_0 * (*y)) + (y_0 * (x_original));
}

long Math :: getSumOfFactors(int num)
{
	vector<PrimeFactor> primeFactors = getPrimeFactorsWithPowers(num);
	long sum = 1;

	for (vector<PrimeFactor>::iterator iter = primeFactors.begin(); iter != primeFactors.end(); iter++)
	{
		int tmp = 1;
		for (int i = 0; i < (iter->power + 1); i++)
		{
			tmp *= iter->factor;
		}

		sum *= (tmp - 1)/(iter->factor - 1);
	}

	return sum;
}

long Math :: getSumOfFactorsExcludingNum(int num)
{
	return (getSumOfFactors(num) - num);
}
