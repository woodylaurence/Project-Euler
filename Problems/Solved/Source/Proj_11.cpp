/*
 * Proj_11.cpp
 *
 *  Created on: Oct 17, 2012
 *      Author: Laurence
 *
 *      Problem: Find maximum product of four adjacent numbers in a 20 x 20 grid
 */

#include <iostream>
#include <fstream>

using namespace std;

class Prob11
{
	int solve(void)
	{
		int **grid, maxProduct = 0, tmpMaxProduct = 0;
		char *buf;
		ifstream *input;

		/* - - - - - - Memory Allocation - - - - - - */
		buf = new char [128];
		grid = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			grid[i] = new int [20];
		}
		input = new ifstream;
		/* - - - - - - Memory Allocation - - - - - - */


		/* - - - - - - Data Read-In  - - - - - - */
		input->open("number_grid.txt");
		if (input->is_open())
		{
			for (int i = 0; i < 20; i++)
			{
				input->getline(buf, 128);
				sscanf(buf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &grid[i][0], &grid[i][1], &grid[i][2], &grid[i][3], &grid[i][4], &grid[i][5], &grid[i][6], &grid[i][7], &grid[i][8], &grid[i][9], &grid[i][10], &grid[i][11], &grid[i][12], &grid[i][13], &grid[i][14], &grid[i][15], &grid[i][16], &grid[i][17], &grid[i][18], &grid[i][19]);
			}
		}

		else
		{
			cout << "File could not be opened." << endl << "Exiting..." << endl;
			exit(EXIT_FAILURE);
		}
		/* - - - - - - Data Read-In  - - - - - - */

		/* - - - - - - Find Max Product - - - - - - */
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (grid[i][j] == 0)
				{
					continue;
				}
				tmpMaxProduct = findMaxProduct(i, j, grid);
				if (tmpMaxProduct > maxProduct)
				{
					maxProduct = tmpMaxProduct;
				}
			}
		}
		/* - - - - - - Find Max Product - - - - - - */

		cout << "Greatest product of four numbers: " << maxProduct << endl;

		return 0;
	}

	int findMaxProduct(int indexY, int indexX, int **grid)
	{
		int maxProduct = 0, tmp = 0, *tmpArray;

		tmpArray = new int [4];

		/* Down */
		if (indexY < 17)
		{
			maxProduct = grid[indexY][indexX]*grid[indexY+1][indexX]*grid[indexY+2][indexX]*grid[indexY+3][indexX];

			/* Diagonal-Right */
			if (indexX < 17)
			{
				tmp = grid[indexY][indexX]*grid[indexY+1][indexX+1]*grid[indexY+2][indexX+2]*grid[indexY+3][indexX+3];
				if (tmp > maxProduct)
				{
					maxProduct = tmp;
				}
			}

			/* Diagonal-Left */
			if (indexX > 2)
			{
				tmp = grid[indexY][indexX]*grid[indexY+1][indexX-1]*grid[indexY+2][indexX-2]*grid[indexY+3][indexX-3];
				if (tmp > maxProduct)
				{
					maxProduct = tmp;
				}
			}
		}

		/* Left */
		if (indexX < 17)
		{
			tmp = grid[indexY][indexX]*grid[indexY][indexX+1]*grid[indexY][indexX+2]*grid[indexY][indexX+3];
			if (tmp > maxProduct)
			{
				maxProduct = tmp;
			}
		}

		return maxProduct;
	}
};
