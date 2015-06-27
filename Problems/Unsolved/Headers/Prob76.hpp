/*
 * Prob76.hpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#ifndef PROB76_HPP_
#define PROB76_HPP_

#include "IProblem.hpp"

class Prob76 : public IProblem
{
public:
	void solve();
    std::string getProblemName();

private:
	long long numWaysToMakeAmount(int amount, int largestDenominationToUse);
	int* denominations;
};

#endif /* PROB76_HPP_ */
