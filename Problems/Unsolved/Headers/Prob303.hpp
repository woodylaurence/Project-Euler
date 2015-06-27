/*
 * Prob303.hpp
 *
 *  Created on: May 9, 2014
 *      Author: Laurence
 */

#ifndef PROB303_HPP_
#define PROB303_HPP_

#include "IProblem.hpp"

class Prob303 : public IProblem
{
public:
	void solve();
    std::string getProblemName();

private:
	int getLowestMultiplier(int n);
};

#endif /* PROB303_HPP_ */
