#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

int main() 
{
	//srand((unsigned int) 324923);
	int j=0;
	
	// before execution copy data 
	// from numbers2bkup.txt to numbers2.txt
	system("copy numbers2bkup.txt numbers2.txt > nul");
	
	string numfile = "numbers2.txt";
	ofstream ofile;
	ofile.open(numfile.c_str(), ios::in | ios::out | ios::ate);
	
	ofile.seekp(100L, ios::beg);
	//if (!ofile)
	ofile << endl;
	for(;j<10; j++)
	{
		ofile << j << " " << rand() << endl;
	}
	

	ofile.seekp(5L, ios::cur);
	//if (!ofile)
	ofile << endl;
	for(;j<20; j++)
	{
		ofile << j << " " << rand() << endl;
	}
	

	
	ofile.seekp(-200L, ios::end);
	//if (!ofile)
	ofile << endl;
	for(;j<30; j++)
	{
		ofile << j << " " << rand() << endl;
	}
	

	ofile.close();

   return 0;
}