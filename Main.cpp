//
//  Main.cpp
//  Project Euler
//
//  Created by Laurence Woodward on 26/06/2015.
//  Copyright (c) 2015 Laurence Woodward. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#define UPPER_LIMIT 100

using namespace std;

int main(void)
{
    long int sumSquare=0, squareSum, diff;
    
    squareSum = 0.5*((double)UPPER_LIMIT)*((double)UPPER_LIMIT+ 1);
    squareSum *= squareSum;
    
    for (int i = 1; i <= (int) UPPER_LIMIT; i++)
    {
        sumSquare += i*i;
    }
    
    cout << "squareSum = " << squareSum << endl;
    cout << "sumSquare = " << sumSquare << endl;
    
    diff = squareSum - sumSquare;
    
    cout << "Difference is " << diff << endl;

    return 0;
}
