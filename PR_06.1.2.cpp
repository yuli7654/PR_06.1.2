#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funcs.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    const int Low = -17;
    const int High = 53;

    int x[n];

    Create(x, n, Low, High, 0);

    cout << "Pochatkovyi masyv:" << endl;
    Print(x, n, 0);

    cout << "Kilkist: " << Count(x, n, 0) << endl;
    cout << "Suma: " << Sum(x, n, 0) << endl;

    ZeroMatching(x, n, 0);

    cout << "Modyfikovanyi masyv:" << endl;
    Print(x, n, 0);

    return 0;
}