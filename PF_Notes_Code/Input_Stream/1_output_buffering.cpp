#include <iostream>
#include <string>

using namespace std;

void busyWaiting()
{
    double j = 2;
    for(int k = 0; k < 100000; k++)
	 {
		 for(int i = 0; i < 10000; i++)
		 {
			  j = i / (i+1);
		 }
	 }
}

int main() 
{
    // cin.tie(nullptr); // to remove flush of output buffer before every input 
    
    cout << "Start";

    busyWaiting();
    for(int k = 0; k < 5; k++)
    {
        for(int i = 0; i < 5; i++)
        {
          cout << i + k << '\n';
        }
    }

    cout << "Wait 1 Finished";

    busyWaiting();
    cout << "Wait 2 Finished";

    // busy waiting code
    double j = 2;
    for(int k = 0; k < 100000; k++)
    {
        for(int i = 0; i < 10000; i++)
        {
          j = i / (i+1);
        }
    }
    cout << "The end";
	 
    return 0;
}
