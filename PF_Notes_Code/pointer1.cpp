#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int x = 9999;
    int y = 6666;
    int z[3]{8888, 4444, 2222};

    cout << "x    " << &x << endl;
    cout << "y    " << &y << endl;
    cout << "z    " << &z << endl;
    cout << "z[0] " << &z[0] << endl;
    cout << "z[1] " << &z[1] << endl;
    cout << "z[2] " << &z[2] << endl;

    cout << "main function is at address " << (void*)&main << endl;

	return 0;
}
