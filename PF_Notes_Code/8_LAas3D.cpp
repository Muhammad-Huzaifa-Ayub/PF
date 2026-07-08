#include <iostream>
#include <iomanip>

using namespace std;

void showMatrix(double m[], const int pags, const int rows, const int cols)
{
	int i;
	for(int j=0; j<pags; j++)
	{
		cout << "Page # " << j << endl;
		for(int k=0; k<rows; k++)
		{
			for(int l=0; l<cols; l++)
			{
				i = j*pags*cols+k*cols+l;
				cout << fixed << setprecision(2) << setw(7) << m[i];
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	double dm[] = {3, 4, 2, 7, 7, 3, 4, 2, 7, 3, 4, 2, 0, 9, 2, 7, 6, 4, 11, 7, 3, -5, 2, 3};
	cout << "Values in 1D array are " << sizeof(dm)/8 << endl << endl;

	cout << "A 3 X 4 X 2 matrix " << endl ;
	showMatrix(dm, 3, 4, 2); // order is 3 X 4 * 2

	cout << "A 2 X 2 X 6 matrix " << endl ;
	showMatrix(dm, 2, 2, 6); // order is 2 X 2 * 2

	cout << "A 1 X 2 X 12 matrix " << endl ;
	showMatrix(dm, 1, 2, 12); // order is 1 X 2 * 6
}
