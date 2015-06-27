/*
 * BigInt.hpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Laurence
 */

#ifndef BIGINT_HPP_
#define BIGINT_HPP_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(int);
	BigInt(const BigInt&);
	~BigInt();
	vector<long long> getValue();
	string toString(int startIndex, int endIndex);
	string firstNDigitsAsString(int n);
	string lastNDigitsAsString(int n);
	void int_to_BigInt(int n);
	void long_to_BigInt(long n);
	void long_long_to_BigInt(long long n);
//	int BigInt_to_int(BigInt tmpNumber);
	int toInt();
	BigInt operator + (BigInt tmpNumber);
	BigInt operator + (int);
//	void operator ++();
//	void operator --(); 				/* Note, this should be used with caution, haven't dealt with negative numbers yet, not sure what 0 - 1 would yield? */
//	BigInt operator - (BigInt tmpNumber);
//	BigInt operator - (int tmpNumber);
	BigInt operator * (BigInt tmpNumber);
	BigInt operator * (int tmpNumber);
	BigInt operator * (long tmpNumber);
	BigInt operator % (BigInt tmpNumber);
	int operator % (int tmpNumber);
	BigInt operator = (const BigInt& tmpNumber);
	BigInt operator = (int tmpNumber);
	bool operator == (BigInt tmpNumber);
	bool operator == (int tmpNumber);
	bool operator != (BigInt tmpNumber);
	bool operator != (int tmpNumber);
	bool operator > (BigInt tmpNumber);
	bool operator > (int tmpNumber);
	bool operator < (BigInt tmpNumber);
	bool operator < (int tmpNumber);
	bool operator >= (BigInt tmpNumber);
	bool operator >= (int tmpNumber);
	bool operator <= (BigInt tmpNumber);
	bool operator <= (int tmpNumber);
	BigInt power(int);
	static BigInt power(int, int);
//	static BigInt factorial(int);
//	static BigInt recursivFactorial(BigInt);
	//BigInt sumDigits();
//	int sumDigits();
	int getNumDigits();
	int getNumDigitBlocks();

	friend ostream& operator << (ostream &outStream, BigInt num);

private:
	int BigInt_To_int();
	void reverseDigitBlocks();
	string toString();

	vector<long long> number;
    bool positive;
	const static long long DIGITS_BASE = 100000000;
};


#endif /* BIGINT_HPP_ */
