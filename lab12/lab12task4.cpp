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

	// Generating hands

	int rank1 = rand() % 13 + 1;
	int rank2 = rand() % 13 + 1;
	int rank3 = rand() % 13 + 1;

	int suit1 = rand() % 4 + 1;
	int suit2 = rand() % 4 + 1;
	int suit3 = rand() % 4 + 1;

	// Display hands

	cout << "Card 1 : " << get_rank(rank1) << " of " << get_suit(suit1);
	cout << endl << endl;
	cout << "Card 2 : " << get_rank(rank2) << " of " << get_suit(suit2);
	cout << endl;
	cout << "Card 3 : " << get_rank(rank3) << " of " << get_suit(suit3);
	cout << endl;

	// Extract ranks

	int score = 0;

	if ( rank1 == rank2 && rank2 == rank3 && rank1 == rank3 )
	{
		score = 10;
		cout << "\nThree of a Kind - 10 points" << endl;
	}
	else if ( rank1 == rank2 || rank2 == rank3 || rank1 == rank3 )
	{
		score = 5;
	 	cout << "\nPair - 5 points" << endl;
	}
	else if ( suit1 == suit2 && suit2 == suit3 && suit1 == suit3 )
	{
		score = 3;
		cout << "\nFlush - 3 points" << endl;
	}
	else if ( score == 0 )
	{
        cout << "\nHigh Card - 0 points" << endl;
	}

    cout << "\nThe final score is : " << score << "." << endl;


	return 0;
}