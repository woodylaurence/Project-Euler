/*
 * Proj_59.cpp
 *
 *  Created on: Oct 23, 2012
 *      Author: Laurence
 *
 *      Problem: Decipher text file using byte-wise XOR decryption
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Prob59
{
	int main(void)
	{
		ifstream *input;
		vector<int> numbers, decodedNumbers;
		vector<char> letters;
		bool decoded = false;
        int tmpNum, *key, k, length, total = 0, attempt = 1;
		char answer;
		string buffer;
		stringstream sstream;

		key = new int [3];
		input = new ifstream;
		input->open("cipher.txt");

		if (input->is_open())
		{
			getline(*input, buffer);
			sstream.str(buffer);

			while(sstream >> tmpNum)
			{
				numbers.push_back(tmpNum);

				if (sstream.peek() == ',')
				{
					sstream.ignore();
				}
			}

			for (k = 0; k < 3; k++)
			{
				key[k] = 97;
			}

			for (key[0] = 97; key[0] < 123 && !decoded; key[0]++)
			{
				for (key[1] = 97; key[1] < 123 && !decoded; key[1]++)
				{
					for (key[2] = 97; key[2] < 123 && !decoded; key[2]++)
					{

						k = 0;

						//cout << "Decrypted message:" << endl;
						for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
						{
							//cout << *iter << ",";
							decodedNumbers.push_back(*iter ^ key[k%3]);
							letters.push_back(static_cast<char>(decodedNumbers.back()));				// Converts the integer to letter
							k++;
						}

						//cout << endl;

						length = (int)numbers.size();

						for (k = 0; k < length - 2; k++)
						{
							if ((letters.at(k) == 't' || letters.at(k) == 'T') && (letters.at(k+1) == 'h' || (letters.at(k+1) == 'H')) && (letters.at(k+2) == 'e' || letters.at(k+2) == 'E'))
							{
								for (vector<char>::iterator iter = letters.begin(); iter != letters.end(); iter++)
								{
									cout << *iter;
								}
								cout << endl << endl << "key[0] = " << key[0] << ", key[1] = " << key[1] << ", key[2] = " << key[2] << endl;
								cout << "Is this the correct decryption?" << endl;
								cin >> answer;
								if (answer == 'y' || answer == 'Y')
								{
									total = totalCharValues(decodedNumbers);
									decoded = true;
								}
								break;
							}
						}

						decodedNumbers.clear();
						letters.clear();

						//getchar();

						attempt++;
					}
				}
			}

			cout << "Answer: " << total << endl;
		}

		else
		{
			cout << "Sorry, the requested file could not be found.\nExiting..." << endl;
			exit(EXIT_FAILURE);
		}

		return 0;
	}

	int totalCharValues(vector<int> tmpDecodedNumbers)
	{
		int tmpTotal = 0;

		for (vector<int>::iterator iter = tmpDecodedNumbers.begin(); iter != tmpDecodedNumbers.end(); iter++)
		{
			tmpTotal += *iter;
		}

		return tmpTotal;
	}
};
