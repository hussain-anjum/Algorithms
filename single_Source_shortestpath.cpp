// Create a directed and weighted graph with five or more nodes.
// Now implement the single source shortest path algorithm to compute the shortest path for a source node s.
#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int main()
{
    cout << "Enter Number of vertex, edge and source: ";
    int n, m;
    cin >> n >> m;
    int source;
    cin >> source;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cout << "Enter " << m << " edge with corresponding weights: " << endl;
    while (m--)
    {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
    }
    vector<int> dist(n + 1, inf);
    vector<bool> visited(n + 1, false);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (!visited[node])
            for (auto &it : graph[node])
            {
                int cost = it.second;
                if (d + cost < dist[it.first])
                {
                    pq.push({d + cost, it.first});
                    dist[it.first] = d + cost;
                }
            }
        visited[node] = true;
    }
    cout << "Shortest path:" << endl;
    for (int i = 1; i <= n; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;
    return 0;
}
