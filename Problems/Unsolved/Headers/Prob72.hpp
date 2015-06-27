/*
 * Prob72.hpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#ifndef PROB72_HPP_
#define PROB72_HPP_

#include "IProblem.hpp"

class Prob72 : public IProblem
{
public:
	void solve();
    std::string getProblemName();

private:
	bool mutuallyPrime(int num1, int num2);
};

#endif /* PROB72_HPP_ */
