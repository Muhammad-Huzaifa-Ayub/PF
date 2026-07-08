#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
    srand(time(0));

    const int as1 = 3;
    const int as2 = 2;

    int array1[as1][as2];
    int array2[as2][as1];
    int result[as1][as1];

    for( int i = 0; i < as1; i++ )
    {
        for( int j = 0; j < as2; j++ )
        {
            array1[i][j] = 10 + rand() % (20 - 10 + 1);

        }
    }
    cout << endl << "Matrix 1 : ";
    for( int i = 0; i < as1; i++ )
    {
        cout << endl;
        for( int j = 0; j < as2; j++ )
        {
            cout << array1[i][j] << "  ";

        }
    }
    for( int i = 0; i < as2; i++ )
    {
        for( int j = 0; j < as1; j++ )
        {
            array2[i][j] = 10 + rand() % (20 - 10 + 1);

        }
    }
    cout << endl << endl << "Matrix 2 : ";
    for( int i = 0; i < as2; i++ )
    {
        cout << endl;
        for( int j = 0; j < as1; j++ )
        {
            cout << array2[i][j] << "  ";

        }
    }
    for( int i = 0; i < as1; i++ )
    {
        for( int j = 0; j < as1; j++ )
        {
            result[i][j] = 0;
            for (int k = 0; k < as2; k++)
            {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
    cout << endl << endl << "M1 * M2 : " << endl;
    for (int i = 0; i < as1; i++)
    {
        for (int j = 0; j < as1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}