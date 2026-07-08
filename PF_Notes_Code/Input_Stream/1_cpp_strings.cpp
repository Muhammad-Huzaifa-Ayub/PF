#include <iostream>
#include <string>

using namespace std;

int main() 
{
    double num = 123.456;
    string str = to_string(num); // Converts double to string
    cout << "String: " << str << endl;

    double reversedNum = stod(str); // Converts string back to double
    cout << "Double: " << reversedNum << endl;

    return 0;
}
