// Build a programming module develop the job sequencing algorithm.
#include <bits/stdc++.h>
using namespace std;

void jobSequencing(char id[], int deadline[], int profit[], int n)
{
    // Sort jobs by profit in descending order (bubble sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                // swap profit
                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;
                // swap deadline
                int tempD = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = tempD;
                // swap id
                char tempID = id[i];
                id[i] = id[j];
                id[j] = tempID;
            }
        }
    }
    // max deadline
    int max = deadline[0];
    for (int i = 0; i < n; i++)
    {
        if (deadline[i] > max)
            max = deadline[i];
    }

    char result[100];
    int totalProfit = 0;

    // Initialize result array
    for (int i = 0; i < max; i++)
        result[i] = '-';

    // Assign jobs to slots
    for (int i = 0; i < n; i++)
    {
        if (result[deadline[i] - 1] == '-')
        {
            result[deadline[i] - 1] = id[i];
            totalProfit += profit[i];
        }
        else
        {
            for (int j = deadline[i] - 1; j >= 0; j--)
            {
                if (result[j] == '-')
                {
                    result[j] = id[i];
                    totalProfit += profit[i];
                }
            }
        }
    }

    cout << "Scheduled jobs: ";
    for (int i = 0; i < max; i++)
    {
        if (result[i] != '-')
            cout << result[i] << " ";
    }
    cout << "\nMaximum Profit: " << totalProfit << endl;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    char id[100];
    int deadline[100], profit[100];

    cout << "Enter job, deadline, and profit:\n";
    for (int i = 0; i < n; i++)
        cin >> id[i] >> deadline[i] >> profit[i];

    jobSequencing(id, deadline, profit, n);

    return 0;
}
