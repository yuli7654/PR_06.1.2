#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// від'ємні елементи, крім кратних 3
inline bool Match(const int v)
{
    return v < 0 && v % 3 != 0;
}

// Формування масиву випадковими числами
inline void Create(int* x, const int size,
    const int Low, const int High, int i)
{
    if (i >= size)
        return;

    x[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(x, size, Low, High, i + 1);
}

// Виведення масиву в рядок
inline void Print(int* x, const int size, int i)
{
    if (i >= size)
        return;

    cout << setw(4) << x[i];

    if (i < size - 1)
        Print(x, size, i + 1);
    else
        cout << endl;
}

// Підрахунок кількості потрібних елементів
inline int Count(int* x, const int size, int i)
{
    if (i >= size)
        return 0;

    if (Match(x[i]))
        return 1 + Count(x, size, i + 1);

    return Count(x, size, i + 1);
}

// Обчислення суми потрібних елементів
inline int Sum(int* x, const int size, int i)
{
    if (i >= size)
        return 0;

    if (Match(x[i]))
        return x[i] + Sum(x, size, i + 1);

    return Sum(x, size, i + 1);
}

// Заміна потрібних елементів нулями
inline void ZeroMatching(int* x, const int size, int i)
{
    if (i >= size)
        return;

    if (Match(x[i]))
        x[i] = 0;

    ZeroMatching(x, size, i + 1);
}