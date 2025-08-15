// Develop a program using divide and conquer method to find number of 1s in an array of sorted binaries.
#include <bits/stdc++.h>
using namespace std;

int countOnes(int arr[], int low, int high, int n)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;

        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            return n - mid; // all elements from mid to end are 1

        if (arr[mid] == 0)
            return countOnes(arr, mid + 1, high, n);
        else
            return countOnes(arr, low, mid - 1, n);
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter sorted binary array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = countOnes(arr, 0, n - 1, n);
    cout << "Number of 1s: " << result << endl;

    return 0;
}
