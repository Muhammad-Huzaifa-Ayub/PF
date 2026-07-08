#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int nlstr_length(const char str[])
{
    int count = 0;
    int i = 0;
    while ( str[i] != '\0')
    {
        count++;
        i++;

    }
    return count;
}

void nlstr_makeempty(char str[])
{
    str[0] = '\0';
    return;
}

void nlstr_assign(char target[], const char source[])
{
    int i = 0;

    while ( source != '\0')
    {
        target[i] = source[i];
        if ( target[i] == '\0')
        {
            break;
        }

        target[i+1];
        i++;
    }

}

void nlstr_append(char target[], const char source[])
{
    int i = 0;
    int tar = 0;
    while ( target[i] != '\0')
    {
        tar++;
        i++;
    }
}

int main()
{    
    cout << "start of program" << endl; // endl here

    int i=0;
    
    char city[100];
    city[i++] = 'L';
    city[i++] = 'a';
    city[i++] = 'h';
    city[i++] = 'o';
    city[i++] = 'r';
    city[i++] = 'e';
    city[i++] = '\n';
    city[i++] = '\0';
    
    cout << city; // no endl here
    cout << "1. we are here" << endl; // endl here
    
    char greeting[100] = "Welcome to the \n"; // automatically place \0 after the last character of string, it is feature of C and CPP

    cout << greeting; // no endl here
    cout << "2. now we are here" << endl; // endl here

// remove this to test function of first task
    // the demonstration of nlstr_length
    int len1 = nlstr_length(city);
    cout << "length of city : "<< len1 << endl; // should return count of characters in city before terminators
    int len2 = nlstr_length(greeting);
    cout << "length of greeting : "<< len2 << endl; // should return count of characters in city before terminators
    cout << "3. now we are here" << endl; // endl here


// remove this to test function of second task
    // the demonstration of nlstr_makeempty
    char temp[] = "Jawan\n";
    cout << temp; // no endl here
    nlstr_makeempty(temp);
    cout << temp; // no endl here, this must put line break
    cout << "4. now we are here" << endl; // endl here


// remove this to test function of third task
    // the demonstration of nlstr_assign
    nlstr_assign(temp, city);
    cout << city; // no endl here
    cout << temp; // no endl here
    nlstr_assign(temp, greeting);
    cout << greeting; // no endl here
    cout << temp; // no endl here
    cout << "5. now we are here" << endl << city;// endl here


// remove this to test function of fourth task
    // the demonstration of nlstr_append
    nlstr_append(temp, city);
    cout << temp;
    cout << city; // no endl here
    cout << "6. now we are here" << endl; // endl here
    
    
    cout << "end of program" << endl; // endl here

    return 0;
}