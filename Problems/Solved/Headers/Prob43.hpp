/*
 * Prob43.hpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Laurence
 */

#ifndef PROB43_HPP_
#define PROB43_HPP_

#include <vector>
#include "IProblem.hpp"

using namespace std;

class Prob43 : public IProblem
{
public:
	void solve();
    string getProblemName();
    
	int convertSubDigitsToNumber(int firstDig, vector<int> number);
	long long digitsToNum(vector<int> digits);
	void printNumber(vector<int> digits);
};

#endif /* PROB43_HPP_ */
