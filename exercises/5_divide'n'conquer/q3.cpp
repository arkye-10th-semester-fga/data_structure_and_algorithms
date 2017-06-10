#include <iostream>
#include <vector>

using namespace std;

void create_cards(vector<int> &cards);
int check_equivalence(vector<int> &cards);
int check_right_cards_equivalence(vector<int> &cards,
	vector<int> &right_cards);
unsigned int count_occurrences(vector<int> &cards, int card);

const int INEQUIVALENT = -1;

int main()
{
	vector<int> cards;
	create_cards(cards);

	int card = check_equivalence(cards);

	if(card == INEQUIVALENT)
	{
		cout << "There are no set of equivalence with more";
		cout << " than the half of the cards." << endl;
	}
	else
	{
		cout << "The equivalence of the card type " << card;
		cout << " is more than the half of the cards." << endl;
	}

	return 0;
}

void create_cards(vector<int> &cards)
{
	const int END_OF_INPUT = 0;
	cout << "Insert a list of card types (positive integers)." << endl;
	cout << "End the insertion with " << END_OF_INPUT	<< "." << endl;
	bool creation_is_done = false;
	while(!creation_is_done)
	{
		int number = 0;
		cin >> number;
		if(number != END_OF_INPUT)
		{
			cards.push_back(number);
		}
		else
		{
			cout << endl;
			creation_is_done = true;
		}
	}
}

int check_equivalence(vector<int> &cards)
{
	int card = INEQUIVALENT;
	if(cards.size() == 1)
	{
		card = cards[0];
	}
	else if(cards.size() == 2)
	{
		if(cards[0] == cards[1])
		{
			card = cards[0];
		}
	}
	else
	{
		unsigned int half = cards.size()/2;
		vector<int> left_cards(cards.begin(), cards.begin() + half);
		vector<int> right_cards(cards.begin() + half, cards.end());

		int left_card = check_equivalence(left_cards);

		if(left_card != INEQUIVALENT)
		{
			if(count_occurrences(cards, left_card) > cards.size()/2)
			{
				card = left_card;
			}
			else
			{
				card = check_right_cards_equivalence(cards, right_cards);
			}
		}
		else
		{
			card =	check_right_cards_equivalence(cards, right_cards);
		}
	}
	return card;
}

int check_right_cards_equivalence(vector<int> &cards, vector<int> &right_cards)
{
	int right_card = check_equivalence(right_cards);
	if(right_card != INEQUIVALENT)
	{
		if(count_occurrences(cards, right_card) > cards.size()/2)
		{
			return right_card;
		}
	}
	return INEQUIVALENT;
}

unsigned int count_occurrences(vector<int> &cards, int card)
{
	unsigned int occurrences = 0;
	for(int other_card : cards)
	{
		if(card == other_card)
		{
			++occurrences;
		}
	}
	return occurrences;
}
