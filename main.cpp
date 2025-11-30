// This is the main file of my MCP Approach : 
# include <iostream>
# include <vector>
# include "Graph.cpp"
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

pair<int, vector<int>> FINDCLIQUE(const Graph &G);

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Graph G(n);

    cout << "Enter all edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    // Compute degree of each vertex
    G.buildDegree();

    // Find maximum clique
    auto result = FINDCLIQUE(G);

    cout << "\nMaximum Clique Size: " << result.first << "\n";
    cout << "Clique Vertices: ";
    for (int v : result.second)
        cout << v << " ";
    cout << "\n";

    return 0;
}
