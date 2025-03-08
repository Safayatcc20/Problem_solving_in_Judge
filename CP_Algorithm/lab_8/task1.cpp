
#include <bits/stdc++.h>
using namespace std;
#define sad '\n'
#define all(b) b.begin(), b.end()
#define ha cout << "YES" << '\n'
#define na cout << "NO" << '\n'
long long t = 1;

long long vis[100000];
void dfs(int source , vector<vector<int>>&g){
    vis[source] = 1;
    for(auto &x:g[source]){
        if(!vis[x]){
            dfs(x , g);
        }
    }
}

void solve(){
    long long n , k;
    cin >> n >> k;
    vector<vector<int>>graph(n);
    while(k--){
        int u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int connected_component = 0 ;
    for(long long i =  0; i < n ; i++){
        if(!vis[i]){
            dfs(i , graph);
            connected_component++;
        }
    }
    cout << connected_component << endl;
}
int main()
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