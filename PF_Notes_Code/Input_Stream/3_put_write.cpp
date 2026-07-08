#include<iostream>
#include<iomanip>
#include<string>

using namespace std;


int main()
{
	for (float i=32; i<256; i++)
	{
		cout << setw(3) << i << '\t';
		cout.put(i);
		cout << endl;
	}
    cout << "~~~~~~~~~~~~" << endl << endl;
    
	int a = 325323;
	cout << a << endl;
    cout << "[";
	cout.write((char *)&a, sizeof(a));
	//cout.write(((char *)&a)-2, sizeof(a));
    cout << "]";
	cout << endl;
    cout << "~~~~~~~~~~~~" << endl << endl;

	a = 65;
    cout << a << endl;
    cout << "[";
	cout.write((char *)&a, sizeof(a));
	//cout.write(((char *)&a)-2, sizeof(a));
    cout << "]";
	cout << endl;

	return 0;
	
}
