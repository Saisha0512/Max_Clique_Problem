// This file implements the FINDCLIQUE Algorithm from the research paper referred using Binary Search & SELECT Algorithm.
# include <vector>
# include <algorithm>
using namespace std;

// Purpose of this function is find the maximum clique possible in the graph : 
pair<int, vector<int>> FINDCLIQUE(const Graph &G) {
    int maxDegree = 0;

    // Getting the maximum degree :
    for (int i = 1; i <= G.n; i++){
        maxDegree = max(maxDegree, G.degree[i]);
    }

    int low = 0, high = maxDegree;
    int bestSize = 0;
    vector<int> bestClique;

    // Implementing Binary Search on the clique size : 
    while (low <= high) {
        int mid = (low + high) / 2;
        int L = mid + 1;

        vector<int> s;
        for (int v = 1; v <= G.n; v++)
            if (G.degree[v] >= mid)
                s.push_back(v);

        if (s.size() < L) {
            high = mid - 1;
            continue;
        }

        vector<int> iclique;
        bool found = SELECT(G, s, s.size(), L, iclique);

        if (found) {
            bestSize = L;
            bestClique = iclique;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {bestSize, bestClique};
}
