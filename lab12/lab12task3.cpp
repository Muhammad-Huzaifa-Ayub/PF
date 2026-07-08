#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

string get_colour(int suit)
{
	if ( suit == 1 || suit == 2 ) return "Red";
	if ( suit == 3 || suit == 4 ) return "Black";
}


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

	int rank1 = rand() % 13 + 1;
	int rank2 = rand() % 13 + 1;

	int suit1 = rand() % 4 + 1;
	int suit2 = rand() % 4 + 1;

	cout << "Card 1 : " << get_rank(rank1) << " of " << get_suit(suit1);
	cout << endl << endl;
	cout << "Card 2 : " << get_rank(rank2) << " of " << get_suit(suit2);
	cout << endl;

	if ( rank1 == rank2 )
		cout << "\nThe both cards have same [Rank]." ;

	if ( suit1 == suit2 )
		cout << "\nThe both cards have same [suit].";

	if ( get_colour(suit1) == get_colour(suit2) )
		cout << "\nThe both cards have same [colour].";

	if( abs(rank1-rank2)== 1)
		cout << "\nThe cards in sequence.";
	
	cout << endl;

	return 0;
}