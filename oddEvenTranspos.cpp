// Let a string S consists of only numerical digits.
// Now implement the odd-even transposition algorithm to sort the digits in the string S.
#include <bits/stdc++.h>
using namespace std;

void oddEvenSort(int arr[], int n)
{
    while (true)
    {
        int swaps = 0;

        // Odd phase
        for (int i = 1; i <= n - 2; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }

        // Even phase
        for (int i = 0; i <= n - 2; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }

        if (swaps == 0)
            break; // No swaps means sorted
    }
}

int main()
{
    char S[100];
    cout << "Enter numeric string: ";
    cin >> S;

    int n = strlen(S);
    int digits[100];
    for (int i = 0; i < n; i++)
    {
        digits[i] = S[i] - '0';
    }

    oddEvenSort(digits, n);

    cout << "Sorted digits: ";
    for (int i = 0; i < n; i++)
    {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}
