#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() 
{
	string infile;
	cout << "Enter input file name ";
	cin >> infile;

	string outfile;
	cout << "Enter output file name ";
	cin >> outfile;

	ifstream ifile(infile.c_str());
	//if (!ifile)
	ofstream ofile(outfile.c_str());
	//if (!ofile)
	char c;
	//ifile >> c;
	ifile.get(c);
	//c = ifile.get();
	while(!ifile.eof())
	{
		if(c >= 'a' && c <= 'z')
		{
			c = c-'a'+'A';
		}
		ofile << c;
		
		//ifile >> c;
		ifile.get(c);
		//c = ifile.get();
	}
	
	ifile.close();
	ofile.close();
	
   return 0;
}