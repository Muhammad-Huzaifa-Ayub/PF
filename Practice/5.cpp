/*3D Array – Student Marks Analysis

Problem:
You have 3 classes, each with 4 students, and each student has marks in 5 subjects. Store the data in a 3D array and:

Compute the total and average marks per student.

Find the highest mark in each subject across all classes.

Identify the class with the highest average marks.

Skills Practiced: 3D indexing, aggregation, traversal across multiple dimensions.*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));

    int data[3][4][5];

    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 4; j++ )
        {
            for ( int k = 0; k < 5; k++ )
            {
                data[i][j][k] = 50 + rand() % (100 - 50 + 1); 
            }
        }
    }
    int sum[3][4];
    float avg[3][4];
    float cls[3];
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 4; j++ )
        {
            sum[i][j] = 0;
            for ( int k = 0; k < 5; k++ )
            {
               sum[i][j] += data[i][j][k]; 
            }
        }
    }
    for ( int i = 0; i < 3; i++ )
    {
        avg[i][0] = 0;
        for ( int j = 0; j < 4; j++ )
        {
            avg[i][j] = sum[i][j] / 5.0;
        }
    }
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 4; j++ )
        {
            cout << "Class : " << i+1 << endl;
            cout << "\t" << "Student : " << j+1 << endl;
            cout << "\t\t" << "Obtained Marks / Total Marks : " << sum[i][j] << " / 500"<< endl;
            cout << "\t\t" << "Average Marks : " << avg[i][j] << endl;
        }
    }


    int sub[5];
    for (int k = 0; k < 5; k++)
    {
        sub[k] = 0;
    }

    for ( int i = 0; i < 3; i++ ) // class 
    {
        for ( int j = 0; j < 4; j++ ) // students
        {
            for ( int k = 0; k < 5; k++ ) // subjects
            {
                if ( data[i][j][k] > sub[k] )
                {
                    sub[k] = data[i][j][k]; 
                }
            }
        }
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Highest Marks Per Subject : " << endl << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << "Subject " << k+1 << " : " << sub[k] << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Class with Highest Average Marks : " << endl << endl;
    for ( int i = 0; i < 3; i++ )
    {
        cls[i] = 0;
        for ( int j = 0; j < 4; j++ )
        {
            cls[i] += avg[i][j];
        }
        cls[i] = cls[i] / 4;
    }
    for ( int i = 0; i < 3; i++ )
    {
        cout << "Class " << i+1 << " Average : " << cls[i] << endl;
    }
    
    return 0;
}