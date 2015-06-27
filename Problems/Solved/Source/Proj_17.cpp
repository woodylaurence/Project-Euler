/*
 * Proj_17.cpp
 *
 *  Created on: Aug 16, 2012
 *      Author: Laurence
 *
 *      Problem: "How many letters would be needed to write all the numbers in words from 1 to 1000?"
 */

#include <iostream>
#include <list>

using namespace std;

class Prob17
{
	int solve(void)
	{
		int totalChars = 0;
		for (int i = 1; i <= 1000; i++)
		{
			totalChars += getDigits(i);
		}

		cout << "Characters required: " << totalChars << endl;
		return 0;
	}

	int getDigits(int tmpNumber)
	{
		int numDigits = 0;
		list<int> digits;

		while (tmpNumber != 0)
		{
			(numDigits)++;
			digits.push_front((tmpNumber % 10));			/* Need to push digit to front since first % gets units, next digit to be put in list is tens and so on. */
			tmpNumber /= 10;
		}

		return (digitsToNumChars(digits, numDigits));
	}

	int digitsToNumChars(list<int> digits, int numDigits)
	{
		int numChars = 0, j = 0;
		list<int>::iterator iter1, iter2;

		for (list<int>::iterator i = digits.begin(); i != digits.end(); i++)
		{
			j++;
			switch(*i)
			{
				case 0:
				{

				} break;

				case 1:
				{
					switch(numDigits - j)
					{
						case 0: case 2: case 3:			/* The 1 is the units, hundreds or thousands digit */
						{
							numChars += 3;
						} break;

						case 1:			/* The 1 is the tens digit, need to take into account teen numbers */
						{
							i++;
							switch(*i)
							{
								case 0:
								{
									numChars += 3;
								} break;

								case 1: case 2:
								{
									numChars += 6;
								} break;

								case 3: case 4: case 8: case 9:
								{
									numChars += 8;
								} break;

								case 5: case 6:
								{
									numChars += 7;
								} break;

								case 7:
								{
									numChars += 9;
								} break;
							}
						} break;
					}
				} break;

				case 2:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 3;
						} break;

						case 1:
						{
							numChars += 6;
						} break;
					}
				} break;

				case 3: case 8:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 5;
						} break;

						case 1:
						{
							numChars += 6;
						} break;
					}
				} break;

				case 4: case 5:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 4;
						} break;

						case 1:
						{
							numChars += 5;
						} break;
					}
				} break;

				case 6:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 3;
						} break;

						case 1:
						{
							numChars += 5;
						} break;
					}
				} break;

				case 7:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 5;
						} break;

						case 1:
						{
							numChars += 7;
						} break;
					}
				} break;

				case 9:
				{
					switch(numDigits - j)
					{
						case 0: case 2:
						{
							numChars += 4;
						} break;

						case 1:
						{
							numChars += 6;
						} break;
					}
				} break;
			}
		}

		if (digits.size() == 3)
		{
			numChars += 7;
			iter1 = iter2 = digits.begin();
			iter1++;
			iter2++;
			iter2++;
			if (*iter1 != 0 || *iter2 != 0)
			{
				numChars += 3;
				}
		}

		else if (digits.size() == 4)
		{
			numChars += 8;
		}

		return numChars;
	}
};
