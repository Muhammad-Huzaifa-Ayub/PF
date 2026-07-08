#include<iostream>
#include<string>


using namespace std;

int main()
{
    int num;
    cout << "Enter a number to calculate the ( a*1 + a*2 + a*3 +.......a*a sreies ) : ";
    cin >> num;
    long long sum = 0;
    for ( int i = 1; i <= num; i++ )
    {
        sum += num * i;
        cout << sum << " ";
    }
    cout << "The sum of requird series is : " << sum << endl;
    
    return 0;
}