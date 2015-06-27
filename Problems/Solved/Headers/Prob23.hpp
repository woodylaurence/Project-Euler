/*
 * Prob23.hpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Laurence
 */

#ifndef PROB23_HPP_
#define PROB23_HPP_

#include "IProblem.hpp"
#include <vector>

using namespace std;

class Prob23 : public IProblem
{
public:
	void solve();

private:
	vector<int> getAbundantNumbers();
};



#endif /* PROB23_HPP_ */
