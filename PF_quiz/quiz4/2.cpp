#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>


using namespace std;

int main()
{
    srand(time(0));

    int array[50];
    cout << "Putting [50] integer random values in the arrary Ranging {200-500} : " << endl;
    for ( int i = 0; i < 50; i++ )
    {
        array[i] = 200 + rand() % (500 - 200);
    }
    float sum = 0;
    for ( int i = 0; i < 50; i++ )
    {
        sum += array[i];
    }
    float avg = sum / 50;
    cout << endl << "The Average is : " << avg << endl;
    float count = 0;
    for ( int i = 0; i < 50; i++ )
    {
        if ( avg < array[i])
        {
            count++;
        }
    }
    cout << endl << "The values above AVERAGE are : " << count << endl;
    float result = (count/50)*(100);
    cout << "The percentage of data in array above its average : " << result << endl;

    return 0;
}