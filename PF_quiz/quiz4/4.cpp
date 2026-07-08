#include<iostream>
#include<string>
#include<cmath>


using namespace std;

int main()
{
    char movement;
    cout << "The Robot movement is { U(UP), D(DOWN), L(LEFT), R(RIGHT) }" << endl << "Default location is ( 0,0 ) " << endl << endl;
    int x = 0, y = 0;
    while (true)
    {
        cout << "Enter ( U,D,L,R ) to move robot and ( B ) to brake : ";
        cin >> movement;
        if ( movement == 'B') break;
        else if ( movement == 'U') y++;
        else if ( movement == 'D') y--;
        else if ( movement == 'L') x--;
        else if ( movement == 'R') x++;
        else
        {
            cout << "Invalid Movement " << endl;
            break;

        } 


    }
    cout << endl;
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;

    float dist = 0.00;
    dist =  sqrt( pow((x - 0),2) + pow((y - 0),2));
    cout << "Total Distance covered by robot is : " << dist << endl;
    
    return 0;
}
