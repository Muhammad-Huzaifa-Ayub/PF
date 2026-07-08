#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>


using namespace std;

int main()
{
    srand(time(0));
    int array[10];
    int count[10];
    cout << "Putting [10] integer random values in the arrary Ranging {21-30} : " << endl;
    for ( int i = 0; i < 10; i++ )
    {
        array[i] = 21 + rand() % (31 - 21);
    }
    for ( int i = 0; i < 10; i++ )
    {
        cout << array[i] << " ";
    }
    for ( int i = 0; i < 10; i++ )
    {
        count[i] = 0;
    }
    for ( int i = 0; i < 10; i++ )
    {   
        for ( int j = 21; j < 31; j++ )
        {   
            if ( array[i] == j )
            {
                count[j - 21]++;
            }
        }
    }
    cout << endl;
    for ( int j = 0; j < 10; j++ )
    {
        cout << "Frequency of " << j+21 << " is " << count[j] << endl; 
    }

    return 0;
}
