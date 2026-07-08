#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    const int RECORD_SIZE = 36;

    char record[RECORD_SIZE + 1];
    record[RECORD_SIZE] = '\0';

    ifstream fin("pakcities.txt", ios::binary);
    if (!fin)
    {
        cout << "File open error" << endl;
        return 0;
    }

    fin.seekg(0, ios::end);
    int fileSize = fin.tellg();
    int recordCount = fileSize / RECORD_SIZE;

    cout << "File size (bytes): " << fileSize << endl;
    cout << "Number of records: " << recordCount << endl;

    if (recordCount < 3)
    {
        cout << "Insufficient data" << endl;
        return 0;
    }

    cout << endl
         << "Last three records:" << endl;

    for (int i = recordCount - 3; i < recordCount; i++)
    {
        fin.seekg(i * RECORD_SIZE, ios::beg);
        fin.read(record, RECORD_SIZE);
        cout << record << endl;
    }

    fin.close();

    fstream file("pakcities.txt", ios::in | ios::out | ios::binary);

    char previous[RECORD_SIZE];
    char current[RECORD_SIZE];
    streampos prevPos;

    file.read(current, RECORD_SIZE);

    while (!file.eof())
    {
        prevPos = file.tellg() - (streamoff)RECORD_SIZE;

        for (int i = 0; i < RECORD_SIZE; i++)
        {
            previous[i] = current[i];
        }

        file.read(current, RECORD_SIZE);

        bool found = true;
        char target[] = "mingora";

        for (int i = 0; i < 7; i++)
        {
            if (current[i] != target[i])
            {
                found = false;
            }
        }

        if (found)
        {
            cout << endl << "Record before mingora:" << endl;
            cout.write(previous, RECORD_SIZE);
            cout << endl;

            file.seekp(prevPos, ios::beg);
            file << left << setw(20) << "jalal abad" << fixed << setprecision(6) << setw(8) << 73.0143306 << " " << setw(8) << 34.501341 << endl;

            cout << "Record updated successfully" << endl;
            break;
        }
    }

    file.close();
    return 0;
}
