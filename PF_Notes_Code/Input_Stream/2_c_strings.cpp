#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*

name of the character array is treated as 
c string for input and output operations
despite it is null (\0) terminated or not

*/

int main() 
{    
    //char msg[] = "We belongs to DDSPU";
    char msg[44] = "We belongs to DDSPU";
    cout << "cstring " << msg << endl;
    cout << "sizeof " << sizeof(msg) << endl;
    cout << "strlen " << strlen(msg) << endl;
    string strmsg = string(msg);
    cout << "string " << strmsg << endl;
    cout << endl;

    string cppstr = "I lovee\b \nteaching\a";
    cout << "String: " << cppstr << endl;
    
    //char cstr[100] = cppstr.c_str(); // error due to array cstr, solution strcpy function of cstring header
    char cstr[100];
    strcpy(cstr, cppstr.c_str());
    cout << "CString: " << cstr << endl;
    cout << endl;

    const char* cstr2 = cppstr.c_str();
    cout << "CString: " << cstr2 << endl;
    cout << "sizeof " << sizeof(cstr2) << endl; // will give size of pointer variable not array
    cout << "strlen " << strlen(cstr2) << endl;

    return 0;
}
