#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<pair<int, int>> adj[MAXN]; // Adjacency list to represent the tree
int values[MAXN];                   // Values of each node
long long platonic[MAXN];          // Platonic number for each node
int parent[MAXN];
int sz[MAXN];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int u, int p, int mx) {
    merge(u, p);
    platonic[u] = mx;
    for (auto& [v, val] : adj[u]) {
        if (v != p) {
            dfs(v, u, max(mx, val));
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sz[i] = 1;
            adj[i].clear();
        }

        for (int i = 1; i <= n; ++i) {
            cin >> values[i];
        }

        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, values[v]);
            adj[v].emplace_back(u, values[u]);
        }

        dfs(1, 0, values[1]);

        for (int i = 1; i <= n; ++i) {
            cout << platonic[find(i)] << " ";
        }
        cout << endl;
    }
    return 0;
}
