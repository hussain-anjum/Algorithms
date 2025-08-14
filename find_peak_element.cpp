// Develop a program using divide and conquar method to find any peak in an array.
#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeak(arr, low, mid - 1, n);
    else
        return findPeak(arr, mid + 1, high, n);
}

int main()
{
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    int arr[100];
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int peakIndex = findPeak(arr, 0, n - 1, n);
    cout << "Peak element: " << arr[peakIndex] << endl;
}
