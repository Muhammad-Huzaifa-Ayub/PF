/*Dynamic Seating Chart – Theater

Problem:
A theater has 10 rows and 15 seats per row.

Use a 2D array to represent seats (0 = empty, 1 = booked).

Implement:

Book a seat (update the array).

Cancel a booking.

Display all empty seats.

Count total available seats.

Skills Practiced: 2D arrays, conditional traversal, real-world mapping of indices.*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;


void ShowTheater(int data[10][15])
{
    cout << setw(6) << left << "Row";
    for (int j = 1; j <= 15; j++)
    {
        cout << setw(6) << left << "C" + to_string(j);
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << setw(6) << left << ("R" + to_string(i + 1));
        for (int j = 0; j < 15; j++)
        {
            cout << setw(6) << left << data[i][j];
        }
        cout << endl;
    }

    return;
}

void Booking(short int row,short int col,int data[][15])
{
    for ( int i = 0; i < 10; i++ )
    {
        for ( int j = 0; j < 15; j++ )
        {
            if (data[row][col] == 0 || data[row][col] == 1)
            {
                data[row][col] = 1;

            }
        }
    }


}

void Cancel(short int row,short int col,int data[][15])
{
    for ( int i = 0; i < 10; i++ )
    {
        for ( int j = 0; j < 15; j++ )
        {
            if (data[row][col] == 0 || data[row][col] == 1)
            {
                data[row][col] = 0;

            }
        }
    }


}

short int Count(short int row,short col,int data[][15])
{
    short int count = 0;
    for ( int i = 0; i < 10; i++ )
    {
        for ( int j = 0; j < 15; j++ )
        {
            if (data[row][col] == 0 )
            {
                count++;
            }
        }
    }

    return count;
}




int main()
{
    srand(time(0));

    int data[10][15];
    short int row;
    short int col;


    for ( int i = 0; i < 10; i++ ) // All Empty
    {
        for ( int j = 0; j < 15; j++ )
        {
            data[i][j] = 0;
        }
    }

    // for ( int i = 0; i < 10; i++ ) // Random
    // {
    //     for ( int j = 0; j < 15; j++ )
    //     {
    //         data[i][j] = rand() % 2;
    //     }
    // }

    while ( true )
    {
        short int choice;
        cout << endl << "--------- Theater Booking System ---------" << endl;
        cout << "Enter [1] to show Theater" << endl;
        cout << "Enter [2] to add Booking" << endl;
        cout << "Enter [3] to cancel Booking" << endl;
        cout << "Enter [4] to get available seat" << endl;
        cout << "Enter [0] to Exit" << endl;
        cout << "Enter your Choice : ";
        cin >> choice;

        if ( choice == 1 )
        {
            cout << endl << endl;
            ShowTheater(data);
        }
        else if ( choice == 2 )
        {
            cout  << endl << endl << "Enter seat row ( for booking ) : ";
            cin >> row;
            if ( !(row >= 1 && row <= 10) )
            {
                cout << endl << "Invalid row choice" << endl;
                continue;
            }
            cout << "Enter seat column ( for booking ) : ";
            cin >> col;
            if ( !(col >= 1 && col <= 15) )
            {
                cout << endl << "Invalid column choice" << endl;
                continue;
            }
            Booking(row-1,col-1,data);
        }
        else if ( choice == 3 )
        {
            cout  << endl << endl << "Enter seat row ( to cancel booking ) : ";
            cin >> row;
            if ( !(row >= 1 && row <= 10) )
            {
                cout << endl << "Invalid row choice" << endl;
                continue;
            }
            cout << "Enter seat column ( to cancel booking ) : ";
            cin >> col;
            if ( !(col >= 1 && col <= 15) )
            {
                cout << endl << "Invalid column choice" << endl;
                continue;
            }
            Cancel(row-1,col-1,data);
        }
        else if ( choice == 4 )
        {
            cout << endl  << "Total Available seats are : " << Count(row-1,col-1,data) << endl;
        }
        else if ( choice == 0 )
        {
            break;
        }
        else
        {
            cout << endl << "Invalid Choice !" << endl;
        }
    }

    return 0;
}