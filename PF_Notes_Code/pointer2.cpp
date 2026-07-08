#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int x = 9999;
    int y = 6666;
    int z[3]{8888, 4444, 2222};    
    
    int *p;
    
    p = &x;
    cout << &x << endl;
    cout << *p << endl;   // note the change, its now *p

    p = &y;
    cout << &y << endl;
    cout << *p << endl;

    p = &z[2];
    cout << &z[2] << endl;
    cout << *p << endl;
	return 0;
}
