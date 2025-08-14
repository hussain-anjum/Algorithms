// Write a program to develop the fractional knapsack problem.
#include <bits/stdc++.h>
using namespace std;

float fractionalKnapsack(int W, int profit[], int weight[], int n)
{
    float ratio[100];

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(profit[j], profit[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }

    float totalValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= W)
        {
            totalValue += profit[i];
            W -= weight[i];
        }
        else
        {
            totalValue += ratio[i] * W;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int profit[100], weight[100];
    cout << "Enter profit and weight for each item:\n";
    for (int i = 0; i < n; i++)
        cin >> profit[i] >> weight[i];

    float maxProfit = fractionalKnapsack(W, profit, weight, n);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
