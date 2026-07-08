#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Define maximum sizes for our character arrays (C-strings)
const int MAX_LEN = 50;

void print_cstring(const char* label, const char* str) {
    cout << label << ": \"" << str << "\"" << endl;
}

int main() {
    // --- 1. Initialization and strlen (String Length) ---
    char source[] = "Hello World!";
    char destination[MAX_LEN];
    char buffer[MAX_LEN] = "This is a buffer.";

    cout << "--- 0. local output ---" << endl;
    cout << "Source String is: " << source << endl;
    cout << "What this is and why: " << &source[4] << endl;
    source[12] = '@';
    cout << "This one ?: " << source << endl;
    source[12] = '\0';
    cout << "Back to original: " << source << endl;
    cout << endl << endl;

    cout << "--- 1. String Length (strlen) ---" << endl;
    print_cstring("Source String", source);

    // strlen: Returns the length of the string, *excluding* the null terminator ('\0').
    size_t length = strlen(source);
    cout << "Length of source string: " << length << " characters." << endl;
    cout << "-----------------------------------" << endl << endl;


    // --- 2. strcpy (String Copy) ---
    cout << "--- 2. String Copy (strcpy) ---" << endl;
    // strcpy: Copies the string pointed to by source, including the null terminator, 
    // to the array pointed to by destination.
    strcpy(destination, source);
    print_cstring("Copied to destination", destination);
    cout << "-----------------------------------" << endl << endl;


    // --- 3. strcat (String Concatenation) ---
    cout << "--- 3. String Concatenation (strcat) ---" << endl;
    char extension[] = " Welcome!"; // note a space at begining of  Welcome
    print_cstring("Current destination", destination); // "Hello World!"
    print_cstring("Extension to add", extension);   // " Welcome!"

    // strcat: Appends the string pointed to by extension to the string pointed to 
    // by destination. The null terminator from destination is overwritten.
    strcat(destination, extension);
    print_cstring("After strcat", destination); // "Hello World! Welcome!"
    cout << "-----------------------------------" << endl << endl;


    // --- 4. strcmp (String Comparison) ---
    cout << "--- 4. String Comparison (strcmp) ---" << endl;
    char str_a[] = "apple";
    char str_b[] = "zebra";
    char str_c[] = "apple";

    // strcmp: Compares two strings lexicographically.
    // - Returns 0 if strings are equal.
    // - Returns < 0 if str_a comes before str_b (e.g., "apple" vs "zebra").
    // - Returns > 0 if str_a comes after str_b (e.g., "zebra" vs "apple").

    int compare1 = strcmp(str_a, str_c); // apple vs apple
    int compare2 = strcmp(str_a, str_b); // apple vs zebra
    int compare3 = strcmp(str_b, str_a); // zebra vs apple

    cout << "Comparing \"" << str_a << "\" and \"" << str_c << "\": Result = " << compare1 << " (Equal)" << endl;
    cout << "Comparing \"" << str_a << "\" and \"" << str_b << "\": Result = " << compare2 << " (Less than zero: a < z)" << endl;
    cout << "Comparing \"" << str_b << "\" and \"" << str_a << "\": Result = " << compare3 << " (Greater than zero: z > a)" << endl;
    cout << "-----------------------------------" << endl << endl;


    // --- 5. strncpy (Safe/Limited String Copy) ---
    cout << "--- 5. Limited Copy (strncpy) ---" << endl;
    char short_source[] = "123456789";
    char short_dest[MAX_LEN];
    
    // NOTE: strncpy does *NOT* guarantee null-termination if the source string 
    // is longer than or equal to the size specified (N).
    // It's safer to manually null-terminate or use safer C++ functions.
    
    // Reset the destination
    memset(short_dest, 0, MAX_LEN); 

    // strncpy: Copies only the first 5 characters (does not copy null terminator 
    // from source, but it will zero-fill the rest of the 5 bytes if source is shorter).
    strncpy(short_dest, short_source, 5); 
    short_dest[5] = '\0'; // Manually null-terminate for safety
    
    print_cstring("Source", short_source);
    cout << "Copied first 5 characters: ";
    print_cstring("Destination", short_dest); // "12345"
    cout << "-----------------------------------" << endl << endl;


    // --- 6. strstr (String Search) ---
    cout << "--- 6. String Search (strstr) ---" << endl;
    char haystack[] = "The quick brown fox jumps over the lazy dog.";
    char needle[] = "fox";
    
    // strstr: Finds the first occurrence of the substring (needle) in the string 
    // (haystack). Returns a pointer to the beginning of the located substring, 
    // or a null pointer if the substring is not found.
    const char* result = strstr(haystack, needle);

    if (result != nullptr) {
        cout << "Found \"" << needle << "\" in \"" << haystack << "\"" << endl;
        // The pointer 'result' points to the 'f' in "fox"
        cout << "The rest of the string from that point is: \"" << result << "\"" << endl;
    } else {
        cout << "\"" << needle << "\" was not found." << endl;
    }
    cout << "-----------------------------------" << endl << endl;

    return 0;
}