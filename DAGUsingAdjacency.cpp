#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;

int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
bool recursionStack[MAX_VERTICES];

void addEdge(int u, int v) {
    adj[u][v] = 1; 
}

bool isCyclicUtil(int v, int vertices)
{
  
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int i = 0; i < vertices; ++i) {
            if (adj[v][i] == 1) { 
                if (!visited[i] && isCyclicUtil(i, vertices))
                    return true;
                else if (recursionStack[i]) 
                    return true;
            }
        }
    }
    recursionStack[v] = false; 
    return false;
}

bool isDAG(int vertices) 
{

    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        recursionStack[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, vertices))
                return false; 
        }
    }
    return true; 
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

 
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            adj[i][j] = 0;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    if (isDAG(vertices))
        cout << "The graph is a Directed Acyclic Graph (DAG).\n";
    else
        cout << "The graph has cycles and is not a DAG.\n";

    return 0;
}



