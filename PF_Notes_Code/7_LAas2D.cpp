#include <iostream>
#include <iomanip>

using namespace std;

void showMatrix(double m[], const int rows, const int cols)
{
	int i;
	for(int j=0; j<rows; j++)
	{
		for(int k=0; k<cols; k++)
		{
			i = j*cols+k;
			cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << setw(7) << m[i];
		}
		cout << endl;
	}
}

int main()
{
	double dm2[] = {3, 4, 2, 7};
	cout << "A 2 X 2 matrix " << endl ;
	showMatrix(dm2, 2, 2); // order is 2 X 2

	double dm3[] = {3, 4, 2, 7, 5, -3, 7, 0, 2};
	cout << "A 3 X 3 matrix " << endl ;
	showMatrix(dm3, 3, 3); // order is 2 X 2

	double dm4[] = {3, 4, 2, 7, 3, 4, 2, 0, 3, 9, 2, 7, 6, 4, 11, 7, 3, -5, 2, 3};
	cout << "A 4 X 4 matrix " << endl ;
	showMatrix(dm4, 4, 4); // order is 4 X 4
	cout << "A 8 X 2 matrix " << endl ;
	showMatrix(dm4, 8, 2); // order is 8 X 2
	cout << "A 8 X 2 matrix " << endl ;
	showMatrix(dm4, 2, 8); // order is 2 X 8

	double dm7[49]; // use the garbage stored in array as data
	cout << "A 7 X 7 matrix " << endl ;
	showMatrix(dm7, 7, 7); // order is 7 X 7
}
