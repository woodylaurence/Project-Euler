/*
 * Prob92.hpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Laurence
 */

#ifndef PROB92_HPP_
#define PROB92_HPP_

#include "IProblem.hpp"

class Prob92 : public IProblem
{
public:
	void solve();
    std::string getProblemName();
    
	int getSquareOfSumDigits(int num);
};

#endif /* PROB92_HPP_ */
