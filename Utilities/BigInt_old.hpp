/*
 * BigInt_old.hpp
 *
 *  Created on: Jun 19, 2012
 *      Author: Laurence
 */

#ifndef BigInt_old_HPP_
#define BigInt_old_HPP_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BigInt_old
{
public:
	BigInt_old();
	BigInt_old(int);
	BigInt_old(const BigInt_old&);
	~BigInt_old();
	vector<long long> getValue();
	string toString(int startIndex, int endIndex);
	string firstNDigitsAsString(int n);
	string lastNDigitsAsString(int n);
	void int_to_BigInt(int n);
	void long_to_BigInt(long n);
	void long_long_to_BigInt(long long n);
//	int BigInt_to_int(BigInt tmpNumber);
	int toInt();
	BigInt_old operator + (BigInt_old tmpNumber);
	BigInt_old operator + (int);
//	void operator ++();
//	void operator --(); 				/* Note, this should be used with caution, haven't dealt with negative numbers yet, not sure what 0 - 1 would yield? */
//	BigInt_old operator - (BigInt_old tmpNumber);
//	BigInt_old operator - (int tmpNumber);
	BigInt_old operator * (BigInt_old tmpNumber);
	BigInt_old operator * (int tmpNumber);
	BigInt_old operator * (long tmpNumber);
	BigInt_old operator % (BigInt_old tmpNumber);
	int operator % (int tmpNumber);
	BigInt_old operator = (const BigInt_old& tmpNumber);
	BigInt_old operator = (int tmpNumber);
	bool operator == (BigInt_old tmpNumber);
	bool operator == (int tmpNumber);
	bool operator != (BigInt_old tmpNumber);
	bool operator != (int tmpNumber);
	bool operator > (BigInt_old tmpNumber);
	bool operator > (int tmpNumber);
	bool operator < (BigInt_old tmpNumber);
	bool operator < (int tmpNumber);
	bool operator >= (BigInt_old tmpNumber);
	bool operator >= (int tmpNumber);
	bool operator <= (BigInt_old tmpNumber);
	bool operator <= (int tmpNumber);
	BigInt_old power(int);
	static BigInt_old power(int, int);
//	static BigInt_old factorial(int);
//	static BigInt_old recursivFactorial(BigInt_old);
	//BigInt_old sumDigits();
//	int sumDigits();
	int getNumDigits();
	int getNumDigitBlocks();

	friend ostream& operator << (ostream &outStream, BigInt_old num);

private:
	int BigInt_old_To_int();
	void reverseDigitBlocks();
	string toString();

	vector<long long> number;
    bool positive;
	const static long long DIGITS_BASE = 100000000;
};


#endif /* BigInt_old_HPP_ */
