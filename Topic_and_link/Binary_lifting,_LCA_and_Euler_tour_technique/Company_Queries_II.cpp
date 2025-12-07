
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
long long t = 1;
const int max_n= 1e5;
class TreeAncestor
{
    int log;
    vector<int> depth; // for handling the not exist of kth ancestor
    vector<vector<int>> up;
    const int Log = 20;
    vector<vector<int>>children;
public:
    
    TreeAncestor(int n, vector<int> &parent)
    {
        log = 0;
        while ((1 << log) <= n)
        { // if give wrong answer then chcek to (1<<(log+1))
            log++;
        }
        up = vector<vector<int>>(n+1, vector<int>(Log, -1));
        children = vector<vector<int>>(n+1);
        depth = vector<int>(n + 1);
        for(int i = 2; i <= n;i++){
            children[parent[i]].push_back(i);
        }
        dfs(1);
        // up[0] = parent;
        // for (int i = 1; i < Log; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         if (up[i - 1][j] == -1)
        //             up[i][j] = -1;
        //         else
        //             up[i][j] = up[i - 1][up[i - 1][j]];
        //     }
        // }
    }

    void dfs(int a)
    {
        for (auto b : children[a])
        {
            depth[b] = depth[a] + 1;
            up[b][0] = a; // a is parent of b
            for (int j = 1; j < Log; j++)
            {
                if(up[b][j-1] != -1) up[b][j] = up[up[b][j - 1]][j - 1];
            }
            dfs(b);
        }
    }
    int getKthAncestor(int node, int k)
    {

        for (int j = 0; j < Log; j++)
        {
            if (node == -1)
            {
                return -1;
            }
            if (k & (1 << j))
            {
                node = up[j][node];
            }
        }
        return node;
    }

    int get_lca(int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        // get same depth
        int k = depth[a] - depth[b];

        for (int j = Log - 1; j >= 0; j--)
        {
            if (k & (1 << j))
            {
                a = up[a][j]; // parent of a
            }
        }
        // if b was ancestor of a then now a == b
        if (a == b)
        {
            return a;
        }
        // move both a and b with powers of two

        for (int j = Log - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1, -1);
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        
    }
    TreeAncestor obj(n , parent);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        //cout << obj.getKthAncestor(a, b) << sad;
        cout << obj.get_lca(a, b) << sad;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}