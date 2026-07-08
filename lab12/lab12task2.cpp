#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;


string get_suit(int suit)
{
	if ( suit == 1 )
		return "Diamond.";
	if ( suit == 2 )
		return "Heart.";
	if ( suit == 3 )
		return "Spade.";
	if ( suit == 4 )
		return "Club.";
}

string get_rank(int rank)
{
	if ( rank == 1 ) return "Ace";
	if ( rank == 11 ) return "Jack";
	if ( rank == 12 ) return "Queen";
	if ( rank == 13 ) return "King";
	else
	return to_string(rank);
}

int main()
{
	srand(time(0));

	int rank = rand() % 13 + 1;
	int suit = rand() % 4 + 1;

	cout << "Card : " << get_rank(rank) << " of " << get_suit(suit);
	cout << endl;

	return 0;
}