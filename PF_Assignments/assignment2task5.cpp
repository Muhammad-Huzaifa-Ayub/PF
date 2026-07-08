//    g++ assignment2task5.cpp -o assignment2task5.exe
//     assignment2task5.exe

#include <iostream>
#include<string>
#include<array>
#include<stdexcept>

using namespace std;


int max_contiguous_gain(array<int,6>daily_change)
{
	int current_sum = 0, max_sum = 0;
	for (int i = 0; i < 6; i++)
	{
		current_sum = current_sum + daily_change[i];
		if ( current_sum < 0)
		{
			current_sum = 0;
		}
		if ( current_sum > max_sum)
		{
            max_sum = current_sum;
		}
	}
	return max_sum;
}




int main()
{
	array<int,6>daily_change;
	cout << "Enter daily change of six days of crypto market : ";
	for (int i = 0; i < 6; i++)
	{
		cin >> daily_change[i];
	}
cout << "Maximum possible cumulative gain is : ";
cout <<  max_contiguous_gain(daily_change) << endl;


return 0;
}
