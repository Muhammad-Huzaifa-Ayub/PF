#include <iostream>
#include<string>


using namespace std;

int main() 
{
    int num;
    cout << "Enter nth number for Fibonacci series : ";
    cin >> num;

    long long a = 0, b = 1, fib;

    if (num == 0) cout << "Fibonacci: 0" << endl;
    else if (num == 1) cout << "Fibonacci: 1" << endl;
    else 
    {
        for (int i = 2; i <= num; i++)
        {
            fib = a + b;
            a = b;
            b = fib;
        }
        cout << "Fibonacci number : " << b << endl;
    }

    return 0;
}
