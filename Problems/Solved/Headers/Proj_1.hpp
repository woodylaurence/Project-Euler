/*
 * Proj_1.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: Laurence
 */

#ifndef PROJ_1_HPP_
#define PROJ_1_HPP_

#include "IProblem.hpp"

class Prob1 : public IProblem
{
public:
	void solve();
    std::string getProblemName();

private:
	int triangle(int limit, int delta);
};



#endif /* PROJ_1_HPP_ */
