/*
 * Proj_52.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: Laurence
 *
 *      Problem: Find smallest x such that 2x, 3x, 4x, 5x and 6x contain the same digits
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Prob52
{
	int main(void)
	{
		int num = 0;
		bool done = false;
		vector<long int> numbers;
		list<int> *digits;

		digits = new list<int> [5];				// Do I need this or not?

		while(!done)
		{
			num++;
			numbers.clear();
			for (int i = 2; i < 7; i++)
			{
				numbers.push_back(num*i);
			}
			digits = getDigits(numbers);
			if (sameDigits(digits))
			{
				done = true;
			}
		}

		cout << "Answer: " << num << endl;

		return 0;
	}

	list<int>* getDigits(vector<long int> numbers)
	{
		list<int> *digits;

		digits = new list<int> [5];

		for (int i = 0; i < 5; i++)
		{
			while(numbers.at(i) > 0)
			{
				digits[i].push_back(numbers.at(i) % 10);
				numbers.at(i) /= 10;
			}
		}

		return digits;
	}

	bool sameDigits(list<int> *digits)
	{
		bool same = false;

		if (digits[0].size() == digits[1].size() && digits[0].size() == digits[2].size() && digits[0].size() == digits[3].size() && digits[0].size() == digits[4].size())			/* No point going further unless each number has same number of digits. */
		{
			same = true;
			for (int i = 0; i < 5; i++)
			{
				digits[i].sort();
			}

			while(!digits[0].empty())
			{
				for (int j = 0; j < 4 && same; j++)
				{
					same = (digits[j].back() == digits[j+1].back());
				}
				for (int j = 0; j < 5; j++)
				{
					digits[j].pop_back();
				}
			}
		}

		return same;
	}
};
