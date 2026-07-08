#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() 
{
	string numfile = "values.txt";
	ofstream ofile;
	ofile.open(numfile);
	//if (!ofile.is_open())
	int j=0;	
	while(j<10)
	{
		ofile << j << '\t' << rand()%850+150 << endl;
		j = j + 1;
	}
	
	ofile.close();
	
   return 0;
}