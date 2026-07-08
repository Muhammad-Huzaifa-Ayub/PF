//    g++ assignment3task1.cpp -o assignment3task1.exe
//    assignment3task1.exe


#include <iostream>
#include<string>

using namespace std;

const int sentinal = -1;

// Initialize array to empty
void makeArrayEmpty(int ar[], int as) {
    for (int i = 0; i < as; i++)
        ar[i] = sentinal;
}

// Display array
void showArray(int ar[], int as) {
    for (int i = 0; i < as; i++) {
        if (ar[i] != sentinal)
            cout << ar[i] << " ";
    }
    cout << endl;
}

// Add value while keeping array sorted
void addData(int data, int ar[], int as) {
    int i = 0;
    // Find correct position
    while (i < as && ar[i] != sentinal && ar[i] < data)
        i++;

    // Shift elements to the right
    int j = 0;
    while (j < as && ar[j] != sentinal) j++; // find current size
    for (int k = j; k > i; k--)
        ar[k] = ar[k-1];

    // Insert new element
    ar[i] = data;
}

// Remove all occurrences of a value
void removeData(int data, int ar[], int as) {
    int i = 0;
    while (i < as && ar[i] != sentinal) {
        if (ar[i] == data) {
            int j = i;
            while (j < as-1 && ar[j+1] != sentinal) {
                ar[j] = ar[j+1];
                j++;
            }
            ar[j] = sentinal; // mark end
        } else {
            i++;
        }
    }
}

// Update all occurrences of oldData with newData
void updateData(int oldData, int newData, int ar[], int as) {
    int i = 0;
    while (i < as && ar[i] != sentinal) {
        if (ar[i] == oldData) {
            removeData(oldData, ar, as);
            addData(newData, ar, as);
            i = 0; // restart since array changed
        } else {
            i++;
        }
    }
}

int main() {
    const int as = 1000;
    int a[as];
    makeArrayEmpty(a, as);

    cout << "Array before adding: ";
    showArray(a, as);

    addData(63, a, as);
    addData(19, a, as);
    addData(47, a, as);
    cout << "Array after adding 63, 19, 47: ";
    showArray(a, as);

    updateData(19, 80, a, as);
    cout << "Array after updating 19 -> 80: ";
    showArray(a, as);

    addData(47, a, as);
    addData(59, a, as);
    addData(22, a, as);
    cout << "Array after adding 47, 59, 22: ";
    showArray(a, as);

    removeData(47, a, as);
    cout << "Array after removing 47: ";
    showArray(a, as);

    return 0;
}
