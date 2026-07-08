//    g++ assignment3task3.cpp -o assignment3task3.exe
//    assignment3task3.exe


#include <iostream>
#include<string>

using namespace std;

// Show array using current data size
void showArray(int ar[], int ds) {
    for (int i = 0; i < ds; i++)
        cout << ar[i] << " ";
    cout << endl;
}

// Add value while maintaining sorted order
void addData(int data, int ar[], int &ds, const int as) {
    if (ds >= as) {
        cout << "Array is full. Cannot add " << data << endl;
        return;
    }

    // Find position to insert
    int i = 0;
    while (i < ds && ar[i] < data) i++;

    // Shift elements to the right
    for (int j = ds; j > i; j--)
        ar[j] = ar[j-1];

    // Insert new data
    ar[i] = data;
    ds++; // increase data size
}

// Remove all occurrences of value
void removeData(int data, int ar[], int &ds) {
    int i = 0;
    while (i < ds) {
        if (ar[i] == data) {
            // Shift left
            for (int j = i; j < ds - 1; j++)
                ar[j] = ar[j+1];
            ds--; // decrease data size
        } else {
            i++;
        }
    }
}

// Update all occurrences of oldData to newData
void updateData(int oldData, int newData, int ar[], int &ds) {
    removeData(oldData, ar, ds);
    addData(newData, ar, ds, ds+1000); // ensure array has space
}

int main() {
    const int as = 1000;
    int a[as];
    int ds = 0; // data size starts empty

    cout << "Array before adding: ";
    showArray(a, ds);

    addData(63, a, ds, as);
    addData(19, a, ds, as);
    addData(47, a, ds, as);
    cout << "Array after adding 63, 19, 47: ";
    showArray(a, ds);

    updateData(19, 80, a, ds);
    cout << "Array after updating 19 -> 80: ";
    showArray(a, ds);

    addData(47, a, ds, as);
    addData(59, a, ds, as);
    addData(22, a, ds, as);
    cout << "Array after adding 47, 59, 22: ";
    showArray(a, ds);

    removeData(47, a, ds);
    cout << "Array after removing 47: ";
    showArray(a, ds);

    return 0;
}
