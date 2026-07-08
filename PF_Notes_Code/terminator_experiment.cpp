#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


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
    const int as = 200;
    
    int a[as];
    makeArrayEmpty(a, as);
    
 
srand(time(0));

for (int i = 0; i < as - 1; i++)
{
    a[i] = rand() % 200 + 1;
}
a[as - 1] = terminator;

    showArray(a, as);
    
    return 0;
}