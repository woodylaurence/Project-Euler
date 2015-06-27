//
//  BigInt.cpp
//  Project Euler
//
//  Created by Laurence Woodward on 27/06/2015.
//  Copyright (c) 2015 Laurence Woodward. All rights reserved.
//

#include "BigInt.h"

BigInt :: BigInt()
{
    BigInt(0);
}

BigInt :: BigInt(int number)
{
    throw "Not Implemented";
}

std::vector<unsigned int> BigInt :: getValue()
{
    return value_;
}