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
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

    cout << endl << endl << endl;
    cout << "Transposed Matrix is as below : " << endl;
    for( int i = 0; i < 5; i++ )
    {
        cout << endl;
        for( int j = 0; j < 5; j++ )
        {
            cout << array[i][j] << "  ";

        }
    }
    cout << endl << endl << endl;




    return 0;
}