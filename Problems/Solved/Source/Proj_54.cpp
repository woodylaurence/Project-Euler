/*
 * Proj_54.cpp
 *
 *  Created on: Oct 18, 2012
 *      Author: Laurence
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Card
{
public:
	Card();
	Card(string cardDetails);
	~Card();
	int getRank();
	int getSuit();

private:
	int rank, suit;
};

class Hand
{
public:
	Hand();
	Hand(vector<Card> tmpCards);
	~Hand();
	void rankHand();
	vector<Card> getCards();
	void orderCards(bool handRanked);
	void printCards();
	bool operator > (Hand tmpHand);
	bool operator == (Hand tmpHand);
	bool nonEqualCards(Hand tmpHand, int i);

private:
	vector<Card> cards;
	bool isFlush, isStraight;
	int numMultiCard1, numMultiCard2, valueMultiCard1, valueMultiCard2, handRank;
};

class Prob54
{
	int main(void)
	{
		ifstream input;
		char *round;
		int numHandsPlayer1Won = 0;
		string *tmpCardInfo, buffer;
		vector<Card> player1Cards, player2Cards;
		Hand *player1, *player2;

		round = new char [32];
		tmpCardInfo = new string [10];

		input.open("poker_hands.txt");

		if (input.is_open())
		{
			//while(!input.eof())						// Not sure why this doesn't work, it doesn't recognise the last line of the file as the end (perhaps)
			for (int j = 0; j < 1000; j++)
			{
				getline(input, buffer);
				for (int i = 0; i < 10; i++)
				{
					tmpCardInfo[i] = buffer.substr(3*i, 2);
				}

				for (int i = 0; i < 5; i++)
				{
					player1Cards.push_back(Card(tmpCardInfo[i]));
					player2Cards.push_back(Card(tmpCardInfo[i+5]));
				}

				player1 = new Hand(player1Cards);
				player2 = new Hand(player2Cards);

				if (*player1 > *player2)
				{
					numHandsPlayer1Won++;
				}

				buffer.clear();
				player1Cards.clear();
				player2Cards.clear();
				delete player1;
				delete player2;
			}

			cout << "Player 1 won " << numHandsPlayer1Won << " hands." << endl;
		}

		else
		{
			cout << "Error, could not open file." << endl << "Exiting..." << endl;
		}

		return 0;
	}
};

Card :: Card()
{
	this->rank = 0;
	this->suit = 0;
}

Card :: ~Card()
{

}

Card :: Card(string cardDetails)
{
	string tmpRank, tmpSuit;

	tmpRank = cardDetails.substr(0, 1);
	tmpSuit = cardDetails.substr(1, 1);

	if (tmpRank == "T")
	{
		this->rank = 10;
	}
	else if (tmpRank == "J")
	{
		this->rank = 11;
	}
	else if (tmpRank == "Q")
	{
		this->rank = 12;
	}
	else if (tmpRank == "K")
	{
		this->rank = 13;
	}
	else if (tmpRank == "A")
	{
		this->rank = 14;
	}
	else
	{
		this->rank = atoi(tmpRank.c_str());
	}


	if (tmpSuit == "S")
	{
		this->suit = 1;
	}

	else if (tmpSuit == "H")
	{
		this->suit = 2;
	}

	else if (tmpSuit == "C")
	{
		this->suit = 3;
	}

	else if (tmpSuit == "D")
	{
		this->suit = 4;
	}
}

int Card :: getRank()
{
	return this->rank;
}

int Card :: getSuit()
{
	return this->suit;
}

Hand :: Hand()
{
	handRank = 0;
	isFlush = false;
	isStraight = false;
	numMultiCard1 = 0;
	numMultiCard2 = 0;
	valueMultiCard1 = 0;
	valueMultiCard2 = 0;
	cout << "Error, default Hand constructor called." << endl;
}

Hand :: ~Hand()
{
	this->cards.clear();
}

Hand :: Hand(vector<Card> tmpCards)
{
	this->cards = tmpCards;
	this->orderCards(false);

	this->isStraight = true;
	this->isFlush = true;
	this->numMultiCard1 = 1;
	this->numMultiCard2 = 1;
	this->valueMultiCard1 = 0;
	this->valueMultiCard2 = 0;
	this->handRank = 0;

	this->rankHand();
	this->orderCards(true);
}

void Hand :: orderCards(bool handRanked)			// This now has bool; false means order cards numerically to aid hand ranking, true means hand has been ranked, move rank to beginning of hand, i.e. move pair to front of hand regardless of card value, this aids determining winner in case of draw
{
	vector<Card>::iterator iter, jter;
	vector<Card> tmp, tmp2;
	Card *tmpCard;

	if (!handRanked)
	{
		for (int i = 0; i < 5; i++)
		{
			tmpCard = new Card();
			for (iter = this->cards.begin(); iter != this->cards.end(); iter++)
			{
				if (iter->getRank() > tmpCard->getRank())
				{
					*tmpCard = *iter;
					jter = iter;
				}
			}
			tmp.push_back(*tmpCard);
			this->cards.erase(jter);

			delete tmpCard;
		}
		this->cards = tmp;
	}

	else
	{
		switch(this->handRank)
		{
			case 2: case 3: case 4: case 8:						// Hands of only one multiCard (pair, three of kind, four of kind)
			{
				for (iter = this->cards.begin(); iter != this->cards.end(); iter++)					// Create two temporary vectors, one containing multi cards, the other all the other cards (in numerical order)
				{
					if (iter->getRank() == this->valueMultiCard1 || iter->getRank() == this->valueMultiCard2)		// Since multiCard1 > multiCard2 this statement will keep that order
					{
						tmp.push_back(*iter);
					}

					else
					{
						tmp2.push_back(*iter);
					}
				}

				for (jter = tmp2.begin(); jter != tmp2.end(); jter++)			// Merge the two vectors together (having the multi-card at the front)
				{
					tmp.push_back(*jter);
				}

				this->cards = tmp;

			} break;

			default:
			{
				// Do nothing to other hands which do not require a second sorting
			} break;
		}
	}

	return;
}

void Hand :: rankHand()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->cards.at(i).getRank() != this->cards.at(i+1).getRank() + 1)
		{
			this->isStraight = false;
		}

		if (this->cards.at(i).getSuit() != this->cards.at(i+1).getSuit())
		{
			this->isFlush = false;
		}

		if (this->cards.at(i).getRank() == this->cards.at(i+1).getRank() && (this->numMultiCard1 == 1 || this->cards.at(i).getRank() == this->cards.at(i-1).getRank()))
		{
			this->valueMultiCard1 = this->cards.at(i).getRank();					// I believe that multiCard1 has a higher value than multiCard2
			this->numMultiCard1++;
		}

		else if (this->cards.at(i).getRank() == this->cards.at(i+1).getRank() && this->numMultiCard1 != 1 && this->cards.at(i).getRank() != this->cards.at(i-1).getRank())
		{
			this->valueMultiCard2 = this->cards.at(i).getRank();
			this->numMultiCard2++;
		}
	}


	if (this->isStraight)
	{
		if (this->isFlush)
		{
			if (this->cards.front().getRank() == 14)
			{
				this->handRank = 10;							// Royal Flush
			}

			else
			{
				this->handRank = 9;								// Straight Flush				// May need to check that front().rank is a valid card?!
			}
		}

		else
		{
			this->handRank = 5;									// Straight
		}
	}

	else if (this->isFlush)
	{
		this->handRank = 6;										// Flush
	}

	else														// Break into switch statement for number of multi-cards
	{
		switch(this->numMultiCard1)
		{
			case 4:
			{
				this->handRank = 8;								// Four of a Kind
			} break;

			case 3:
			{
				switch(this->numMultiCard2)
				{
					case 2:
					{
						this->handRank = 7;						// Full House
					} break;

					case 1:
					{
						this->handRank = 4;						// Three of a Kind
					} break;

					default:
					{
						//cout << "Something went wrong there! (numMultiCard1 = 3)" << endl;
						exit(EXIT_FAILURE);
					} break;
				}
			} break;

			case 2:
			{
				switch(this->numMultiCard2)
				{
					case 3:
					{
						this->handRank = 7;						// Full House
					} break;

					case 2:
					{
						this->handRank = 3;						// Two Pairs
					} break;

					case 1:
					{
						this->handRank = 2;						// One Pair
					} break;

					default:
					{
						cout << "Something went wrong there! (numMultiCard1 = 2)" << endl;
						exit(EXIT_FAILURE);
					} break;
				}
			} break;

			case 1:
			{
				this->handRank = 1;								// High Card
			} break;

			default:
			{
				cout << "Something went wrong there! (Switching numMultiCard)" << endl;
			} break;
		}
	}

	return;
}

bool Hand :: operator == (Hand tmpHand)
{
	bool isEqual = false;

	if (this->handRank == tmpHand.handRank)
	{
		isEqual = true;
	}

	return isEqual;
}

bool Hand :: operator > (Hand tmpHand)
{
    bool isGreater = false;

	if (this->handRank > tmpHand.handRank)
	{
		isGreater = true;
	}

	else if (this->handRank < tmpHand.handRank)
	{
		isGreater = false;
	}

	else
	{
		switch (this->handRank)
		{
			case 9: case 5:								// These hands (straights) do not require to cycle through all cards, since the first card determines the hand
			{
				if (this->cards.at(0).getRank() > tmpHand.cards.at(0).getRank())
				{
					isGreater = true;
				}

				else if (this->cards.at(0).getRank() < tmpHand.cards.at(0).getRank())
				{
					isGreater = false;
				}

				else
				{
					cout << "Something went wrong there. (Hand::operator > (straights))" << endl;
					exit(EXIT_FAILURE);
				}
			} break;

			case 6: case 1:
			{
				isGreater = this->nonEqualCards(tmpHand, 0);
			} break;

			case 8: case 7: case 4: case 3: case 2:
			{
				if (this->valueMultiCard1 > tmpHand.valueMultiCard1)
				{
					isGreater = true;
				}

				else if (this->valueMultiCard1 < tmpHand.valueMultiCard1)
				{
					isGreater = false;
				}

				else
				{
					if (this->numMultiCard2 != 1)
					{
						if (this->valueMultiCard2 > tmpHand.valueMultiCard2)
						{
							isGreater = true;
						}

						else if (this->valueMultiCard2 < tmpHand.valueMultiCard2)
						{
							isGreater = false;
						}

						else
						{
							isGreater = this->nonEqualCards(tmpHand, (this->numMultiCard1 + this->numMultiCard2));
						}
					}

					else
					{
						isGreater = this->nonEqualCards(tmpHand, this->numMultiCard1);
					}
				}
			} break;
		}
	}

	return isGreater;
}

bool Hand :: nonEqualCards(Hand tmpHand, int i)
{
	bool isGreater = false, foundNonEqualCards = false;

	while (!foundNonEqualCards)
	{
		if (this->cards.at(i).getRank() > tmpHand.cards.at(i).getRank())
		{
			isGreater = true;
			foundNonEqualCards = true;
		}

		else if (this->cards.at(i).getRank() < tmpHand.cards.at(i).getRank())
		{
			isGreater = false;
			foundNonEqualCards = true;
		}

		else
		{
			i++;
		}
	}

	return isGreater;
}

void Hand :: printCards()
{
	for (vector<Card>::iterator iter = this->cards.begin(); iter != this->cards.end(); iter++)
	{
		cout << iter->getRank() << " of " << iter->getSuit() << "\t";
	}

	cout << endl;
	return;
}
