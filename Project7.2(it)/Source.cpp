// Lab_7_2_1.cpp
// Барчук Денис Петрович
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 2
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int SumMax(int** a, const int n, const int k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 5;
	int High = 55;
	int k;
	int n; 
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n, n);
    int Sum = SumMax(a, n, n);
    cout << "Suma maximalnih elementiv: " << Sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumMax(int** a, const int n, const int k)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int maxInRow = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] > maxInRow)
            {
                maxInRow = a[i][j];
            }
        }
        sum += maxInRow;
    }

    return sum;
}