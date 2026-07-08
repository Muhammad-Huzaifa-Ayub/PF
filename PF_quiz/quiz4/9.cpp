#include <iostream>
#include<string>


using namespace std;

int main()

{
    int array[5] = {7, 2, 9, 4, 1};
    int k;

    cout << "Enter k: ";
    cin >> k;

    for (int i = 0; i < 5; i++)
    {
        int countSmaller = 0;


        for (int j = 0; j < 5; j++)
        {
            if (array[j] < array[i])
            {
                countSmaller++;
            }
        }


        if (countSmaller == k - 1)
        {
            cout << "The " << k << "th ranked value is: " << array[i] << endl;
            return 0;
        }
    }

    cout << "Invalid k value." << endl;
    return 0;
}
