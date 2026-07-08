#include <iostream>
#include <string>

using namespace std;

const int sentinal = -1;

void makeArrayEmpty(int ar[], const int as)
{
    for(int j=0; j<as; j+=1)
    {
        ar[j] = sentinal;
    }
    return;
}

void showArray(int ar[], const int as)
{
    for(int j=0; j<as; j+=1)
    {
        if(ar[j] != sentinal)
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
    makeArrayEmpty(a, as);
    
    a[0] = 99;
    a[1] = 88;
    a[2] = 77;
    a[6] = 33;
    a[9] = 11;
    a[4] = 55;
    
    showArray(a, as);
    
    return 0;
}
