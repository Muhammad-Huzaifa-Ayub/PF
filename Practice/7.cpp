/*3D Warehouse Inventory

Problem:
A warehouse has 4 sections, each section has 5 shelves, each shelf stores 6 boxes. Use a 3D array:

Store box weights.

Find:

Total weight in each section.

Heaviest box in the warehouse.

Average weight per shelf.

Skills Practiced: Multi-dimensional traversal, accumulation, max/min search.*/



#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));

    int data[4][5][6];
    int sum[4];
    int box = 0;
    float avg[5];

    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            for ( int k = 0; k < 6; k++ )
            {
                data[i][j][k] = 700 + rand() % ( 1000 - 700 + 1 ); 
            }
        }
    }
    for ( int i = 0; i < 4; i++ )
    {
        sum[i] = 0;
        for ( int j = 0; j < 5; j++ )
        {
            for ( int k = 0; k < 6; k++ )
            {
               sum[i] += data[i][j][k]; 
            }
        }
    }
    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            for ( int k = 0; k < 6; k++ )
            {
                if ( data[i][j][k] > box )
                {
                    box = data[i][j][k];
                }
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
    avg[j] = 0;
    }
    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 5; j++ )
        {
            for ( int k = 0; k < 6; k++ )
            {
               avg[j] += data[i][j][k]; 
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
        avg[j] /= (4 * 6.0);
    }

    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl << "Total Weight in each Section : " << endl;
    for ( int i = 0; i < 4; i++ )
    {
       cout << "Sum of Section " << i+1 << " is : " << sum[i] << endl;
    }
    cout << endl << "--------------------------------------------------------" << endl;
    cout << endl << "Heaviest Box of all Sections is : " << box << endl << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Average per shelf is as follows : " << endl << endl;
    for ( int i = 0; i < 5; i++ )
    {
       cout << "Avg of shelf " << i+1 << " is : " << avg[i] << endl;
    }
    cout << endl << "--------------------------------------------------------" << endl;



    return 0;
}