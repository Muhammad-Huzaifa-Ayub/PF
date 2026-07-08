#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const unsigned short int maxpower = 21;

struct Polynomial
{
    int degree;
    unsigned int coefficients[maxpower];
};


Polynomial createPolynomial(int degree)
{
    Polynomial r;
    r.degree = degree;

    for (int i = 0; i <= degree; i++)
        r.coefficients[i] = 0;

    return r;
}


void printPolynomial(const Polynomial &p)
{
    for (int i = p.degree; i >= 0; i--)
    {
        if (p.coefficients[i] != 0)
        {
            if (i != p.degree)
                cout << " + ";

            cout << p.coefficients[i];
            if (i > 0)
                cout << "x^" << i;
        }
    }
    cout << endl;
}


Polynomial inputPolynomial(int degree)
{
    Polynomial t = createPolynomial(degree);

    for (int i = degree; i >= 0; i--)
    {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> t.coefficients[i];
    }

    return t;
}


void updatePolynomial(Polynomial &p)
{
    for (int i = p.degree; i >= 0; i--)
    {
        cout << "Enter new coefficient for x^" << i << ": ";
        cin >> p.coefficients[i];
    }
}


Polynomial addPolynomials(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial t;
    t.degree = max(p1.degree, p2.degree);

    for (int i = 0; i <= t.degree; i++)
    {
        unsigned int c1 = (i <= p1.degree) ? p1.coefficients[i] : 0;
        unsigned int c2 = (i <= p2.degree) ? p2.coefficients[i] : 0;
        t.coefficients[i] = c1 + c2;
    }

    return t;
}


unsigned int value(const Polynomial &m, int varValue)
{
    unsigned int v = 0;
    unsigned int power = 1;

    for (int i = 0; i <= m.degree; i++)
    {
        v += m.coefficients[i] * power;
        power *= varValue;
    }

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
    
    Polynomial c;
    c = addPolynomials(a, b);
    cout << "Sum of above two polynomials is" << endl;
    printPolynomial(c);

    return 0;
}
