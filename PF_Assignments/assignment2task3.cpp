//     g++ assignment2task3.cpp -o assignment2task3.exe
//     assignment2task3.exe

#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

using namespace std;

void sorting_notes(array<int, 4>& notes) {
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(notes[j] > notes[i]) {
                int temp = notes[i];
                notes[i] = notes[j];
                notes[j] = temp;
            }
        }
    }
}

int calculate_min_change(array<int, 4> notes, int total_cost, int cash_paid) {
    if (total_cost < 0 || cash_paid < 0) {
        throw invalid_argument("Total cost and cash paid must be non-negative.");
    }

    int balance = cash_paid - total_cost;
    if (balance < 0) {
        throw runtime_error("Insufficient cash paid.");
    }
    if (balance == 0) {
        return 0;
    }

    sorting_notes(notes);
    cout << "Notes for change req are:" << endl;
    int amount = 0;

    for (int i = 0; i < 4; i++) {
        if (notes[i] <= 0) {
            throw invalid_argument("Currency notes must be positive values.");
        }

        if (balance >= notes[i]) {
            int count = balance / notes[i];
            balance -= count * notes[i];
            amount += count;
            cout << notes[i] << " x " << count << endl;
        }
    }

    if (balance > 0) {
        throw runtime_error("Cannot provide exact change with given notes.");
    }

    return amount;
}

int main() {
    try {
        array<int, 4> currency_notes;
        cout << "Enter 4 currency notes available for transaction :" << endl;

        for (int i = 0; i < 4; i++) {
            cin >> currency_notes[i];
            if (!cin) {
                throw invalid_argument("Invalid input for currency notes.");
            }
        }

        int total_cost;
        int cash_paid;

        cout << "Enter Total cost and Cash paid : " << endl;
        cin >> total_cost >> cash_paid;

        if (!cin) {
            throw invalid_argument("Invalid input for cost or cash.");
        }

        int result = calculate_min_change(currency_notes, total_cost, cash_paid);
        cout << "Minimum currency notes required : " << result << endl;

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
