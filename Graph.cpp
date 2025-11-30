// This files defines the Graph Class used by all the functions implemented in my MCP Approach.
# include <iostream>
# include <vector>
using namespace std;

class Graph {
public:
    int n; // No of vertices of the graph
    vector<vector<int>> adj; // Adjacency Matrix of the graph
    vector<int> degree; // Vector to store the degree of each vertex

    // Constructor: Create a graph with n vertices
    Graph(int n) {
        this->n = n;
        // Dynamically allocating the adjacency matrix : 
        adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        // Initializing the degree of all the vertices as 0 : 
        degree = vector<int>(n + 1, 0);
    }

    // Function to add an edge from u to v : 
    void addEdge(int u, int v) {
        if (u < 1 || u > n || v < 1 || v > n) return;

        // Adding edge only if it does not already exist : 
        if (adj[u][v] == 0) {
            // Undirected Graph 
            adj[u][v] = 1;
            adj[v][u] = 1;

            // Increasing degree count : 
            degree[u]++;
            degree[v]++;
        }
    }

    // Function to recalculate degrees : 
    void buildDegree() {
        for (int i = 1; i <= n; i++) {
            int degCount = 0;
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] == 1)
                    degCount++;
            }
            degree[i] = degCount;
        }
    }

    // Function to check if there is an edge present between two vertices : 
    bool isConnected(int u, int v) const {
        return adj[u][v] == 1;
    }
};
