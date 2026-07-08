#include<iostream>
#include<string>

using namespace std;

int main()
{
	char suit;
	cout << "Enter a single character representing a card suit ( D,H,S or C) : ";
	cin >> suit;

	if ( suit == 'D' || suit == 'H')
		cout << "The suit colour is [Red].";
	if ( suit == 'S' || suit == 'C')
		cout << "The suit colur is [Black].";
	else
		cout << "Invalid Choice!";


	return 0;
}