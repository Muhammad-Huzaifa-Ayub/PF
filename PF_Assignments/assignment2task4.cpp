//     g++ assignment2task4.cpp -o assignment2task4.exe
//     assignment2task4.exe

#include <iostream>
#include<string>
#include<array>
#include<stdexcept>

using namespace std;


int find_first_dna_match(string dna_seq,string pattern)
{
    int dna_length = 0;
    int pattern_length = 0;
    int zero = 0;
    int one = 1;
    int i = 0, j = 0;
    int k = 0, c =0;
    int count = 0;

    while (true)
    {
        if ( dna_seq[i] == '.')
            break;
        dna_length++;
        i++;
    }

    while (true)
    {
        if ( pattern[j] == '.')
            break;
        pattern_length++;
        j++;
    }

    try
    {
        if (pattern_length == 0) 
            throw runtime_error("Pattern string is EMPTY!");

        if (dna_length == 0) 
            throw runtime_error("DNA string is EMPTY!");

        for (int start = 0; start <= dna_length - pattern_length; start++)
		{
		    bool match = true;

		    for (int j = 0; j < pattern_length; j++)
		    {
		        if (dna_seq[start + j] != pattern[j])
		        {
		            match = false;
		            break;
		        }
		    }

		    if (match)
		    {
		        if (start == 0)
		        {
		            cout << "evaluated using case 1" << endl << "returning ";
		            return 0;
		        }
		        else
		        {
		            cout << "evaluated using case 2" << endl << "returning ";
		            return 1;
		        }
		    }
		}

		throw runtime_error("No Match Found.");
    }
    catch(const runtime_error& ex)
    {
        cout << "Error occurred: " << ex.what();
    }
    return 3;
}


int main ()
{
	string haystack;
	cout << "Enter DNA sequence : ";
	haystack = "GATTACA";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	string needle;
	needle = "ATT";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "AAATAAA";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "AAA";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "ATCGATCG";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "CAT";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "CGCGCGGC";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "GG";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "A";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "A";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "TATA";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "TA";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "AGCT";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	haystack = "GTACAG";
	cout << haystack;
	cout << endl;
	//cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	needle = "TACAG";
	cout << needle;
	cout << endl;
	//cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;


	cout << "Enter DNA sequence : ";
	cin >> haystack;
	haystack = haystack + ".";
	cout << "Enter PATTERN for search : ";
	cin >> needle;
	needle = needle + ".";
	cout << find_first_dna_match(haystack,needle);
	cout << endl;
	cout << endl;



	return 9;
}
