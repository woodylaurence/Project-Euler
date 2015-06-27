/*
 * Proj_81.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: Laurence
 *
 *      Do like in problem 18, work out minimal sum along diagonals of matrix until you reach the bottom right corner
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Prob8
{
	int main(void)
	{
		vector<int> cumulDiagonal;
		vector<int> matrix;
		vector< vector<int> > diagonalLines;
		vector< vector<int> >::iterator iter;

		readInMatrix(&matrix);
		diagonalLines = getDiagonalLines(matrix);

		cumulDiagonal.push_back(diagonalLines.front().front());

		iter = diagonalLines.begin();
		iter++;
		for (; iter != diagonalLines.end(); iter++)
		{
			getTotalDiagonal(&cumulDiagonal, *iter, (iter->size() > cumulDiagonal.size()) ? true : false);
		}

		cout << cumulDiagonal.back() << endl;

		return 0;
	}

	void readInMatrix(vector<int>* matrix)
	{
		int tmp;
		ifstream *input;
		string buffer;
		stringstream *sstream;

		sstream = new stringstream();

		input = new ifstream("matrix.txt");
		if (input->is_open())
		{
			while (!input->eof())
			{
				getline(*input, buffer);
				sstream->clear();
				sstream->str(buffer);

				while(*sstream >> tmp)
				{
					matrix->push_back(tmp);
					if (sstream->peek() == ',')
					{
						sstream->ignore();
					}
				}
			}
		}

		else
		{
			cout << "Sorry, the file could not be opened." << endl << "Exiting..." << endl;
		}

		return;
	}


	void getTotalDiagonal(vector<int>* cumulDiagonal, vector<int> line, bool lineSizeIncreasing)
	{
		int lineLength = 0, tmp, tmp1, tmp2;
		vector<int> previousLine;

		for (vector<int>::iterator iter = cumulDiagonal->begin(); iter != cumulDiagonal->end(); iter++)
		{
			previousLine.push_back(*iter);
		}


		cumulDiagonal->clear();

		lineLength = (int)line.size();

		if (lineSizeIncreasing)
		{
			cumulDiagonal->push_back(line.front() + previousLine.front());

			for (int i = 1; i < lineLength - 1; i++)
			{
				tmp1 = previousLine.at(i - 1) + line.at(i);
				tmp2 = previousLine.at(i) + line.at(i);
				tmp = (tmp1 < tmp2) ? tmp1 : tmp2;

				cumulDiagonal->push_back(tmp);
			}

			cumulDiagonal->push_back(line.back() + previousLine.back());
		}
		else
		{
			for (int i = 0; i < lineLength; i++)
			{
				tmp1 = previousLine.at(i) + line.at(i);
				tmp2 = previousLine.at(i + 1) + line.at(i);
				tmp = (tmp1 < tmp2) ? tmp1 : tmp2;

				cumulDiagonal->push_back(tmp);
			}
		}


		return;
	}

	vector< vector<int> > getDiagonalLines(vector<int> matrix)
	{
		int numInLine, matDim, matrixIndex;
		vector< vector<int> > diagonalLines;
		vector<int> diagonalLine;

		matDim = (int)sqrt(matrix.size());

		for (int i = 1; i < 2*matDim; i++)
		{
			diagonalLine.clear();
			numInLine = (i < matDim) ? i : 2*matDim - i;
			for (int j = 0; j < numInLine; j++)
			{
				matrixIndex = (i <= matDim) ? (i - 1)*(matDim) - j*(matDim - 1) : (matDim-1)*matDim  + (i - matDim) - j*(matDim - 1);
				diagonalLine.push_back(matrix.at(matrixIndex));
			}
			diagonalLines.push_back(diagonalLine);
		}


		return diagonalLines;
	}
};
