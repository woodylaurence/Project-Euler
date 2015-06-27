/*
 * Utilities.hpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Laurence
 */

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <vector>

using namespace std;

class Utilities
{
public:
	int static getSumDigits(int num);
	vector<int> static getDigits(int num);
	vector<int> static getDigits(long long num);
	int static getNumDigits(int num);
	void static printVectorAsNumber(vector<int> digits);
	int static digitsToInt(vector<int> digits);
	long long static digitsToLongLong(vector<int> digits);
	bool static isPanditigalNumber(int n, int num, bool includeZero);
	bool static isPanditigalNumber(int n, long long num, bool includeZero);
	bool static isPanditigalNumber(int n, vector<int> digits, bool includeZero);
};

#endif /* UTILITIES_HPP_ */
