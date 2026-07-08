#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const unsigned short int totalelements = 400;
// too store matrices where rows * col <= 400
struct Matrix
{
    int rows, columns;
    unsigned int elements[totalelements];
};

Matrix createMatrix(int rowcount, int colcount)
{
    Matrix r;
    r.rows = rowcount;
    r.columns = colcount;
    return r;
}

Matrix createNullMatrix(int rowcount, int colcount)
{
    Matrix t;
    t.rows = rowcount;
    t.columns = colcount;
    for(int r = 0; r < t.rows; r+=1)
    {
        for(int c = 0; c < t.columns; c+=1)
        {
            int i = r * t.columns + c;
            t.elements[i] = 0;
        }
    }
    return t;
}

Matrix createIdentityMatrix(int rowcount)
{
    Matrix t = createNullMatrix(rowcount, rowcount);
    for(int rc = 0; rc < t.rows; rc+=1)
    {
        int i = rc * t.columns + rc;
        t.elements[i] = 1;
    }
    return t;
}

void printMatrix(const Matrix &m)
{
    for(int r = 0; r < m.rows; r+=1)
    {
        for(int c = 0; c < m.columns; c+=1)
        {
            int i = r * m.columns + c;
            cout << m.elements[i] << " ";
        }
        cout << endl;
    }        
}

Matrix inputMatrix(int rowcount, int colcount)
{
    Matrix t;
    t.rows = rowcount;
    t.columns = colcount;
    for(int r = 0; r < t.rows; r+=1)
    {
        for(int c = 0; c < t.columns; c+=1)
        {
            int i = r * t.columns + c;
            cin >> t.elements[i];
        }
    }
    return t;
}

void updateMatrix(Matrix &p)
{
    for(int r = 0; r < p.rows; r+=1)
    {
        for(int c = 0; c < p.columns; c+=1)
        {
            int i = r * p.columns + c;
            cin >> p.elements[i];
        }
    }
    return;
}

Matrix transposeMatrix(const Matrix &p)
{
    Matrix t;
    t.rows = p.columns;
    t.columns = p.rows;
    for(int r = 0; r < t.rows; r+=1)
    {
        for(int c = 0; c < t.columns; c+=1)
        {
            int i = r * t.columns + c;
            int j = c * p.columns + r;
            t.elements[i] = p.elements[j];
        }
    }
    return t;
}

Matrix addMatrices(const Matrix &p1, const Matrix &p2)
{
    if (!(p1.rows == p2.rows && p1.columns == p2.columns))
    {
        cout << "Matices are not compatible for addition" << endl;
        throw 0; // bad practice to throw 0, it should be something valid 
    }
    Matrix t;
    t.rows = p1.rows;
    t.columns = p1.columns;
    for(int r = 0; r < t.rows; r+=1)
    {
        for(int c = 0; c < t.columns; c+=1)
        {
            int i = r * t.columns + c;
            t.elements[i] = p1.elements[i] + p2.elements[i];
        }
    }
    return t;
}

unsigned int & element(Matrix &m, int row, int column)
{
    return m.elements[row * m.columns + column];
}

int main()
{
    cout << "Enter 15 values for 3 X 5 matrix" << endl;
    Matrix m1 = inputMatrix(3,5);
    cout << "Your 3 X 5 matrix is:" << endl;
    printMatrix(m1);
    
    cout << "Again enter 15 values for same 3 X 5 matrix" << endl;
    updateMatrix(m1);
    cout << "Your 3 X 5 matrix is:" << endl;
    printMatrix(m1);

    Matrix m2 = transposeMatrix(m1);
    cout << "The transpose of your 3 X 5 matrix as 5 X 3 matrix is:" << endl;
    printMatrix(m2);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Creating an identity matrix:" << endl;
    Matrix i1 = createIdentityMatrix(17);
    cout << "Identity matrix of size 17 is:" << endl;
    printMatrix(i1);
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter 6 values for 3 X 2 matrix" << endl;
    Matrix a = inputMatrix(3,2);
    cout << "Your 3 X 2 matrix is:" << endl;
    printMatrix(a);
    
    cout << "Again enter 6 values for another 3 X 2 matrix" << endl;
    Matrix b = inputMatrix(3,2);
    cout << "Your 3 X 2 matrix is:" << endl;
    printMatrix(b);
    
    Matrix c;  // after this line total garbage
    c = addMatrices(a, b);
    cout << "Sum of above two matrices is" << endl;
    printMatrix(c);

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Think deeply on values stored in following 16 X 9 matrix" << endl;
    Matrix uniq = createMatrix(16,9);
    for(int rr = 0; rr < uniq.rows; rr+=1)
    {
        for(int cc = 0; cc < uniq.columns; cc+=1)
        {
            element(uniq, rr, cc) = rr+cc+1;
        }
    }
    printMatrix(uniq);
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Once again" << endl;
    for(int rr = 0; rr < uniq.rows; rr+=1)
    {
        for(int cc = 0; cc < uniq.columns; cc+=1)
        {
            cout << setw(2) << element(uniq, rr, cc) << " ";
        }
        cout << endl;
    }

	return 0;
}
