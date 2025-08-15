#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int item, int n)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == item)
        return mid;
    else if (item < arr[mid])
        return binarySearch(arr, low, mid - 1, item, n);
    else
        return binarySearch(arr, mid + 1, high, item, n);
}
int main()
{
    int n, arr[100], item;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements(sorted): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter item: ";
    cin >> item;
    int r = binarySearch(arr, 0, n - 1, item, n);
    if (r == -1)
        cout << "Item not found" << endl;
    else
        cout << "Item found in position: " << r + 1 << endl;
}