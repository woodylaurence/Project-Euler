/*
 * Proj_101.hpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Laurence
 */

#ifndef PROJ_101_HPP_
#define PROJ_101_HPP_

#include <vector>
#include "IProblem.hpp"

using namespace std;

class Prob101 : public IProblem
{
public:
	void solve();
    string getProblemName();
    
	long long u_n(int n);
	long long myPow(int base, int exponent);
	vector<long long> findBOP(int k);
};

#endif /* PROJ_101_HPP_ */
