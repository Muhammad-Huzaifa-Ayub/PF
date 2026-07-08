#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
    srand(time(0));

    cout << "Enter [16] elements for 4*4 Matrix : " << endl;
    int array[4][4];

    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            array[i][j] = 10 + rand() % (99 - 10 + 1);

        }
    }
    for( int i = 0; i < 4; i++ )
    {
        cout << endl;
        for( int j = 0; j < 4; j++ )
        {
            cout << array[i][j] << "  ";

        }
    }

    cout << endl << "Row and colum sum of Matrix : ";
    for( int i = 0; i < 4; i++ )
    {
        cout << endl;
        int sum = 0;
        for( int j = 0; j < 4; j++ )
        {
            cout << array[i][j] << "  ";
            sum += array[i][j];

        }
        cout << " | "<< sum;
    }
    cout << endl;
    for( int i = 0; i < 4; i++ )
    {
        int sum = 0;
        for( int j = 0; j < 4; j++ )
        {
            sum += array[j][i];

        }
        cout << sum << "  ";
    }
    
    return 0;
}