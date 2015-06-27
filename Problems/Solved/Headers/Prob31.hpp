/*
 * Prob31.hpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Laurence
 */

#ifndef PROB31_HPP_
#define PROB31_HPP_

#include "IProblem.hpp"
#include <vector>
using namespace std;

class Prob31 : public IProblem
{
public:
	void solve();

private:
	long long numWaysToMakeAmount(int amount, int largestDenominationToUse);

	int const denominations[8] = {200, 100, 50, 20, 10, 5, 2, 1};
};

#endif /* PROB31_HPP_ */
