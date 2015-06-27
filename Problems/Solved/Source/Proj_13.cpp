/*
 * Proj_13.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: Laurence
 *
 *      Problem: Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 *
 *      NOTE: REQUIRES 'BigInt.cpp'  TO RUN
 */

#include "BigInt.hpp"

using namespace std;

class Prob13
{
	int solve(void)
	{
        throw "Needs reimplementing";
        
		/*FILE *input;
		list<BigInt> numbers;
		BigInt answer=0;
		char **charNumbers;

		charNumbers = (char**) malloc(100*sizeof(char*));
		for (int i = 0; i < 100; i++)
		{
			charNumbers[i] = (char*) malloc(50*sizeof(char));
		}

		input = fopen("Proj_13_numbers.txt", "r");

		if (input != (FILE*) NULL)
		{
			for (int i = 0; i < 100; i++)
			{
				fscanf(input, "%s\n", charNumbers[i]);
			}

			for (int i = 0; i < 100; i++)
			{
				numbers.push_back(BigInt(charNumbers[i]));
			}

			for (list<BigInt>::iterator j = numbers.begin(); j != numbers.end(); j++)
			{
				answer = answer + *j;
			}

			cout << "Answer: "; answer.printValue(1, 10); cout << endl;
		}

		else
		{
			cout << "Could not find input file\nExiting...\n";
			exit(EXIT_FAILURE);
		}

		return 0;*/
	}
};
