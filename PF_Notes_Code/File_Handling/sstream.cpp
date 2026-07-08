#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string an = "550";
	string bn = "230";
	cout << an+bn << endl;
	
	stringstream ss;
	ss << an << endl << bn << endl;
	
	cout << "|\n" << ss.str() << "|\n";
	
	double d1, d2;
	ss >> d1 >> d2;
	cout << d1+d2 << endl;

	cout << "|\n" << ss.str() << "|\n";

	ss.str(""); // make stream's string emply
	
	return 0;
}
