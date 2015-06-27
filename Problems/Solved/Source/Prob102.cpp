/*
 * Prob102.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Laurence
 *
 *      Problem: Determine the number of triangles (determined by text file) which contain the origin (0, 0)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Prob102.hpp"

void Prob102 :: solve()
{
	cout << "Solving Problem 102..." << endl << endl;

	int numTriangles = 0;

	vector< vector<Point> > triangles = getTriangles();
	for (vector< vector<Point> >::iterator triangle = triangles.begin(); triangle != triangles.end(); triangle++)
	{
		if (containsOrigin(triangle->at(0), triangle->at(1), triangle->at(2))) numTriangles++;
	}

	cout << "Answer: " << numTriangles << endl;

	return;
}

bool Prob102 :: containsOrigin(Point a, Point b, Point c)
{
	double alpha_num = (b.y - c.y)*(-c.x) + (c.x - b.x)*(-c.y);
	double alpha_den = (b.y - c.y)*(a.x - c.x) + (c.x - b.x)*(a.y - c.y);
	double alpha = alpha_num / alpha_den;

	double beta_num = (c.y - a.y)*(-c.x) + (a.x - c.x)*(-c.y);
	double beta_den = (b.y - c.y)*(a.x - c.x) + (c.x - b.x)*(a.y - c.y);
	double beta = beta_num / beta_den;

	return ((alpha > 0 && beta > 0) && (alpha + beta) < 1);
}

vector< vector<Point> > Prob102 :: getTriangles()
{
	ifstream input;
	string buffer;
	vector< vector<Point> > triangles;

	input.open("Resources/triangles.txt", ifstream::in);
	while (!input.eof())
	{
		Point a, b, c;
		vector<Point> triangle;
		string str;
		vector<string> vPointStrings;

		getline(input, buffer);
		stringstream sstream(buffer);

		while(getline(sstream, str, ',' )) vPointStrings.push_back(str);

		a.x = atof(vPointStrings.at(0).c_str());
		a.y = atof(vPointStrings.at(1).c_str());
		b.x = atof(vPointStrings.at(2).c_str());
		b.y = atof(vPointStrings.at(3).c_str());
		c.x = atof(vPointStrings.at(4).c_str());
		c.y = atof(vPointStrings.at(5).c_str());

		triangle.push_back(a);
		triangle.push_back(b);
		triangle.push_back(c);
		triangles.push_back(triangle);
	}

	input.close();

	return triangles;
}
