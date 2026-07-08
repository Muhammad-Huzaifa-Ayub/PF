#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{

    stringstream ss("The quick brown fox jumps over a lazy dog.");
    string word;


    cout << " the first string stream is : " << endl;
    while ( ss >> word )
    {
        cout << word << endl;
    }
    cout << endl;

    ss.clear();

    ss.str("the job requires extra pluck zeal from every young wage earner.");

    cout << " the second string stream is : " << endl;

    while ( ss >> word )
    {
        cout << word << endl;
    }



    return 0;
}