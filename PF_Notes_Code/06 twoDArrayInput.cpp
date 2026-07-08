#include <iostream>
#include <string>
#include <array>

using namespace std;

array<array<int,5>,3> aget();
void ashow(array<array<int,5>,3> a);

int main()
{
	array<array<int,5>,3> v;

    cout << "Please enter 15 values: " << endl;
    v = aget();
	
    cout << "You entered values: " << endl;
    ashow(v);
	return 0;
}

array<array<int,5>,3> aget()
{
    array<array<int,5>,3> ar;
    int j = 0;
    while(j < 3)
    {
        int k = 0;
        while(k < 5)
        {
            cin >> ar[j][k];
            k = k + 1;
        }
        j = j + 1;
    }
    return ar;
}

void ashow(array<array<int,5>,3> data)
{
    int j = 0;
    while(j < 3)
    {
        int k = 0;
        while(k < 5)
        {
            cout << data[j][k] << "  ";
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
}
