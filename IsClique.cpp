// This file implements the ISCLIQUE Algorithm from the research paper referred, to check if a given set of vertices forms a clique. 
# include "Graph.cpp"
# include <vector>
using namespace std;

// This function returns true if all the vertices inside vector t (the clique which we are considering right now) are connected with each other : 
bool ISCLIQUE(const Graph &G, const vector<int> &t) {
    int L = t.size();
    if (L <= 1) return true;   // Graphs with 0 or 1 vertex always form a clique

    for (int i = 0; i < L; i++) {
        int count = 0;
        for (int j = 0; j < L; j++) {
            if (i == j) continue;
            if (G.isConnected(t[i], t[j]))
                count++;
        }

        // For a clique of size L, each vertex must connect to (L-1) others : 
        if (count != L - 1)
            return false;
    }

    return true;
}
