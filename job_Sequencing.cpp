// Build a programming module develop the job sequencing algorithm.
#include <bits/stdc++.h>
using namespace std;

void jobSequencing(char id[], int deadline[], int profit[], int n)
{
    // Sort jobs by profit in descending order (bubble sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profit[j] < profit[j + 1])
            {
                // swap profit
                int tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;
                // swap deadline
                int tempD = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempD;
                // swap id
                char tempID = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempID;
            }
        }
    }

    char result[100];
    bool slot[100] = {false};
    int totalProfit = 0;

    // Initialize result array
    for (int i = 0; i < n; i++)
        result[i] = '-';

    // Assign jobs to slots
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, deadline[i]) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                result[j] = id[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++)
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
