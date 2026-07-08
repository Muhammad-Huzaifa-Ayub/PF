#include<iostream>
#include<fstream>

using namespace std;

int main()
{   
    char ch;
    string content;

    ofstream out("file1.txt");
    //out.open("file.txt");
    out << "My first line of file handling in cpp." << endl;
    out << "This line is for file reading." << endl;
    out.close();

    ifstream in("file1.txt");

    while (in.get(ch))
    {
        content += ch;
    }
    in.close();

    cout << "file reading : " << endl << content << endl;






    return 0;
}