/*
 * Prob38.hpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Laurence
 */

#ifndef PROB38_HPP_
#define PROB38_HPP_

#include "IProblem.hpp"
#include <vector>

using namespace std;

class Prob38 : public IProblem
{
public:
	void solve();
	vector<int> convertMultiDigitsToSingleDigitVector(vector<int> digits);
};

#endif /* PROB38_HPP_ */
