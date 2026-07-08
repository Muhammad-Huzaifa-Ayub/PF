//     g++ assignment2task2.cpp -o assignment2task2.exe
//     assignment2task2.exe

#include <iostream>
#include<string>
#include<array>

using namespace std;


void count_inversions(array<int,5>arr)
{
	bool equal = false;
	int c=0;
	cout << "Inversion pairs are : ";
	for (int i =1; i<5; i++)
	{
		if( arr[0] > arr[i] )
		{
			cout << "(" << arr[0] << "," << arr[i] << ")" << " ";
			c++;
		}
		else if ( arr[0] == arr[i] )
		{
			equal = true;
		}
		
	}
	
	for (int i =2; i<5; i++)
	{
		if( arr[1] > arr[i] )
		{
			cout << "(" << arr[1] << "," << arr[i] << ")" << " ";
			c++;
		}
		else if ( arr[1] == arr[i] )
		{
			equal = true;
		}
	}
	for (int i =3; i<5; i++)
	{
		if( arr[2] > arr[i] )
		{
			cout << "(" << arr[2] << "," << arr[i] << ")" << " ";
			c++;
		}
		else if ( arr[2] == arr[i] )
		{
			equal = true;
		}
	}
	for (int i =4; i<5; i++)
	{
		if( arr[3] > arr[i] )
		{
			cout << "(" << arr[3] << "," << arr[i] << ")" << " ";
			c++;
		}
		else if ( arr[3] == arr[i] )
		{
			equal = true;
		}
	}
	
	if (c==0)
	{
		cout << " Total number of inversions are : " << c;
		cout << "                 Array is fully sorted.";
	}
	if (c>0)
	{
		cout << "                         Total number of inversions are : " << c;
	}
	if ( equal == true)
	{
		cout << " As the array is all equal , so the  Inversion is : 0 ";
	}
	return;
}


int main()
{
	array<int,5>array_input1{2,4,1,3,5};
	array<int,5>array_input2{1,2,3,4,5};
	array<int,5>array_input3{5,4,3,2,1};
	array<int,5>array_input4{10,1,2,3,4};
	array<int,5>array_input5{4,4,4,4,4};
	array<int,5>array_input6{1,5,2,8,3};

	
	
	
	count_inversions(array_input1);
	cout << endl;
	count_inversions(array_input2);
	cout << endl;
	count_inversions(array_input3);
	cout << endl;
	count_inversions(array_input4);
	cout << endl;
	count_inversions(array_input5);
	cout << endl;
	count_inversions(array_input6);
	cout << endl;
	
	
	return 0;
}
