// You are given a set of items in ascending order.
// Now implement the interpolation search to find a key item in the array.
#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int k, int n)
{
    if (k < arr[low] || k > arr[high])
        return -1;

    if (arr[low] == arr[high])
    {
        if (arr[low] == k)
            return low;
        else
            return -1;
    }

    int pos = low + ((k - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    if (arr[pos] == k)
        return pos;
    else if (k < arr[pos])
        return interpolationSearch(arr, low, pos - 1, k, n);
    else
        return interpolationSearch(arr, pos + 1, high, k, n);
}
int main()
{
    int n, arr[100], key;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements(sorted): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key item: ";
    cin >> key;
    int r = interpolationSearch(arr, 0, n - 1, key, n);
    if (r == -1)
        cout << "Item not found" << endl;
    else
        cout << "Item found in position: " << r + 1 << endl;
}