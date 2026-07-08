#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int *p;
    /* in the line above no array is declared and
    only 4 bytes are allocated for an int
    BUT in the below line, code is treating p as 
    an array, WHY? 
    The answer is: as adress is just a byte number
    and . . . . . . . */
    
    
    p = new int; // var/array is create with memory allocated on heap
    
    *p = 53;
    *(p+1) = 87;
    *(p+2) = 39;
    
    cout << "heap memory through pointer notation" << endl;
    int i = 0;
    while(i < 3)
    {
        cout << *(p+i) << endl;
        i += 1;
    }
    
    cout << "same heap memory through array notation" << endl;
    int j = 0;
    while(j < 3)
    {
        cout << p[j] << endl;
        j += 1;
    }
    
    delete[] p; // it is mandotory for heap memory
    
	return 0;
}
