/*
 * Prob62.hpp
 *
 *  Created on: Sep 4, 2014
 *      Author: Laurence
 */

#ifndef PROB62_HPP_
#define PROB62_HPP_

#include "IProblem.hpp"

class Prob62 : public IProblem
{
public:
	void solve();

private:
	int getLowestCube();
};

#endif /* PROB62_HPP_ */
