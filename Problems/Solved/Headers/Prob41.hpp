/*
 * Prob41.hpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Laurence
 */

#ifndef PROB41_HPP_
#define PROB41_HPP_

#include "IProblem.hpp"
#include <vector>

using namespace std;

class Prob41 : public IProblem
{
public:
	void solve();

private:
	long getNumFromDigits(vector<int> digits);
	long getLargestPandigitalPrime();

};

#endif /* PROB41_HPP_ */
