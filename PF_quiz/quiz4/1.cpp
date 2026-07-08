#include<iostream>
#include<string>

using namespace std;

int main()
{
    int heads = 100;
    int legs = 300;
    int chicken = 0;
    int rabbit = 0;
    
    chicken = heads * 2;
    rabbit = legs - chicken;
    rabbit =  rabbit - rabbit / 2;

    chicken = ( chicken - heads ) - rabbit;

    cout << "Total Chickens in farm are : " << chicken << endl;
    cout << "Total Rabbits in farm are : " << rabbit << endl;

    return 0;
}
