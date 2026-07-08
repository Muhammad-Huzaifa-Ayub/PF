#include <iostream>
#include <string>

using namespace std;


void showArray(int ar[], const int as, const int ds)
{
    if (as >= ds)
    {
        for(int j=0; j<ds; j+=1)
        {
            cout << ar[j] << endl;
        }
    }
    return;
}

int main()
{
	const int as = 10;
    
    int a[as];
	int ds = 0; // implicitly makes array empty, no need to call the function makeArrayEmpty  >> ds - Data Size 
    
    a[0] = 99;
    ds+=1;   
    a[1] = 88;
    ds+=1;   
    a[2] = 77;
    ds=2; // assignment   
    a[3] = 55;
    ds+=1;
    a[4] = 33;
    ds+=1;   
    a[5] = 22;
    ds+=1;   
    a[6] = 11;
    ds+=1;   
    
    showArray(a, as ,ds);
    
	return 0;
}
