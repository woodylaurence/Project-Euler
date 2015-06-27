//
//  BigInt.h
//  Project Euler
//
//  Created by Laurence Woodward on 27/06/2015.
//  Copyright (c) 2015 Laurence Woodward. All rights reserved.
//

#ifndef __Project_Euler__BigInt__
#define __Project_Euler__BigInt__

#include <vector>
#include <climits>

class BigInt
{
public:
    BigInt();
    BigInt(int number);
    
    std::vector<unsigned int> getValue();

private:
    bool positive_;
    std::vector<unsigned int> value_;
    static const unsigned int DIGITS_MAX = UINT_MAX;
};

#endif /* defined(__Project_Euler__BigInt__) */
