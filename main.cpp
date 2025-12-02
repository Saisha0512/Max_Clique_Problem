// This is the main file of my MCP Approach : 
# include "Graph.cpp"
# include "IsClique.cpp"
# include "Select.cpp"
# include "FindClique.cpp
# include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges : ";
    cin >> n >> m;

    Graph G(n); // Initialising the graph

    cout << "Enter " << m << " edges (u v) : \n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    G.buildDegree();

    auto result = FINDCLIQUE(G);

    cout << "\nMaximum Clique Size: " << result.first << "\n";
    cout << "Clique Vertices : ";
    for (int v : result.second)
        cout << v << " ";
    cout << "\n";

    return 0;
}
