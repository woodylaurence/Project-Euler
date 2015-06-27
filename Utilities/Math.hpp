/*
 * Math.hpp
 *
 *  Created on: Oct 18, 2012
 *      Author: Laurence
 */

#ifndef MATH_HPP_
#define MATH_HPP_

#include <vector>
#include "BigInt.hpp"

using namespace std;

//Make this typed, ExactFraction<T,S> where T states type of numerator, S states type of denominator
struct ExactFraction
{
	BigInt numerator;
	BigInt denominator;
};

struct PrimeFactor
{
	int factor;
	int power;
};

class Math
{
public:
	bool static isPrime(int num);
	bool static isPrime(long int num);
	bool static isPrime(long long int num);
	vector<int> static getPrimeFactors(int num);
	vector<PrimeFactor> static getPrimeFactorsWithPowers(int num);
	int static getNextPrime(int previousPrime);
	vector<int> static calculateRepeatingContinuedFractionAValuesForSquareRoot(int root);
	ExactFraction static getNextConvergentForContinuedFraction(int a, ExactFraction previousConvergent_1, ExactFraction previousConvergent_2);
	ExactFraction static getNthConvergentForContinuedFraction(vector<int> a_vector, int n);
	void static getPrimitiveSolutionForPellEquation(int n, BigInt* x_1, BigInt* y_1);
	void static getNextSolutionForPellEquation(int n, BigInt* x, BigInt* y, BigInt x_0, BigInt y_0);
	long static getSumOfFactors(int num);
	long static getSumOfFactorsExcludingNum(int num);
};

#endif /* MATH_HPP_ */
