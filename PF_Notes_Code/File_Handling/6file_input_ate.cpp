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
	ifstream ofile;
	ofile.open(numfile.c_str(), ios::in | ios::ate);
	
	ofile.seekg(-20L, ios::cur);
	char ch;
	ofile.get(ch);
	while(ch != EOF)
	{
		cout.put(ch);
		ch = ofile.get();
	}
	
	ofile.close();

   return 0;
}