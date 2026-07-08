#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	
	string numfile = "nums.txt";
	ifstream ifile(numfile);
	// if (!ifile){
	// 	cout << "error" << endl;
	// 	exit(0);
	// }
	int a[10];
	cout << "Start\n";
	for(int j=0; j<10; j++)
	{
		ifile >> a[j];
		cout << a[j] << ",";
	}
	cout << "End\n";
	for(int j=0; j<10; j++)
	{
	}
	//cout << '\b' << " " << endl;
	ifile.close();
	
   return 0;
}