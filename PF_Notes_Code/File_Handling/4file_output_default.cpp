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
	
	// file variable is not ofstream
	fstream ofile;
	
	// later replace ios::out with ios::app
	// and experiment
	ofile.open(numfile.c_str(), ios::out); 
	//ofile.open(numfile.c_str(), ios::app); 
	ofile << "The end" << endl;
	ofile.close();

   return 0;
}