// This file implements the SELECT Algorithm from the research paper referred, to try all the combinations possible of size L & find a Clique.
# include <vector>
using namespace std;

// This function helps in generating the next combination of indices : 
bool next_combination(vector<int> &comb, int n) {
    int r = comb.size();

    for (int i = r - 1; i >= 0; i--) {
        if (comb[i] < n - r + i) {
            comb[i]++;
            for (int j = i + 1; j < r; j++)
                comb[j] = comb[j - 1] + 1;
            return true;
        }
    }
    return false;
}

// SELECT Function used to try all groups of size L from s[], return first clique : 
bool SELECT(const Graph &G, const vector<int> &s, int k, int L, vector<int> &iclique) {
    if (k < L) return false;

    vector<int> comb(L);
    for (int i = 0; i < L; i++)
        comb[i] = i;

    while (true) {
        vector<int> t;
        for (int idx : comb)
            t.push_back(s[idx]);

        if (ISCLIQUE(G, t)) {
            iclique = t;
            return true;
        }

        if (!next_combination(comb, k))
            break;
    }

    return false;
}
