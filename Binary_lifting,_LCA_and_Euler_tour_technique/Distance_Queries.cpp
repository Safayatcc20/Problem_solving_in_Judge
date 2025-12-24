/***** Bismillahir Rahmanir Rahim *****/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define int long long

const int max_n = 1e5;
class TreeAncestor {
    int log;
    vector<int> depth;
    vector<vector<int>> up;
    const int Log = 20;

public:
    TreeAncestor(int n, vector<vector<int>> &children) {
        log = 0;
        while ((1 << log) <= n) {
            log++;
        }

        up = vector<vector<int>>(n + 1, vector<int>(Log, -1));
        depth = vector<int>(n + 1);

        depth[0] = 0; // Depth of root is 0
        
        // Populate depth and up array using DFS approach
        // for (int i = 0; i < n; ++i) {
        //     if (i != 0) {
        //         depth[i] = depth[parent[i]] + 1; // Calculate depth of each node
        //     }
        //     up[i][0] = parent[i];
        //     for(int j = 1; j<= n ;j++){
        //         if(up[i-1][j] == -1) up[i][j] = -1;
        //         else up[i][j] = up[i-1][up[i-1][j]];
        //     }
        // }
        dfs(1, -1, children); // Start DFS from the root (node 1)
    }

    void dfs(int node, int parent, vector<vector<int>> &children) {
        up[node][0] = parent; // the direct parent
        for (int j = 1; j < Log; j++) {
            if (up[node][j - 1] != -1) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }

        for (int child : children[node]) {
            if (child != parent) { // avoid revisiting the parent
                depth[child] = depth[node] + 1;
                dfs(child, node, children);
            }
        }
    }
    
    int get_lca(int a, int b) {
        if (depth[a] < depth[b])
            swap(a, b);

        int k = depth[a] - depth[b];
        for (int j = Log - 1; j >= 0; j--) {
            if (k & (1 << j)) {
                a = up[a][j];
            }
        }

        if (a == b) {
            return a;
        }

        for (int j = Log - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }

    int get_distance(int a, int b) {
        int lca = get_lca(a, b);
        return depth[a] + depth[b] - 2 * depth[lca];
    }
};

void solve() {
    // Note: this problem is unweighted
    // if weighted then Wa + Wb - 2 * lca
    int n, q;
    cin >> n >> q;
    vector<vector<int>> children(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    TreeAncestor obj(n, children);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << obj.get_distance(a, b) << sad;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
