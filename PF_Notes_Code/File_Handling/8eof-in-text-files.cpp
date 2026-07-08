#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() 
{
	char nl = char(10);
	char ef = char(26);
	ofstream oof("text-inners.txt");
	oof.write("Pakistan",8);
	//oof.write((char*)&nl,1); // comment uncomment
	//oof.write((char*)&ef,1); // comment uncomment
	oof.write("Zindabad",8);
	oof.close();
	
	
   return 0;
}