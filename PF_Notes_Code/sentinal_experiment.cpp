#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

void showArray1(int ar[], const int as)
{
    for(int j=0; j<as; j+=1)
    {
        cout << ar[j] << endl; 
    }
    return;
}

int main()
{
    srand(time(0));

	const int as = 1000;
    int a[as];

    for (int i = 0; i < 999 ; i=i+3 )
    {
        a[i] = rand() % 999 + 1;
    }

    makeArrayEmpty(a, as);
  
    for (int i = 0; i < 999 ; i=i+3 )
    {
        a[i] = rand() % 999 + 1;
    }
    
    showArray(a, as);
    showArray1(a, as);
    
    
	return 0;
}
