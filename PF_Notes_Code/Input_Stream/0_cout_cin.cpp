#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main1()
{
    // Reference variables for standard output streams:
    ostream& mon = cout;
    ostream& eod = cerr;
    ostream& lod = clog;

    // Reference variable for standard input stream:
    istream& kb = cin;

    // You can now use the reference variables exactly like the original streams:

    mon << "This goes to standard output (cout)." << endl;
    eod << "This goes to standard error (cerr)." << endl;
    lod << "This goes to standard log (clog)." << endl;

    int user_input;
    mon << "Enter a number: ";
    kb >> user_input;
    mon << "You entered: " << user_input << endl;

    return 0;
}

int main2() {
    // Redirect standard output (stdout) to "output.log"
    if (freopen("output.log", "w", stdout) == nullptr) {
        perror("Failed to redirect stdout");
        return 1;
    }
    cout << "This message is written to output.log" << endl;

    // Redirect standard error (stderr) to "error.log"
    if (freopen("error.log", "w", stderr) == nullptr) {
        perror("Failed to redirect stderr");
        return 1;
    }
    cerr << "This error is written to error.log" << endl;

    // Redirect standard input (stdin) from "input.txt"
    if (freopen("input.txt", "r", stdin) == nullptr) {
        perror("Failed to redirect stdin");
        return 1;
    }
    int value;
    cin >> value; // Reads from input.txt
    cout << "The input is " << value << "OK\n";
    // Note: After redirection, you often need to restore the original
    // streams if you want to print to the actual console again.

    return 0;
}

int main3() {
    // Save the original standard output buffer
    streambuf* original_cout_buf = cout.rdbuf();

    // Create an output file stream
    ofstream file_out("cpp_output.log");

    // Redirect cout to the file
    cout.rdbuf(file_out.rdbuf());

    cout << "This line goes to cpp_output.log" << endl;

    // Restore cout to its original buffer (the console)
    cout.rdbuf(original_cout_buf);

    cout << "This line is back on the console." << endl;

    // File stream closes automatically when it goes out of scope
    return 0;
}

int main() {

    main1();
    //main2();
    return 0;
}
