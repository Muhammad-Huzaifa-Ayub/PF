#include <iostream>
#include<string>


using namespace std;

int main() 
{
    int array[17] = {9,17,22,34,8,54,78,45,89,56,62,73,39,81,12,66,98};
    int num = 0;
    cout << "Enter a number for closest check : ";
    cin >> num;
    cout << endl << endl;
    int closest = array[0];
    for ( int i = 0; i < 17; i++ )
    {
        if ( abs(array[i] - num) < abs(closest - num) )
        {
            closest = array[i];
        }
    }
    cout << "The closest number on array is : " << closest << endl;

    return 0;
}