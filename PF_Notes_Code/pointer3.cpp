#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int x = 9999;
    short int y = 6666; // note change here
    float z[3]{8888, 4444, 2222}; // note change here    
    
    int *p;
    
    p = &x;  // this is still working
    cout << &x << endl;
    cout << *p << endl;   // output will be as expected

    /*
    p = &y; // this will give error, so commented
    cout << &y << endl;
    cout << *p << endl;
    */
    
    p = (int*)&y; // explicit type cast will work here
    cout << &y << endl;
    cout << *p << endl;   // output will NOT be as expected

    p = (int *)&z[2]; // explicit type cast will work here
    cout << &z[2] << endl;
    cout << *p << endl;   // output will NOT be as expected
    
	return 0;
}
