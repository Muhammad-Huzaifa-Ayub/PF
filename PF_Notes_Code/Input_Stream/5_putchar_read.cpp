#include<iostream>
#include<iomanip>
#include<string>

using namespace std;


int main1()
{
    char s[1000];
    int m;
    double d;
    
    cin >> s >> m >> d;
    cout << "gcount " << cin.gcount() << endl;
    cout << s << endl;
    cout << m << endl;
    cout << d << endl;
    cout << endl;
    
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
    cout << "gcount " << cin.gcount() << endl;
    cout << endl << endl;
    cout << s << endl;

	return 0;
	
}

int main3()
{
    char s[1000];

    cin.getline(s, 1000); // later make it less than 10
    cout << "gcount " << cin.gcount() << endl;
    cout << s << endl << endl;

    cin.getline(s, 10, '*');
    cout << "gcount " << cin.gcount() << endl;
    cout << s << endl;

	return 0;
}

int main4()
{
    char s[1000];
    
    cin.get(s[0]);
    cin.get(s[1]);
    cin.get(s[2]);
    
    cin.putback('#');
    cin.putback('^');
    cin.putback('#');
//    cin.putback('^'); donot puback more than extracted
//    cin.putback('#');

    cin.getline(&s[3], 1000);
    cout << s << endl << endl;

	return 0;
}

int main5()
{
    char s[1000] = "humpty dumpty sat on a wall";

    cin.read(&s[7], 4); // later make it less than 10
    cout << "gcount " << cin.gcount() << endl;
    cout << s << endl << endl;

	return 0;
}

int main()
{
    main1();
    //main2();
    //main3();
    //main4();
    //main5();
    return 0;
}
