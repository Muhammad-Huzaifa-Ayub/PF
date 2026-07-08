#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void funny_function_isnt_it(char *);

int main()
{
    int x = 65;   // x is in 4 bytes
    
    int *ip;   
    ip = &x;
    cout << &x << endl;
    cout << *ip << endl;

    char *cp;       
    cp = (char *)&x;  // explicit type cast works
    cout << &x << endl;
    cout << *cp << endl;   // output will be as expected, but understandable
    
    cout << "[" << *(cp+0) << "]" << endl;
    cout << "[" << *(cp+1) << "]" << endl;
    cout << "[" << *(cp+2) << "]" << endl;
    cout << "[" << *(cp+3) << "]" << endl;

    //funny_function_isnt_it(cp); // uncomment at the beginning

    cout << "at end of main" << endl;
    cout << "x is " << x << endl; // after function call, x is changed by function due to manipulation of data through address

	return 0;
}

void funny_function_isnt_it(char *p)
{
    cout << "in a function named funny_function_isnt_it" << endl;
    *(p+0) = 'A';
    *(p+1) = '\t';
    *(p+2) = '\n';
    *(p+3) = '\b';

    cout << "[" << *(p+0) << "]" << endl;
    cout << "[" << *(p+1) << "]" << endl;
    cout << "[" << *(p+2) << "]" << endl;
    cout << "[" << *(p+3) << "]" << endl;

    *(p+0) = char(219);
    *(p+1) = char(65);
    *(p+2) = char(236);
    *(p+3) = char(241);

    cout << "[" << *(p+0) << "]" << endl;
    cout << "[" << *(p+1) << "]" << endl;
    cout << "[" << *(p+2) << "]" << endl;
    cout << "[" << *(p+3) << "]" << endl;

    return;
}
