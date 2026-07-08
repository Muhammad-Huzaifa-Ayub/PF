#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<array>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<fstream>


using namespace std;


void show(int data[2][9][12],short int gender,short int month,short int outlet[9])
{
    int avg[2][9][12];

    for ( int i = 0; i < 2; i++ )
    {
        avg[0][0][0] = 0;
        for ( int j = 0; j < 9; j++ )
        {
            for ( int k = 0; k < 12; k++ )
            {
                avg[i][j][k] += data[i][j][k]; 
            }
        }
        
    }


    int avg1[9];
    for ( int k = 0; k < 9; k++ )
    {
        avg1[0] = 0;
        avg1[k] += data[0][k][0]; 
    }
    cout << "Gender :  " << gender << endl;
    cout << "Month : " << month << endl;
    cout << setw(10) << left << "Outlet  #";
    cout << setw(10) << right << "Month Count ";
    cout << setw(10) << right << "Progress " << endl;
    for ( int i = 0; i < 9; i++ )
    {
        cout << setw(10) << left << outlet[i];
        cout << setw(10) << right << data[0][i][0];
        if ( avg[0][i][0]/216 < avg1[i]/9 )
        {
            cout <<"     Above Average";
        }
        else 
        {
            cout <<"     below Average";
        }
        cout << endl;

    }

    return;


}








int main()
{
    srand(time(0));

    short int gender;
    short int month;
    cout << "Gender: Male or Female ( 1 or 2 ) : ";
    cin >> gender;
    cout << "Month: ";
    for (int i = 1; i < 12; i++ )
    {
        cout << i << " or ";
    }
    cout << "12 : ";
    cin >> month;


    string  genders[2] = {"Male", "Female"};
    short int outlets[9] = {1,2,3,4,5,6,7,8,9};
    short int months[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int data[2][9][12];

    for ( int i = 0; i < 2; i++ )
    {
        for ( int j = 0; j < 9; j++ )
        {
            for ( int k = 0; k < 12; k++ )
            {
                data[i][j][k] = 1000 + rand() % (10000 - 1000 + 1);
            }
        }

    }
    
    
    show (data,gender,month,outlets);






    return 0;
}


