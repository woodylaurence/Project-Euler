/*
  * BigIntEvenFaster.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 *
 *      Arithmetic for numbers too great for int to hold.
 */
#include "BigInt.hpp"
#include <sstream>

BigInt :: BigInt()
{
	BigInt(0);
}

BigInt :: BigInt(int tmpNumber)				/* Creates BigIntEvenFaster if supplied argument is just an integer, the value wanting be represented by BigIntEvenFaster*/
{
	this->number.reserve(1000);
	this->int_to_BigInt(tmpNumber);
}

BigInt :: ~BigInt()
{
    //does this not need to delete the vector as well, MEMORY LEAK?!
	number.clear();
}

BigInt :: BigInt(const BigInt &tmpNumber)
{
	number = tmpNumber.number;
}

vector<long long> BigInt :: getValue()
{
	return number;
}

/* Make these statics, so you can say BigIntEvenFaster b = BigIntEvenFaster::int_to_BigIntEvenFaster(875) */
/* Surely these could all be done with generic types? */
void BigInt :: int_to_BigInt(int tmpNumber) { long_long_to_BigInt((long long)tmpNumber); }
void BigInt :: long_to_BigInt(long tmpNumber) {	long_long_to_BigInt((long long)tmpNumber); }
void BigInt :: long_long_to_BigInt(long long tmpNumber)
{
	vector<long long> digits;

	if (tmpNumber == 0)
	{
		digits.push_back(0);
		this->number = digits;
		return;
	}

	while (tmpNumber > 0)
	{
		digits.push_back(tmpNumber % DIGITS_BASE);
		tmpNumber /= DIGITS_BASE;
	}
	number = digits;
	this->reverseDigitBlocks();

	return;
}

int BigInt :: toInt()
{
    throw "This should probably check it can be converted to int, otherwise, throw error";
	/*int num = number.back();
	if (getNumDigitBlocks() > 1)
	{
		num += DIGITS_BASE * number.at(getNumDigitBlocks() - 2);
	}

	return num;*/
}

#pragma region Operators

//OPERATORS
BigInt BigInt :: operator = (const BigInt &tmpNumber)
{
	if (this == &tmpNumber) return *this;

	number = tmpNumber.number;
	return *this;
}

BigInt BigInt :: operator = (int tmpNumber)
{
	number.clear();
	this->int_to_BigInt(tmpNumber);

	return *this;
}

BigInt BigInt :: operator + (BigInt tmpNumber)
{
	BigInt answer;
	long long carry = 0;

	if (tmpNumber.getNumDigits() > this->getNumDigits())
	{
		answer.number = this->number;
		this->number = tmpNumber.number;
		tmpNumber.number = answer.number;
	}

	answer.number.clear();
	vector<long long>::reverse_iterator j = this->number.rbegin();
	for (vector<long long>::reverse_iterator i = tmpNumber.number.rbegin(); i != tmpNumber.number.rend(); i++, j++)
	{
		long long tmp = *i + *j + carry;
		(answer.number).push_back(tmp % DIGITS_BASE);
		carry = tmp / DIGITS_BASE;
	}
	for ( ; j != this->number.rend(); j++)
	{
		answer.number.push_back((*j + carry) % DIGITS_BASE);
		carry = (*j + carry) / DIGITS_BASE;
	}

	if (carry != 0) (answer.number).push_back(carry);

	answer.reverseDigitBlocks();

	return answer;
}

BigInt BigInt :: operator + (int tmpNumber)
{
	return *this + BigInt(tmpNumber);
}

/*			This needs implementing
BigIntEvenFaster BigIntEvenFaster :: operator - (BigIntEvenFaster tmpNumber)
{

}*/

BigInt BigInt :: operator * (BigInt tmpNumber)
{
	BigInt answer, tmp;
	long long temp, carry=0, digit;
	int k=0;

	answer = 0;
	for (vector<long long>::reverse_iterator i = number.rbegin(); i != number.rend(); i++)
	{
		(tmp.number).clear();
		carry = 0;
		for (int m = 0; m < k; m++)
		{
			(tmp.number).push_back(0);
		}

		for (vector<long long>::reverse_iterator j = (tmpNumber.number).rbegin(); j != (tmpNumber.number).rend(); j++)
		{
			temp = (*i) * (*j) + carry;
			digit = temp % DIGITS_BASE;
			carry = temp / DIGITS_BASE;
			(tmp.number).push_back(digit);
		}

		if (carry != 0)	(tmp.number).push_back(carry);

		tmp.reverseDigitBlocks();

		answer = answer + tmp;
		k++;
	}

	return answer;
}

BigInt BigInt :: operator * (int tmpNumber)
{
	BigInt tmp;

	tmp.int_to_BigInt(tmpNumber);
	return (*this * tmp);
}

/*BigIntEvenFaster BigIntEvenFaster :: operator % (int tmpNumber)
{
	if (tmpNumber == 3)
	{

	}
}*/

bool BigInt :: operator == (BigInt tmpNumber)
{
	int numDigits = this->getNumDigits();
	int numDigitBlocks = this->getNumDigitBlocks();
	if (tmpNumber.getNumDigitBlocks() != numDigitBlocks &&					//just for speed
		tmpNumber.getNumDigits() != numDigits) return true;

	for (int i = 0; i < numDigitBlocks; i++)
	{
		if (this->number[i] != tmpNumber.number[i]) return false;
	}

	return true;
}

bool BigInt :: operator == (int tmpNumber)
{
	return (*this == BigInt(tmpNumber));
}

bool BigInt :: operator != (BigInt tmpNumber)
{
	return !(*this == tmpNumber);
}

bool BigInt :: operator != (int tmpNumber)
{
	return !(*this == BigInt(tmpNumber));
}

bool BigInt :: operator < (BigInt tmpNumber)
{
	int numDigits = this->getNumDigits();
	int numDigitBlocks = this->getNumDigitBlocks();
	int tmpNumberNumDigits = tmpNumber.getNumDigits();
	int tmpNumberNumDigitBlocks = tmpNumber.getNumDigitBlocks();

	if (numDigitBlocks < tmpNumberNumDigitBlocks) return true;
	else if (numDigitBlocks > tmpNumberNumDigitBlocks) return false;
	else
	{
		if (numDigits < tmpNumberNumDigits) return true;
		else if (numDigits > tmpNumberNumDigits) return false;
	}

	for (int i = 0; i < numDigitBlocks; i++)
	{
  		if (number[i] < tmpNumber.number[i]) return true;
  		else if (number[i] > tmpNumber.number[i]) return false;
	}

	return false;
}

bool BigInt :: operator < (int tmpNumber)
{
	return (*this < BigInt(tmpNumber));
}

bool BigInt :: operator > (BigInt tmpNumber)
{
	return (tmpNumber < *this);
}

bool BigInt :: operator > (int tmpNumber)
{
	return ( BigInt(tmpNumber) < *this);
}

bool BigInt :: operator <= (BigInt tmpNumber)
{
	return ((*this == tmpNumber) || (*this < tmpNumber));
}

bool BigInt :: operator <= (int tmpNumber)
{
	BigInt tmp = BigInt(tmpNumber);
	return ((*this == tmp) || (*this < tmp));
}

bool BigInt :: operator >= (BigInt tmpNumber)
{
	return ((*this == tmpNumber) || (tmpNumber < *this));
}

bool BigInt :: operator >= (int tmpNumber)
{
	BigInt tmp = BigInt(tmpNumber);
	return ((*this == tmp) || (tmp < *this));
}

#pragma endregion Operators


//POWER
BigInt BigInt :: power(int exponent)
{
	BigInt base, answer = 1;

	base = *this;
	{
		while (exponent)
		{
			if (exponent & 1)
			{
				answer = answer * base;
			}
			exponent >>= 1;
			base = base * base;
		}
	}

	return answer;
}

BigInt BigInt :: power(int base, int exponent)
{
	BigInt answer, BigIntBase;

	BigIntBase.int_to_BigInt(base);
	return BigIntBase.power(exponent);
}



//REVERSE DIGITS
void BigInt :: reverseDigitBlocks()
{
	//cout << "This might be better done with std::reverse(a.begin(), a.end())" << endl;
	BigInt reversedDigits;

	for (vector<long long>::reverse_iterator iter = number.rbegin(); iter != number.rend(); iter++)
	{
		reversedDigits.number.push_back(*iter);
	}

	this->number = reversedDigits.number;
}



//NUM OF DIGITS
int BigInt :: getNumDigits()
{
	if (number.size() == 0) return 0;
	// how many digits is the number 0, is it 0 or 1?
	long long firstBlockDigit = number.front();
	int numDigitsInFirstBlock = (1 + (firstBlockDigit > 10) + (firstBlockDigit > 100) + (firstBlockDigit > 1000)
							  + (firstBlockDigit > 10000) + (firstBlockDigit > 100000) + (firstBlockDigit > 1000000)
							  + (firstBlockDigit > 10000000));
	return numDigitsInFirstBlock +  (int)(9 * (number.size() - 1));
}

int BigInt :: getNumDigitBlocks()
{
	return int(number.size());
}



//CONVERT TO STRING AND PRINTING
string BigInt::toString()
{
	stringstream stream;

	if (number.size() == 0) return "0";
	else
	{
		vector<long long>::iterator i = number.begin();			// Need to this since don't want have extra 0s at the beginning of the number
		stream << *i;
		i++;
		for ( ; i != number.end(); i++)
		{
			if (*i < 10000000) stream << 0;
			if (*i < 1000000) stream << 0;
			if (*i < 100000) stream << 0;
			if (*i < 10000) stream << 0;
			if (*i < 1000) stream << 0;
			if (*i < 100) stream << 0;
			if (*i < 10) stream << 0;
			stream << *i;
		}
	}

	return stream.str();
}

string BigInt::firstNDigitsAsString(int n)
{
	if (n > getNumDigits())
	{
		cout << "You requested printing the result to more characters than there are ... Printing full value:\n";
		return toString();
	}

	return toString().substr(0, n);
}

string BigInt::lastNDigitsAsString(int n)
{
	return toString().substr(getNumDigits() - n, n);
}

ostream& operator << (ostream &outStream, BigInt num)
{
	outStream << num.toString();
	return outStream;
}
