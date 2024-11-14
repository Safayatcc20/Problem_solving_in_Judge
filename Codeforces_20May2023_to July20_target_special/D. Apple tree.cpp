#include <bits/stdc++.h>
using namespace std;

long long leap[200005];
vector<int> g[200005];

void dfs(int source, int parent) {
    if (g[source].size() == 1 && g[source][0] == parent) {
        leap[source]++;
        //cout << leap[source] <<  " "<< source << " p " << parent << endl;
        return;
    }
    for (auto& x : g[source]) {
        if (x != parent) {
            dfs(x, source);
            //cout << leap[source] <<  " "<< source << " "<< x  << " " << parent << endl;
            leap[source] += leap[x];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            leap[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int q;
        dfs(1, 0);
        for(int i = 1 ; i <= n ; i++){
            //cout << leap[i] <<endl;
        }
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            long long uc = leap[u];
            //leap[u] = 0;
           // dfs(v, 0);
            long long vc = leap[v];
            //leap[v] = 0;
            cout << uc * vc << "\n";
        }
    }
    return 0;
}
