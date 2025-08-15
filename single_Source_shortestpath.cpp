// Create a directed and weighted graph with five or more nodes.
// Now implement the single source shortest path algorithm to compute the shortest path for a source node s.
#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[], bool visited[], int V)
{
    int minVal = 999999, minIndex = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] <= minVal)
        {
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[100][100], int V, int src)
{
    int dist[100];
    bool visited[100];

    // Initialize distance and visited arrays
    for (int i = 0; i < V; i++)
    {
        dist[i] = 999999;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main()
{
    int V, graph[100][100], src;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
