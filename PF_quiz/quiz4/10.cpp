#include <iostream>
#include <string>

using namespace std;

void showArray(int ar[], const int as, const int ds)
{
    if (as >= ds)
    {
        for (int j = 0; j < ds; j++)
        {
            cout << ar[j] << " ";
        }
        cout << endl;
    }
}


void removeDuplicates(int ar[], int &ds)
{
    if (ds == 0 || ds == 1)
        return;

    int index = 0; 

    for (int i = 1; i < ds; i++)
    {
        if (ar[i] != ar[index])
        {
            index++;
            ar[index] = ar[i];
        }
    }

    ds = index + 1; 
}

int main()
{
    const int as = 30;
    int a[as];
    int ds = 0;

    int array[] = {0,0,0,3,4,4,5,8,8,8,8,8,8,9,9,9};
    int array_size = 16;

    for (int i = 0; i < array_size; i++)
    {
        a[i] = array[i];
        ds++;
    }

    cout << "Original array:" << endl;
    showArray(a, as, ds);

    removeDuplicates(a, ds);

    cout << "\nArray after removing duplicates:" << endl;
    showArray(a, as, ds);

    return 0;
}
