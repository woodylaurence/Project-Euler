/*
 * IProblem.hpp
 *
 *  Created on: Apr 5, 2014
 *      Author: Laurence
 */

#ifndef IPROBLEM_HPP_
#define IPROBLEM_HPP_

class IProblem
{
public:
	virtual ~IProblem();
	virtual void solve() = 0;
};

#endif /* IPROBLEM_HPP_ */
