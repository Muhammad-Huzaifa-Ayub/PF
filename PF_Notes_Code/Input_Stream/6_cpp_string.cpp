#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
    string name;
    string hobbies[3];
    
    cout << "enter your name ";
    getline(cin, name); // note it is not cin.getline
    cout << "enter your three hobbies, each end at *: ";
    for(int j=0; j<3; ++j)
    {
        getline(cin, hobbies[j], '*');
    }
    
    cout << "your name is: " << name << endl;
    cout << "your hobbies are " << endl;
    cout << "  " << char(42) << " " << hobbies[0] << endl;
    cout << "  " << char(247) << " " << hobbies[1] << endl;
    cout << "  " << char(250) << " " << hobbies[2] << endl;
        
	return 0;
}
