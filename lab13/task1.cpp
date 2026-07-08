#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<array>
#include<ctime>
#include<cstdlib>
#include<iomanip>


using namespace std;


void showtable(int sem[],string prog[],float mean[][8])
{
    cout << "Program" << setw(10);
    for ( int i = 0; i < 8; i++ )
    {
        cout  << setw(9) << right << "Sem" << sem[i];
    }
    cout << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << setw(10) << left << prog[i];
        for (int j = 0; j < 8; j++ )
        {
            cout << setw(10) << right << fixed << setprecision(2) << mean[i][j];
        }
       cout << endl;
    }
}


void max(string prog[],float mean[][8])
{   
    float max[5];
    for ( int i = 0; i < 5; i++ )
    {
        max[i] = mean[i][0];
        for ( int j = 0; j < 8; j++ )
        {
            if ( mean[i][j] > max[i])
            {
                max[i] = mean[i][j];
            }
        }
    }
    for ( int i = 0; i < 5; i++ )
    {
        cout << "Max for " << prog[i] << " = " << max[i] << endl;
    }
}

void min(string prog[],float mean[][8])
{   
    float min[5];
    for ( int i = 0; i < 5; i++ )
    {
        min[i] = mean[i][0];
        for ( int j = 0; j < 8; j++ )
        {
            if ( mean[i][j] < min[i])
            {
                min[i] = mean[i][j];
            }
        }
    }
    for ( int i = 0; i < 5; i++ )
    {
        cout << "Min for " << prog[i] << " = " << min[i] << endl;
    }
}


void showtable_Reverse_with_average(int sem[],string prog[],float mean[][8])
{
    float avg = 0.00;
    float sum = 0.00;
    cout << "Semester" << setw(10);
    for ( int i = 0; i < 5; i++ )
    {
        cout  << setw(10) << right << prog[i];
    }
    cout  << setw(16) << right << "R-Average";
    cout << endl;
    for ( int i = 0; i < 8; i++ )
    {
        sum = 0;
        cout << setw(10) << left << "Semester" << setw(2) << sem[i];
        for (int j = 0; j < 5; j++ )
        {
            cout << setw(10) << right << fixed << setprecision(1) << mean[j][i];
            sum += mean[j][i];
        }
        avg = sum / 5;
        cout << setw(13) << right << fixed << setprecision(2) << avg;
       cout << endl;
    }
    cout << endl;
    cout << setw(13) << left << "C-Average";
    for ( int i = 0; i < 5; i++ )
    {
        sum = 0;
        for (int j = 0; j < 8; j++ )
        {
            sum += mean[i][j];
        }
        avg = sum / 8;
        cout << setw(10) << right << fixed << setprecision(2) << avg;
    }
}








int main()
{
    srand(time(0));
    string prog[5] = {"CS","CY","IT","DS","SE"};
    int sem[8] = {1,2,3,4,5,6,7,8};

    float mean[5][8];
    for ( int i = 0; i < 5; i++ )
    {
        for ( int j = 0; j < 8; j++ )
        {
            mean[i][j] = 52.60 + ( rand() % 22);
        }
    }
    cout << endl;
    showtable(sem,prog,mean);
    cout << endl;
    cout << "=================<<<< MAX >>>>===============";
    cout << endl;
    max(prog,mean);
    cout << "=================<<<< MIN >>>>===============";
    cout << endl;
    min(prog,mean);
    cout << "=============================================";
    cout << endl << endl;
    showtable_Reverse_with_average(sem,prog,mean);


    return 0;
}