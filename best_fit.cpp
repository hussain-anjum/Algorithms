// Implement a program to assign new threads in the free holes of the memory using the best bit algorithm.
#include <bits/stdc++.h>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[100];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int m, n;
    int blockSize[100], processSize[100];

    cout << "Enter number of blocks: ";
    cin >> m;
    cout << "Enter block sizes: ";
    for (int i = 0; i < m; i++)
        cin >> blockSize[i];

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter process sizes: ";
    for (int i = 0; i < n; i++)
        cin >> processSize[i];

    bestFit(blockSize, m, processSize, n);
    return 0;
}
