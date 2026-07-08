#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const unsigned short int maxpower = 21;
// too store polynomails where degree <= 20
struct Polynomial
{
    int degree;
    unsigned int coefficients[maxpower];
};

Polynomial createPolynomial(int degree)
{
    Polynomial r;
your code here
    return r;
}

void printPolynomial(const Polynomial &p)
{
your code here
    return;
}

Polynomial inputPolynomial(int degree)
{
    Polynomial t;
your code here
    return t;
}

void updatePolynomial(Polynomial &p)
{
your code here
    return t;
}

Polynomial addPolynomials(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial t;
your code here
    return t;
}

unsigned int value(const Polynomial &m, int varValue)
{
    unsigned int v;
your code here
    return v;
}

int main()
{
    cout << "Enter 3 coefficients for Polynomial of degree 2" << endl;
    Polynomial m1 = inputPolynomial(2);
    cout << "Your Polynomial is:" << endl;
    printPolynomial(m1);
    
    cout << "Again enter 3 coefficients for same Polynomial of degree 2" << endl;
    updatePolynomial(m1);
    cout << "Your Polynomial is:" << endl;
    printPolynomial(m1);

    int v = value(m1, 2);
    cout << "The polynomial for x = 2 is evaluated as:" << endl;
    cout << v << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter 4 coefficients for a degree 3 polynomial" << endl;
    Polynomial a = inputPolynomial(3);
    cout << "Your Polynomial is:" << endl;
    printPolynomial(a);
    
    cout << "Now enter 3 coefficients for another degree 2 polynomial" << endl;
    Polynomial b = inputPolynomial(2);
    cout << "Your Polynomial is:" << endl;
    printPolynomial(b);
    
    Polynomial c;  // after this line total garbage
    c = addPolynomials(a, b);
    cout << "Sum of above two polynomials is" << endl;
    printPolynomial(c);

	return 0;
}
