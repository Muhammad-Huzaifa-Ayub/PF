//     g++ assignment2task1.cpp -o assignment2task1.exe
//     assignment2task1.exe

#include <iostream>
#include<string>
#include<array>

using namespace std;


array<int,7>merge_sorted_arrays(array<int,3>arr1,array<int,4>arr2)
{
	int j=3;
	int t;
	array<int,7>merged_array;

	
	for (int i = 0; i < 3; i++)
	{
		merged_array[i] = arr1[i];
	}
	for (int i = 0; i < 4; i++)
	{
		merged_array[j] = arr2[i];
		j++;
	}
	
	for ( int times =0; times < 6; times++ )
	{
		for ( int i = 0; i < 6; i++ )
		{
			if ( merged_array[i] > merged_array[i+1] )
			{ 
				t = merged_array[i+1];
				merged_array[i+1] = merged_array[i]; 
				merged_array[i] = t;
			}
		}
	}
	

	return merged_array;
}



int main()
{
	array<int,7>sorted_array;
	array<int,3>array1{5,5,11};
	array<int,4>array2{1,5,5,10};
	
	sorted_array = merge_sorted_arrays(array1,array2);
	
	cout << "Sorted array is : ";
	for (int i = 0; i < 7; i++)
	{
		cout << sorted_array[i] << ",";
	}
	
	return 0;
}