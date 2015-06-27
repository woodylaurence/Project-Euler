/*
 * Proj_97.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <list>
#include "BigInt.hpp"

using namespace std;

class Prob97
{
	int main(void)
	{
        throw "Needs reimplementing";
		/*list<int> lastTenDigits;
		int length;

		lastTenDigits.push_back(1);

		for (int i = 0; i < 7830457; i++)
		{
			multiplyByTwo(&lastTenDigits);
		}

		BigInt *temp;

		temp = new BigInt(lastTenDigits);

		*temp = (*temp) * 28433;
		*temp = (*temp) + 1;

		length = temp->getNumDigits();

		cout << "Last 10 digits: "; temp->printValue(length - 10, 10); cout << endl;

		return 0;*/
	}

	void multiplyByTwo(list<int>* tenDigits)
	{
        int carry = 0, tmp;
        size_t size = tenDigits->size();

		for (list<int>::reverse_iterator rIter = tenDigits->rbegin(); rIter != tenDigits->rend(); rIter++)
		{
			tmp = (*rIter)*2 + carry;
			*rIter = tmp % 10;
			carry = tmp / 10;
		}

		if (carry != 0 && size < 10)
		{
			tenDigits->push_front(carry);
		}

		return;
	}

	void printNumber(list<int> number)
	{
		for (list<int>::iterator iter = number.begin(); iter != number.end(); iter++)
		{
			cout << *iter;
		}
		cout << endl;

		return;
	}
};
