#include <iostream>

using namespace std;

const int INF = 1000000; 
const int MAX_VERTICES = 100;

int adj[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
bool visited[MAX_VERTICES];

void dijkstra(int source, int vertices)
{
   
    for (int i = 0; i < vertices; ++i)
	{
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < vertices - 1; ++count)
	{
        int minDist = INF, u = -1;

        for (int v = 0; v < vertices; ++v)
		{
            if (!visited[v] && dist[v] <= minDist)
			{
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < vertices; ++i)
	{
        if (dist[i] == INF)
            cout << "Distance from " << source << " to " << i << " is: INF\n";
        else
            cout << "Distance from " << source << " to " << i << " is: " << dist[i] << '\n';
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    for (int i = 0; i < vertices; ++i)
	{
        for (int j = 0; j < vertices; ++j)
		{
            adj[i][j] = 0;
        }
    }

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u][v] = weight;
        adj[v][u] = weight; 
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(source, vertices);

    return 0;
}



