#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cap, p[100], w[100], totalp = 0, i;
    double ratio[100];
    cout << "Enter n: ";
    cin >> n;
    cout << "\nEnter capacity: ";
    cin >> cap;

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "]: ";
        cin >> p[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "w[" << i << "]: ";
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        ratio[i] = p[i] / w[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(p[i], p[j]);
                swap(w[i], w[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cap < w[i])
            break;
        else
        {
            totalp += p[i];
            cap -= w[i];
        }
    }
    if (i < n)
        totalp += ratio[i] * cap;

    cout << "Max profit: " << totalp << endl;
}