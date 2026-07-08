#include <iostream>
#include<string>


using namespace std;

int main() 
{
    int num;
    cout << "Enter number ( 1 - 100 ) to check longest contiguous subarray that equals to it : ";
    cin >> num; 
    cout << endl;
    int array[17] = {9,17,22,34,8,54,78,45,89,56,62,73,39,81,12,66,98};
    int max_len = 0;
    for ( int i = 0; i < 17; i++ )
    {
        int sum = 0;
        for ( int j = i; j < 17; j++ )
        {
            sum += array[j];
            if (sum == num)
            {
                int length = j - i + 1;
                if (length > max_len)
                {
                    max_len = length;
                }
            }
        }
    }
    if (max_len > 0)
    {
        cout << "Length of longest contiguous subarray with sum " << num << " is : " << max_len << endl;
    }
    else
    {
        cout << "No contiguous subarray found with sum " << num << endl;
    }

    return 0;
}