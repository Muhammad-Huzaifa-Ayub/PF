#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int *p;
    p = new int[11];
    
    cout << "Enter 11 values" << endl;
    for(int j=0; j<11; ++j)
    {
        cin >> p[j];
    }
    
    cout << endl << "You entered" << endl;
    for(int j=0; j<11; ++j)
    {
        cout << p[j] << endl;
    }

    cout << endl << "See code and the following output" << endl;
    p = p+5; // as p as variable, so value can be changed
    for(int j=-5; j<=5; ++j)
    {
        cout << p[j] << endl;
    }

    p = p-5; // must take back to original adress before delete
    delete[] p; // it is mandotory for heap memory
    
	return 0;
}
