// Build a programming module to compute the Egyption fraction for a given fractional value.
#include <bits/stdc++.h>
using namespace std;

void egyptianFraction(int nr, int dr)
{
    while (nr != 0)
    {
        int x = (dr + nr - 1) / nr;
        cout << "1/" << x << " ";
        nr = nr * x - dr;
        dr = dr * x;
    }
}

int main()
{
    int nr, dr;
    cout << "Enter numerator: ";
    cin >> nr;
    cout << "Enter denominator: ";
    cin >> dr;
    egyptianFraction(nr, dr);
}
