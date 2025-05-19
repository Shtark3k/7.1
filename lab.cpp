#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void SortCols(int** a, const int rowCount, const int colCount);
void ChangeCols(int** a, const int col1, const int col2, const int rowCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));
    const int rowCount = 9;
    const int colCount = 6;
    const int Low = 18;
    const int High = 74;

    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Z[i] = new int[colCount];

    Create(Z, rowCount, colCount, Low, High);
    cout << "Initial matrix:\n";
    Print(Z, rowCount, colCount);

    SortCols(Z, rowCount, colCount);
    cout << "Sorted matrix:\n";
    Print(Z, rowCount, colCount);

    int S = 0, k = 0;
    Calc(Z, rowCount, colCount, S, k);
    cout << "S = " << S << "\nk = " << k << endl;
    cout << "Modified matrix:\n";
    Print(Z, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Z[i];
    delete[] Z;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void ChangeCols(int** a, const int col1, const int col2, const int rowCount)
{
    for (int i = 0; i < rowCount; i++)
        swap(a[i][col1], a[i][col2]);
}

void SortCols(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
        {
            if (
                (a[0][i1] > a[0][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) ||
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1])
                )
                ChangeCols(a, i1, i1 + 1, rowCount);
        }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
        {
            if (!(a[i][j] % 2 != 0 || a[i][j] % 7 == 0)) 
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
}
