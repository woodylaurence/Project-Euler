/*
 * Prob32.hpp
 *
 *  Created on: Sep 6, 2014
 *      Author: Laurence
 */

#ifndef PROB32_HPP_
#define PROB32_HPP_

#include "IProblem.hpp"

#include <vector>

using namespace std;

class Prob32 : public IProblem
{
public:
	void solve();

private:
	vector<int> concatonateNumbers(int multiplcand, int multipler, int product);
};

#endif /* PROB32_HPP_ */
