#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main1()
{
    char s[1000];
    for(int j=0; j<1000; j+=1)
    {
        cin.get(s[j]);
        if (s[j]=='*')
        {
            s[j+3] = '\0';
            j=1000; // good option is break
        }
    }
    cout << endl << endl;
    cout << s << endl;

	return 0;
	
}

int main2()
{
    char s[1000];
    for(int j=0; j<1000; j+=1)
    {
        s[j] = cin.get(); // returns int but casted
        if (s[j]=='*')
        {
            s[j+3] = '\0';
            j=1000; // good option is break
        }
    }
    cout << endl << endl;
    cout << s << endl;

	return 0;
	
}

int main3()
{
    char s[1000];
    cin.getline(s, 1000); // later make it less than 10
    cout << endl << endl;
    cout << s << endl;

    cin.getline(s, 10, '*');
    cout << endl << endl;
    cout << s << endl;

	return 0;
}

int main4()
{
    char s[1000];
    for(int j=0; j<10; j+=1)
    {
        cin.get(s[j]);
        for(int u=0; u<3; u+=1)
        {
            s[++j] = cin.peek();
        }
        if (j>=9)
        {
            s[++j] = '\0';
        }
    }
    cout << endl << endl;
    cout << s << endl;
    for(int j=0; j<1000 && s[j] != '\0'; j+=1)
    {
        cout << j << " " << s[j] << "  " << int(s[j]) << endl;
    }    
    cout << endl;
    
	return 0;
}

int main()
{
    main1();
    //main2();
    //main3();
    //main4();
    return 0;
}
