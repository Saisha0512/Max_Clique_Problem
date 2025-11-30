// This files initializes the Graph Class used by all the functions implemented in my MCP Approach.
# ifndef GRAPH_H
# define GRAPH_H

# include <vector>
using namespace std;

class Graph {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> degree;

    Graph(int n);
    void addEdge(int u, int v);
    void buildDegree();
    bool isConnected(int u, int v) const;
};

# endif