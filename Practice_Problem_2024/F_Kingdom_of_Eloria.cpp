#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
const int MAXLOG = 17;

vector<pair<int, int>> graph[MAXN]; // {neighbor, weight}
int up[MAXN][MAXLOG];              // Binary lifting table
int pathWeight[MAXN][MAXLOG];      // Weight of the edge to the k-th ancestor
int N, Q;

// Function to calculate GCD
int calculateGCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// DFS to preprocess binary lifting for the first level
void dfs(int node, int parent, int weight) {
    up[node][0] = parent;
    pathWeight[node][0] = weight;

    for (auto &[neighbor, edgeWeight] : graph[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node, edgeWeight);
    }
}

// Preprocessing function for all levels of binary lifting
void pre() {
    dfs(1, -1, 0);
    for (int k = 1; k < MAXLOG; ++k) {
        for (int i = 1; i <= N; ++i) {
            if (up[i][k - 1] != -1) {
                up[i][k] = up[up[i][k - 1]][k - 1];
                pathWeight[i][k] = calculateGCD(pathWeight[i][k - 1], pathWeight[up[i][k - 1]][k - 1]);
            } else {
                up[i][k] = -1;
                pathWeight[i][k] = 0;
            }
        }
    }
}

// Function to find the farthest valid ancestor using GCD and binary lifting
int findValidAncestor(int u, int x) {
    for (int k = MAXLOG - 1; k >= 0; --k) {
        if (up[u][k] != -1 && pathWeight[u][k] % x == 0) {
            u = up[u][k];
        }
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N;

        // Reset for each test case
        for (int i = 1; i <= N; ++i) {
            graph[i].clear();
            fill(up[i], up[i] + MAXLOG, -1);
            fill(pathWeight[i], pathWeight[i] + MAXLOG, 0);
        }

        // Input graph
        for (int i = 0; i < N - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Preprocess levels, binary lifting, and edge weights
        pre();

        // Process queries
        cin >> Q;
        cout << "Case " << t << ":\n";
        while (Q--) {
            int u, x;
            cin >> u >> x;
            cout << findValidAncestor(u, x) << "\n";
        }
    }

    return 0;
}