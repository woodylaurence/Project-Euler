/*
 * Prob160.cpp
 *
 *  Created on: May 10, 2014
 *      Author: Laurence
 */

#include "Prob160.hpp"

#include <iostream>
#include "BigInt.hpp"

using namespace std;

void Prob160 :: solve()
{
	BigInt prod = 1;

//	for (long i = 1; i < 1000000000000; i++)
//	{
//		prod = prod * i;
//	}



	cout << "Answer : " << prod << endl;
}

string Prob160 :: getProblemName()
{
    return "Problem 160";
}