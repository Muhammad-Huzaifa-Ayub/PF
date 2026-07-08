#include <iostream>
#include <fstream>

using namespace std;

/* ================= BASIC STRING HELPERS ================= */

int str_length(char s[])
{
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void str_copy(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int str_equal(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return (a[i] == b[i]);
}

/* ================= NUMBER PARSING ================= */

double parse_number(char s[])
{
    double value = 0;
    double frac = 0.1;
    int i = 0;
    int decimal = 0;

    while (s[i] != '\0')
    {
        if (s[i] == ',')
        {
            i++;
            continue;
        }
        if (s[i] == '.')
        {
            decimal = 1;
            i++;
            continue;
        }
        int digit = s[i] - '0';
        if (digit >= 0 && digit <= 9)
        {
            if (!decimal)
                value = value * 10 + digit;
            else
            {
                value += digit * frac;
                frac = frac / 10;
            }
        }
        i++;
    }
    return value;
}

/* ================= PGM GENERATORS ================= */

void generate_strips1()
{
    ofstream f("strips1.pgm");
    f << "P2\n256 256\n3\n";
    for (int r = 0; r < 256; r++)
    {
        int v;
        if (r < 64) v = 2;
        else if (r < 128) v = 0;
        else if (r < 192) v = 3;
        else v = 1;

        for (int c = 0; c < 256; c++)
            f << v << " ";
        f << "\n";
    }
    f.close();
}

void generate_pattern1()
{
    ofstream f("pattern1.pgm");
    f << "P2\n256 256\n255\n";
    for (int r = 0; r < 256; r++)
    {
        for (int c = 0; c < 256; c++)
            f << (r + c) % 255 << " ";
        f << "\n";
    }
    f.close();
}

void generate_strips4()
{
    ofstream f("strips4.pgm");
    f << "P2\n256 256\n15\n";
    for (int r = 0; r < 256; r++)
    {
        for (int c = 0; c < 256; c++)
            f << c / 16 << " ";
        f << "\n";
    }
    f.close();
}

/* ================= PGM INVERSION ================= */

void invert_pgm()
{
    ifstream in("input.pgm");
    ofstream out("inverted.pgm");

    char p1, p2;
    int w, h, maxv;
    in >> p1 >> p2;
    in >> w >> h;
    in >> maxv;

    out << "P2\n" << w << " " << h << "\n" << maxv << "\n";

    int pixel;
    for (int i = 0; i < w * h; i++)
    {
        in >> pixel;
        out << maxv - pixel << " ";
        if ((i + 1) % w == 0) out << "\n";
    }

    in.close();
    out.close();
}

/* ================= NUMBERS TASK ================= */

void numbers_task()
{
    double nums[20];
    double sum = 0;

    cout << "Enter 20 numbers (commas allowed):\n";
    for (int i = 0; i < 20; i++)
    {
        char buf[50];
        cin >> buf;
        nums[i] = parse_number(buf);
        sum += nums[i];
    }

    double avg = sum / 20;
    cout << "Average = " << avg << "\n";
    cout << "Above average:\n";
    for (int i = 0; i < 20; i++)
        if (nums[i] > avg)
            cout << nums[i] << "\n";
}

/* ================= COURSE FILES ================= */

void course_files()
{
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    char code[50][20];
    char title[50][50];
    int credits[50];
    int seats[50];

    for (int i = 0; i < n; i++)
    {
        cout << "Code: "; cin >> code[i];
        cout << "Title: "; cin >> title[i];
        cout << "Credits: "; cin >> credits[i];
        cout << "Seats: "; cin >> seats[i];
    }

    ofstream f1("courses1.csv");
    for (int i = 0; i < n; i++)
        f1 << code[i] << "," << title[i] << "," << credits[i] << "," << seats[i] << "\n";
    f1.close();

    ofstream f2("courses2.txt");
    for (int i = 0; i < n; i++)
        f2 << code[i] << " " << title[i] << " " << credits[i] << " " << seats[i] << "\n";
    f2.close();
}

/* ================= MAIN MENU ================= */

int main()
{
    int ch;
    do
    {
        cout << "\n1 Strips1\n2 Pattern1\n3 Strips4\n4 Invert PGM\n5 Numbers\n6 Courses\n0 Exit\n";
        cin >> ch;

        if (ch == 1) generate_strips1();
        else if (ch == 2) generate_pattern1();
        else if (ch == 3) generate_strips4();
        else if (ch == 4) invert_pgm();
        else if (ch == 5) numbers_task();
        else if (ch == 6) course_files();

    } while (ch != 0);

    return 0;
}
