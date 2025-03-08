 
 /***** Bismillahir Rahmanir Rahim *****/
 
#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using oset = tree<T , null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define minusone cout << "-1" << '\n'
#define int long long
long long t = 1;
const int max_n= 1e5;
const int Log = 16;
vector<vector<int>>children(max_n);
vector<vector<int>>up(max_n, vector<int>(Log));
vector<int>depth(max_n);
void dfs(int a){
    for(auto b:children[a]){
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is parent of b
        for(int j = 1; j < Log; j++){
            up[b][j] = up[up[b][j-1]][j-1];
        }
        dfs(b);
    }
}

int get_lca(int a , int b){
    if(depth[a] < depth[b]) swap(a  ,b);
   
    //get same depth
    int k = depth[a] - depth[b];
   
    for(int j = Log - 1; j >= 0 ; j--){
        if(k & ( 1<< j)){
            a = up[a][j];//parent of a
        }
    }
    // if b was ancestor of a then now a == b
    if(a == b){
        return a;
    }
    // move both a and b with powers of two

    for(int j = Log - 1; j >= 0 ;j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
void solve(){
    int n ;
    cin >> n;
    for(int v = 0 ; v < n ;v++){
        // read children of v
        int x;
        cin >> x;
        for(int i = 0; i < x; i++){
            int a;
            cin >> a;
            children[v].push_back(a);
        }
    }
    dfs(0);
    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int a , b;
        cin >> a >> b;
        cout << get_lca(a , b) << sad;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}