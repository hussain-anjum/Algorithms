// A set of activity are submitted to a auditorium manager praying for having allocation according to their start and end time.
// Help the manager by writing a program using the concept of greedy activity section method to slove the problem.
#include <bits/stdc++.h>
using namespace std;

void activitySelection(int start[], int finish[], int n)
{
    // Sort activities by finish time using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                swap(finish[j], finish[j + 1]);
                swap(start[j], start[j + 1]);
            }
        }
    }

    cout << "Selected activities (start, finish):\n";
    int lastFinish = finish[0];
    cout << "(" << start[0] << ", " << finish[0] << ")\n";

    for (int i = 1; i < n; i++)
    {
        if (start[i] >= lastFinish)
        {
            cout << "(" << start[i] << ", " << finish[i] << ")\n";
            lastFinish = finish[i];
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[100], finish[100];
    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> finish[i];
    }

    activitySelection(start, finish, n);

    return 0;
}