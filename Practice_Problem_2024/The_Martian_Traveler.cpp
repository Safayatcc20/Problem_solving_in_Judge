#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, const vector<vector<int>>& g, vector<bool>& used, stack<int>& order) {
    used[u] = true;
    for (int v : g[u]) {
        if (!used[v]) dfs1(v, g, used, order);
    }
    order.push(u);
}

void dfs2(int u, const vector<vector<int>>& rg, vector<bool>& used, vector<int>& scc, int id) {
    used[u] = true;
    scc[u] = id;
    for (int v : rg[u]) {
        if (!used[v]) dfs2(v, rg, used, scc, id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> g(N + 1), rg(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        vector<bool> used(N + 1, false);
        stack<int> order;
        for (int i = 1; i <= N; i++) {
            if (!used[i]) dfs1(i, g, used, order);
        }
        fill(used.begin(), used.end(), false);
        vector<int> scc(N + 1, -1);
        int scc_cnt = 0;
        while (!order.empty()) {
            int u = order.top();
            cout << u << " ";
            order.pop();
            if (used[u]) continue;
            dfs2(u, rg, used, scc, scc_cnt);
            scc_cnt++;
        }
        vector<int> size_scc(scc_cnt, 0);
        for (int i = 1; i <= N; i++) {
            size_scc[scc[i]]++;
        }
        vector<vector<int>> dag(scc_cnt), in_dag(scc_cnt);
        set<pair<int, int>> edge_set;
        for (int u = 1; u <= N; u++) {
            int su = scc[u];
            for (int v : g[u]) {
                int sv = scc[v];
                if (su != sv && edge_set.find({su, sv}) == edge_set.end()) {
                    dag[su].push_back(sv);
                    in_dag[sv].push_back(su);
                    edge_set.insert({su, sv});
                }
            }
        }
        // Topo sort
        vector<int> topo_order;
        vector<bool> vis(scc_cnt, false);
        function<void(int)> topo_dfs = [&](int u) {
            vis[u] = true;
            for (int v : dag[u]) {
                if (!vis[v]) topo_dfs(v);
            }
            topo_order.push_back(u);
        };
        for (int i = 0; i < scc_cnt; i++) {
            if (!vis[i]) topo_dfs(i);
        }
        reverse(topo_order.begin(), topo_order.end());
        // DP
        int effective_k = min(K, scc_cnt);
        const int INF = 2e9;
        vector<vector<int>> dp(effective_k + 1, vector<int>(scc_cnt, -INF));
        int max_cities = 0;
        for (int u : topo_order) {
            dp[1][u] = size_scc[u];
            max_cities = max(max_cities, size_scc[u]);
            for (int j = 2; j <= effective_k; j++) {
                int max_prev = -INF;
                for (int pv : in_dag[u]) {
                    max_prev = max(max_prev, dp[j - 1][pv]);
                }
                if (max_prev != -INF) {
                    dp[j][u] = size_scc[u] + max_prev;
                    max_cities = max(max_cities, dp[j][u]);
                }
            }
        }
        cout << max_cities << '\n';
    }
    return 0;
}