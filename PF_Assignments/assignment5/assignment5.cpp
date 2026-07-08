#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<fstream>


using namespace std;

const int SIZE = 20;

const int C = 12;
const int P = 5;  
const int T = 3; 
const int R = 5; 
const int M = 12; 

int trade[C][C][P][T][R][M];

void displayNumbersInWords()
{
    double numbers[SIZE];
    ifstream in("numbers.txt");

    if (!in)
    {
        cout << "Error opening file 'numbers.txt'!" << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++)
    {
        in >> numbers[i];
    }
    in.close();

    string one[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string two[11] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "Numbers in words:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        double number = numbers[i];

        long long rupees = (long long) number;
        double frac = number - (double) rupees;
        if ( frac < 0 ) frac = 0;

        int paisa = (int) round (frac * 100.0);

        if ( paisa == 100 )
        {
            rupees +=1;
            paisa = 0;
        }

        string result = "";

        int lakh = (int)rupees / 100000;
        int thousand = (int)(rupees / 1000) % 100;
        int hundred = (int)(rupees / 100) % 10;
        int remainder = (int)rupees % 100;

        string str = "";
        int num;

        num = lakh;
        if (num > 0)
        {
            if (num >= 100)
            {
                result += one[num / 100] + " hundred ";
                num %= 100;
            }
            if (num >= 20)
            {
                result += tens[num / 10] + " ";
                num %= 10;
            }
            if (num >= 10 && num < 20)
                result += two[num - 9] + " ";
            if (num > 0 && num < 10)
                result += one[num] + " ";
            result += "lacs ";
        }

        num = thousand;
        if (num > 0)
        {
            if (num >= 100)
            {
                result += one[num / 100] + " hundred ";
                num %= 100;
            }
            if (num >= 20)
            {
                result += tens[num / 10] + " ";
                num %= 10;
            }
            if (num >= 10 && num < 20)
                result += two[num - 9] + " ";
            if (num > 0 && num < 10)
                result += one[num] + " ";
            result += "thousands ";
        }

        if (hundred > 0)
        {
            result += one[hundred] + " hundred ";
        }

        num = remainder;
        if (num >= 20)
        {
            result += tens[num / 10] + " ";
            num %= 10;
        }
        if (num >= 10 && num < 20)
        {
            result += two[num - 9] + " ";
        }
        if (num > 0 && num < 10)
        {
            result += one[num] + " ";
        }

        result += "rupees";

        num = paisa;
        if (num > 0)
        {
            result += " and ";
            if (num >= 20)
            {
                result += tens[num / 10] + " ";
                num %= 10;
            }
            if (num >= 10 && num < 20)
            {
                result += two[num - 9] + " ";
            }
            if (num > 0 && num < 10)
            {
                result += one[num] + " ";
            }
            result += "paisas";
        }

        double diff = fabs(number - (double)rupees);
        if (diff < 1e-9)
        {
            cout << rupees << " ----> " << result << endl;
        }
        else
        {
            cout << fixed << setprecision(3) << number << defaultfloat << " ----> " << result << endl;
        }
    }
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    return;
}


void displayAboveAverage()
{
    double numbers[SIZE];
    double sum = 0.0;

    ifstream in("numbers.txt");
    if (!in)
    {
        cout << "Error opening file 'numbers.txt'!" << endl;
        return;
    }

    for ( int i = 0; i < SIZE; i++ )
    {
        in >> numbers[i];
        sum += numbers[i];
    }
    in.close();

    double average = sum / SIZE;
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << "Average: " << average << endl;
    cout << "Numbers above average:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (numbers[i] > average)
        {
            cout << numbers[i] << ",";
        }
    }
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    return;
}


void read_countries_csv()
{
    ifstream in("countries of the world.csv");

    if (!in)
    {
        cout << "CSV file not found." << endl;
        return;
    }

    char line[1024];

    in.getline(line, 1024);

    cout << endl << "COUNTRY DATA (Selected 6 Columns)" << endl << endl;
    cout << "Country | Region | Population | Area (sq. mi.) | GDP( $ per capita ) | Literacy( % )" << endl << endl;

    while (in.getline(line, 1024))
    {
        char country[50], region[50], population[20], area[20], gdp[20], literacy[20];

        int i = 0, k = 0, col = 0;
        char temp[50];

        for ( i = 0; line[i] != '\0'; i++ )
        {
            if (line[i] == ',')
            {
                temp[k] = '\0';

                if ( col == 0 )
                    strcpy(country, temp);
                if ( col == 1 )
                    strcpy(region, temp);
                if ( col == 2 )
                    strcpy(population, temp);
                if ( col == 3 )
                    strcpy(area, temp);
                if ( col == 4 )
                    strcpy(gdp, temp);
                if ( col == 5 )
                    strcpy(literacy, temp);

                col++;
                k = 0;
            }
            else
            {
                temp[k++] = line[i];
            }
        }

        cout << country << " | " << region << " | " << population << " | " << area << " | " << gdp << " | " << literacy << endl;
    }

    in.close();
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    return;
}


void origin_tariff_count()
{
    cout << endl << "ORIGIN COUNTRY WISE TRADE COUNT ( Tariff slabs of 20% )" << endl << endl;

    for ( int o = 0; o < C; o++ )
    {
        int slabCount[5] = {0};

        for ( int d = 0; d < C; d++ )
        {
            if (o != d)
            {
                for ( int p = 0; p < P; p++ )
                {
                    for ( int t = 0; t < T; t++ )
                    {
                        for ( int m = 0; m < M; m++ )
                        {
                            if ( trade[o][d][p][t][0][m] > 0 )
                            {
                                int tariffPercent = rand() % 101;

                                int slab = tariffPercent / 20;
                                if (slab >= 5)
                                {
                                    slab = 4;
                                }

                                slabCount[slab]++;
                            }
                        }
                    }
                }
            }
        }

        cout << "Country " << o+1 << ": ";

        for (int s = 0; s < 5; s++)
        {
            cout << "[" << s * 20 << "-" << (s * 20 + 19) << "%]=" << slabCount[s] << "  ";
        }
        cout << endl;
    }

    cout << endl << "---------------------------------------------------------------" << endl;
}


void generate_trade_data()
{
    srand(time(0));

    for ( int c = 0; c < C; c++ )
    {
        for ( int d = 0; d < C; d++ )
        {
            for ( int p = 0; p < P; p++ )
            {
                for ( int t = 0; t < T; t++ )
                {
                    for ( int r = 0; r < R; r++ )
                    {
                        for ( int m = 0; m < M; m++ )
                        {
                            if ( c != d )
                            {
                                trade[c][d][p][t][r][m] = 30000 + rand() % ( 120000 - 30000 + 1 );
                            }
                            else
                            {
                                trade[c][d][p][t][r][m] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}


void country_to_country_total()
{
    cout << endl << "COUNTRY TO COUNTRY TOTAL TRADE ( 2025 )" << endl << endl;

    for ( int c = 0; c < C; c++ )
    {
        for ( int d = 0; d < C; d++ )
        {
            if ( c == d )
            {
                cout << "--------  ";
            }
            else
            {
                long long sum = 0;

                for ( int p = 0; p < P; p++ )
                {
                    for ( int t = 0; t < T; t++ )
                    {
                        for ( int r = 0; r < R; r++ )
                        {
                            for ( int m = 0; m < M; m++ )
                            {
                                sum += trade[c][d][p][t][r][m];
                            }
                        }
                    }
                }
                cout << sum;
                cout << "  ";
            }
        }
        cout << endl;
    }
}


void month_wise_average()
{
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "MONTH-WISE AVERAGE TRADE ( 2025 )" << endl << endl;

    for ( int m = 0; m < M; m++ )
    {
        long long sum = 0;
        int count = 0;

        for ( int o = 0; o < C; o++ )
        {
            for ( int d = 0; d < C; d++ )
            {
                if ( o != d )
                {
                    for ( int p = 0; p < P; p++ )
                    {
                        for ( int t = 0; t < T; t++ )
                        {
                            for ( int r = 0; r < R; r++ )
                            {
                                sum += trade[o][d][p][t][r][m];
                                count++;
                            }
                        }
                    }
                }
            }
        }
        long long avg = sum / count;
        cout << "Month " << (m + 1) << ": " << avg << endl;
    }
    cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
    return;
}


void PGM_inversion()
{
    ifstream in("strips1.pgm"); 
    ofstream out("output.pgm"); 

    char format[3];
    int width, height;
    int maxVal;

    in >> format;          
    in >> width >> height;
    in >> maxVal;         

    out << format << endl;
    out << width << " " << height << endl;
    out << maxVal << endl;
 
    int pixel;
    for (int i = 0; i < width * height; i++)
    {
        in >> pixel;
        out << (maxVal - pixel) << " ";

        if ((i + 1) % width == 0)
        {
            out << endl;
        }
    }

    in.close();
    out.close();

    cout << "Image inverted successfully." << endl;
    return;
}


void generate_input_files()
{
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    char code[50][20];
    char title[50][50];
    int credits[50];
    int semester[50];
    char status[50][20];

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Course " << i + 1 << endl;

        cout << "Course Code: ";
        cin >> code[i];

        cout << "Course Title: ";
        cin.ignore();
        cin.getline(title[i], 50);

        cout << "Credits: ";
        cin >> credits[i];

        cout << "Semester: ";
        cin >> semester[i];

        cout << "Status (active/discontinued): ";
        cin >> status[i];
    }

    ofstream file1("courses1.txt");

    for (int i = 0; i < n; i++)
    {
        file1 << code[i] << "," << title[i] << "," << credits[i] << "," << semester[i] << "," << status[i] << endl;
    }
    file1.close();

    ofstream file2("courses2.txt");

    for (int i = 0; i < n; i++)
    {
        file2 << code[i] << "  " << title[i] << endl;
    }
    file2 << endl;

    for (int i = 0; i < n; i++)
    {
        file2 << credits[i] << endl;
    }
    file2 << endl;

    for (int i = 0; i < n; i++)
    {
        file2 << semester[i] << status[i] << endl;
    }
    file2.close();
    cout << endl << "Files created successfully." << endl;

    return;
}


void generate_pattern4()
{
    ofstream out("pattern4.ppm");
    out << "P3" << endl << "256 256" << endl << "255" << endl;

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            int rowBlock = i / 16;
            int colBlock = j / 16;

            int value;
            if ((rowBlock + colBlock) % 2 == 0)
                value = 0;
            else
                value = 255;

            out << value << " " << value << " " << value << " ";
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_pattern3()
{
    ofstream out("pattern3.pgm");
    out << "P2" << endl << "256 256" << endl << "255" << endl;

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            int rowBlock = i / 32;
            int colBlock = j / 32;

            int value;
            if ((rowBlock + colBlock) % 2 == 0)
                value = 0;
            else
                value = 255;

            out << value << " ";
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_pattern2()
{
    ofstream out("pattern2.pgm");
    out << "P2" << endl << "256 256" << endl << "255" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        for ( int j = 0; j < 256; j++ )
        {
            int rowBlock = i / 16;
            int colBlock = j / 16;

            int value;
            if ((rowBlock + colBlock) % 2 == 0)  value = 0;     
            else  value = 255;     

            out << value << " ";
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_strips4()
{
    ofstream out("strips4.pgm");
    out << "P2" << endl << "256 256" << endl << "15" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        for ( int j = 0; j < 256; j++ )
        {
            int k = j/16;
            out << k << " "; 
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_pattern1()
{
    ofstream out("pattern1.pgm");
    out << "P2" << endl << "256 256" << endl << "255" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        for ( int j = 0; j < 256; j++ )
        {
            int k = (i+j) % 225;
            out << k << " "; 
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_strips3()
{
    ofstream out("strips3.pgm");
    out << "P2" << endl << "256 256" << endl << "255" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        srand(time(0));

        for ( int j = 0; j < 256; j++ )
        {
            int k = rand() % 225 + 1;
            out << k << " "; 
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_strips2()
{
    ofstream out("strips2.pgm");
    out << "P2" << endl << "256 256" << endl << "15" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        short int num;
        if ( i < 16 ) num = 0;
        else if ( i < 32 ) num = 1;
        else if ( i < 48 ) num = 2;
        else if ( i < 64 ) num = 3;
        else if ( i < 80 ) num = 4;
        else if ( i < 96 ) num = 5;
        else if ( i < 112 ) num = 6;
        else if ( i < 128 ) num = 7;
        else if ( i < 144 ) num = 8;
        else if ( i < 160 ) num = 9;
        else if ( i < 176 ) num = 10;
        else if ( i < 192 ) num = 11;
        else if ( i < 208 ) num = 12;
        else if ( i < 224 ) num = 13;
        else if ( i < 240 ) num = 14;
        else num = 15;
    
        for ( int j = 0; j < 256; j++ )
        {
            out << num << " "; 
        }
        out << endl;
    }
    out.close();

    return;
}


void generate_strips1()
{
    ofstream out("strips1.pgm");
    out << "P2" << endl << "256 256" << endl << "3" << endl;

    for ( int i = 0; i < 256; i++ )
    {
        short int num;
        if ( i < 64 ) num = 2;
        else if ( i < 128 ) num = 0;
        else if ( i < 192 ) num = 3;
        else  num = 1;

        for ( int j = 0; j < 256; j++ )
        {
            out << num << " "; 
        }
        out << endl;
    }
    out.close();

    return;
}


int main()
{
    generate_trade_data();

        while( true )
        {
            short int choice;
            cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------- Assignment 5  [ Menu ] ---------";
            cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter [1] to get input files function" << endl;
            cout << "Enter [2] to generate ( strips1.pgm )" << endl;
            cout << "Enter [3] to generate ( strips2.pgm )" << endl;
            cout << "Enter [4] to generate ( strips3.pgm )" << endl;
            cout << "Enter [5] to generate ( strips4.pgm )" << endl;
            cout << "Enter [6] to generate ( pattern1.pgm )"<< endl;
            cout << "Enter [7] to generate ( pattern2.pgm )" << endl;
            cout << "Enter [8] to generate ( pattern3.pgm )" << endl;
            cout << "Enter [9] to generate ( pattern4.ppm )" << endl;
            cout << "Enter [10] to get PGM Inversion" << endl << endl << endl;
            cout << "Enter [11] to get { Country to Country Total }" << endl;
            cout << "Enter [12] to get { Month Wise Average }" << endl;
            cout << "Enter [13] to get { Tariff Count }" << endl;
            cout << "Enter [14] to read { Countries of the world.csv }" << endl << endl << endl;
            cout << "Enter [15] to get ( Average numbers from input of file )" << endl;
            cout << "Enter [16] to get ( Numbers In Words from input of file )" << endl;
            cout << "Enter [0] to exit" << endl << endl;
            cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter your choice : ";
            cin >> choice;

            if (choice == 1)
            {
                generate_input_files();
                cout << endl;
            }
            else if (choice == 2)
            {
                generate_strips1();
                cout << "The file { Strips1.pgm } created successfully." << endl;
            }
            else if (choice == 3)
            {
                generate_strips2();
                cout << "The file { Strips2.pgm } created successfully." << endl;
            }
            else if (choice == 4)
            {
                generate_strips3();
                cout << "The file { Strips3.pgm } created successfully." << endl;
            }
            else if (choice == 5)
            {
                generate_strips4();
                cout << "The file { Strips4.pgm } created successfully." << endl;
            }
            else if (choice == 6)
            {
                generate_pattern1();
                cout << "The file { pattern1.pgm } created successfully." << endl;
            }
            else if (choice == 7)
            {
                generate_pattern2();
                cout << "The file { pattern2.pgm } created successfully." << endl;
            }
            else if (choice == 8)
            {
                generate_pattern3();
                cout << "The file { pattern3.pgm } created successfully." << endl;
            }
            else if (choice == 9)
            {
                generate_pattern4();
                cout << "The file { pattern4.ppm } created successfully." << endl;
            }
            else if (choice == 10)
            {
                PGM_inversion();
                cout << "The file { output.pgm } created successfully." << endl;
            }
            else if (choice == 11)
            {
                country_to_country_total();
            }
            else if (choice == 12)
            {
                month_wise_average();
            }
            else if (choice == 13)
            {
                origin_tariff_count();
            }
            else if (choice == 14)
            {
                read_countries_csv();
            }
            else if (choice == 15)
            {
                displayAboveAverage();
            }
            else if (choice == 16)
            {
                displayNumbersInWords();
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << endl << "Invalid Choice!" << endl;
                break;
            }
        }

        return 0;
}