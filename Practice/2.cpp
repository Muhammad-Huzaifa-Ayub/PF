#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
    srand(time(0));

    cout << "Enter [25] elements for 5*5 Matrix : " << endl;
    int array[5][5];

    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 5; j++ )
        {
            array[i][j] = 10 + rand() % (99 - 10 + 1);

        }
    }
    for( int i = 0; i < 5; i++ )
    {
        cout << endl;
        for( int j = 0; j < 5; j++ )
        {
            cout << array[i][j] << "  ";

        }
    }
    int sum = 0;
    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 5; j++ )
        {
            if ( i == j )
            {
                sum += array[i][j];
            }

        }
    }
    cout << endl << endl << "Primary Diagonal sum = " << sum << endl;
    sum = 0;
    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 5; j++ )
        {
            if ( i+j == 5-1 )
            {
                sum += array[i][j];
            }

        }
    }
    cout << endl << "Secondry Diagonal sum = " << sum << endl; 

    return 0;
}
