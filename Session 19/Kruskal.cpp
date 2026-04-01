#include <bits/stdc++.h>
using namespace std;

class kruskal {
public:
    vector<int> parentArr, rank;

    kruskal(int n) {
        parentArr.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parentArr[i] = i;
    }

    int findParent(int node) {
        if (parentArr[node] == node)
            return node;
        return parentArr[node] = findParent(parentArr[node]);
    }

    void joinRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parentArr[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parentArr[pv] = pu;
        }
        else {
            parentArr[pv] = pu;
            rank[pu]++;
        }
    }
};

int spanningTree(int V, vector<vector<int>>& edges) {

    sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[2] < b[2];
         });

    kruskal ds(V);
    int minCost = 0;

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (ds.findParent(u) != ds.findParent(v)) {
            minCost += w;
            ds.joinRank(u, v);
        }
    }

    return minCost;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int result = spanningTree(V, edges);

    cout << "Minimum Cost of MST: " << result << endl;

    return 0;
}
