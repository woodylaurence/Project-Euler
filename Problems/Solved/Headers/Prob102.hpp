/*
 * Prob102.hpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Laurence
 */

#ifndef PROB102_HPP_
#define PROB102_HPP_

#include "IProblem.hpp"
#include <vector>

using namespace std;

struct Point
{
	double x;
	double y;
};

class Prob102 : public IProblem
{
public:
	void solve();
    string getProblemName();
    
	vector< vector<Point> >getTriangles();
	bool containsOrigin(Point point1, Point point2, Point point3);
};

#endif /* PROB102_HPP_ */
