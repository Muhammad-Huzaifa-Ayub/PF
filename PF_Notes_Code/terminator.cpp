#include <iostream>
#include <string>

using namespace std;

const int terminator = -1;

void makeArrayEmpty(int ar[], const int as)
{
    if (as > 0)
    {
        ar[0] = terminator;
    }
    return;
}

void showArray(int ar[], const int as)
{
    for(int j=0; j<as && ar[j] != terminator; j+=1)
    {
        cout << ar[j] << endl;
    }
    return;
}

int main()
{
	const int as = 10;
    
    int a[as];
    makeArrayEmpty(a, as);
    
    a[0] = 99;
    a[1] = terminator;   
    a[1] = 88;
    a[2] = terminator;
    a[2] = 77;
    a[3] = terminator;
    a[3] = 55;
    a[4] = terminator;
    a[4] = 22;
    a[5] = terminator;
    a[5] = 11;
    a[6] = terminator;
    
    showArray(a, as);
    
	return 0;
}
