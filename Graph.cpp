// This files defines the functions for the Graph Class used by all the functions implemented in my MCP Approach.
# include "Graph.h"
# include <vector>
using namespace std;

// Constructor
Graph :: Graph(int n) {
    this->n = n;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    degree = vector<int>(n + 1, 0);
}

// Adding an edge from u to v : 
void Graph :: addEdge(int u, int v) {
    if (u < 1 || u > n || v < 1 || v > n) return;

    if (adj[u][v] == 0) {
        adj[u][v] = adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
}

// Building degrees : 
void Graph :: buildDegree() {
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++)
            if (adj[i][j]) count++;
        degree[i] = count;
    }
}

// Checking the connections : 
bool Graph :: isConnected(int u, int v) const {
    return adj[u][v] == 1;
}