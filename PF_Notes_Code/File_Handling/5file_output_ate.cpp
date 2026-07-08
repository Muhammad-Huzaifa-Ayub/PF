#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() 
{
	// before execution copy data 
	// from numbers2bkup.txt to numbers2.txt
	system("copy numbers2bkup.txt numbers2.txt > nul");
	
	string numfile = "numbers2.txt";
	fstream ofile;
	ofile.open(numfile.c_str(), ios::out | ios::ate);
	ofile << "The end" << endl;
	ofile.close();

   return 0;
}