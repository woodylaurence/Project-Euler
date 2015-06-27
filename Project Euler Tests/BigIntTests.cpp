//
//  BigIntTests.cpp
//  Project Euler
//
//  Created by Laurence Woodward on 27/06/2015.
//  Copyright (c) 2015 Laurence Woodward. All rights reserved.
//

#include <climits>
#include "gtest/gtest.h"

#include "BigInt.h"

using namespace std;

TEST(BigInt, Constructor_WHERE_parameterless_SHOULD_create_BigInt_with_value_0)
{
    //act
    BigInt actual = BigInt();
    
    //assert
    vector<unsigned int> expected = vector<unsigned int>{0};
    EXPECT_EQ(expected, actual.getValue());
}

TEST(BigInt, Constructor_WHERE_int_parameter_SHOULD_create_BigInt_with_value_provided)
{
    //arrange
    int expected = 83501;
    
    //act
    BigInt actual = BigInt(83501);
    
    //assert
    EXPECT_EQ(expected, actual);
}