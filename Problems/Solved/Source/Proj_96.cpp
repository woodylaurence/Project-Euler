/*
 * Proj_96.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: Laurence
 */

/*#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "/Users/Laurence/Documents/Programming/C++/Eclipse/Sudoku Solver/Grid.h"
#include "/Users/Laurence/Documents/Programming/C++/Eclipse/Sudoku Solver/Cell.h"

using namespace std;

int main(void)
{
	ifstream inputFile;
	int sum = 0;

	inputFile.open("sudoku.txt", ifstream::in);

	for(int i = 0; i < 50; i++)
	{
		char tmp[128];
		vector<int> sudoku;

		inputFile.getline(tmp, 128);

		for (int j = 0; j < 81; j++)
		{
			int value = inputFile.get() - 48;
			sudoku.push_back(value);

			if (j % 9 == 8)			//To get rid of the \n character
			{
				char c = inputFile.get();
			}
		}

		Grid g = Grid(sudoku);

		if (g.solve())
		{
			cout << "Solved sudoku " << i << endl;

			vector< vector<Cell> > solvedGrid = g.getRawGrid();

			sum += (solvedGrid[0][0].getValue() * 100) + (solvedGrid[0][1].getValue() * 10) + (solvedGrid[0][2].getValue());
		}
		else
		{
			cout << "Error, could not solve sudoku " << i << ".\nExiting." << endl;
			return 1;
		}
	}

	cout << "Total of top-left corner numbers: " << sum << endl;

	return 0;
}*/


