#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {

    int E = edges.size();
    vector<vector<pair<int,int>>> myAdj(V);

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        myAdj[u].push_back({w, v});
        myAdj[v].push_back({w, u});
    }

    vector<bool> visitedArr(V, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > myQueue;

    myQueue.push({0, 0});

    int minCost = 0;

    while (!myQueue.empty()) {

        int wi = myQueue.top().first;
        int ui = myQueue.top().second;
        myQueue.pop();

        if (visitedArr[ui]) continue;

        visitedArr[ui] = true;
        minCost += wi;

        for (auto &pr : myAdj[ui]) {
            int currW = pr.first;
            int vi = pr.second;

            if (!visitedArr[vi]) {
                myQueue.push({currW, vi});
            }
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
