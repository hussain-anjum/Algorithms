// A set of activity are submitted to a auditorium manager praying for having allocation according to their start and end time.
// Help the manager by writing a program using the concept of greedy activity section method to slove the problem.
#include <bits/stdc++.h>
using namespace std;

// Comparator for sorting by finish time
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void activitySelection(pair<int, int> activities[], int n)
{
    sort(activities, activities + n, compare);

    cout << "Selected activities (start, finish):" << endl;
    int lastFinish = activities[0].second;
    cout << "(" << activities[0].first << ", " << activities[0].second << ")" << endl;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= lastFinish)
        {
            cout << "(" << activities[i].first << ", " << activities[i].second << ")" << endl;
            lastFinish = activities[i].second;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    pair<int, int> activities[n]; // first = start, second = finish
    cout << "Enter start and finish times:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].first >> activities[i].second;
    }

    activitySelection(activities, n);

    return 0;
}
