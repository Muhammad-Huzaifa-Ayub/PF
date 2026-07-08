#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> // for pow

using namespace std;

int main()
{
    int logsize;
    long  long arraysize;
    cout << "enter log of array size (initally 0 to 20, but later any relativlely large int value 30 to 40) ";
    cin >> logsize;
    arraysize = pow(2, logsize);
    
    int *p;
    p = new (nothrow) int[arraysize]; // perfactly OK to use variable in size here, mean when allocating memory at heap
    if (p != nullptr) // nullptr is like address 0, no memory allocated
    {
        cout << "enjoy array here of your size" << endl;
    }
    else
    {
        cout << "unable to allocate too much required memory" << endl;
    }
    
    delete[] p; // it is mandotory for heap memory
    
	return 0;
}
